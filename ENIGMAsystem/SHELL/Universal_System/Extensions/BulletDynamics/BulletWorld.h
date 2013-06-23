/** Copyright (C) 2013 Robert B. Colton
***
*** This file is a part of the ENIGMA Development Environment.
***
*** ENIGMA is free software: you can redistribute it and/or modify it under the
*** terms of the GNU General Public License as published by the Free Software
*** Foundation, version 3 of the license or any later version.
***
*** This application and its source code is distributed AS-IS, WITHOUT ANY
*** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
*** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
*** details.
***
*** You should have received a copy of the GNU General Public License along
*** with this code. If not, see <http://www.gnu.org/licenses/>
**/

#ifdef DEBUG_MODE
  #include "libEGMstd.h"
  #include "Widget_Systems/widgets_mandatory.h"
  #define get_worldr(w,id,r) \
    if (unsigned(id) >= bulletWorlds.size() || id < 0) { \
      show_error("Cannot access Bullet Dynamics physics world with id " + toString(id), false); \
      return r; \
    } BulletWorld* w = bulletWorlds[id];
  #define get_world(w,id) \
    if (unsigned(id) >= bulletWorlds.size() || id < 0) { \
      show_error("Cannot access Bullet Dynamics physics world with id " + toString(id), false); \
      return; \
    } BulletWorld* w = bulletWorlds[id];
#else
  #define get_worldr(w,id,r) \
    BulletWorld* w = bulletWorlds[id];
  #define get_world(w,id) \
    BulletWorld* w = bulletWorlds[id];
#endif

#ifndef _BULLETWORLD__H
#define _BULLETWORLD__H

#include <vector>
using std::vector;

#undef None
#include <BulletSoftBody/btSoftBody.h>
#include <btBulletDynamicsCommon.h>
#include <BulletSoftBody/btSoftRigidDynamicsWorld.h>

struct BulletWorld {
  btDynamicsWorld* dynamicsWorld;
  btBroadphaseInterface* broadphase;
  btDefaultCollisionConfiguration* collisionConfiguration;
  btCollisionDispatcher* dispatcher;
  btSequentialImpulseConstraintSolver* solver;

  bool paused;

  BulletWorld()
  {
    // Construct a world object, which will hold and simulate the physics bodies.
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    solver = new btSequentialImpulseConstraintSolver;

    paused = false;
  }

  void createDiscrete()
  {
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
  }

  void createSoftRigid()
  {
    dynamicsWorld = new btSoftRigidDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
  }

  void createSimple()
  {
    dynamicsWorld = new btSimpleDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
  }

  ~BulletWorld() 
  {
    delete dynamicsWorld;
    delete solver;
    delete collisionConfiguration;
    delete dispatcher;
    delete broadphase;
  }

  void update(double timestep, double iterations) 
  {
    dynamicsWorld->stepSimulation(timestep, iterations);
  }
}; 
extern vector<BulletWorld*> bulletWorlds;

#endif
