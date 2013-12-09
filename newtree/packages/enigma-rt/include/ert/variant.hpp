/******************************************************************************

 ENIGMA
 Copyright (C) 2008-2013 Enigma Strike Force

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

******************************************************************************/

#ifndef ERT_VARIANT_HPP_
#define ERT_VARIANT_HPP_

#include "ert/real.hpp"
#include "ert/string.hpp"

namespace ert {
  struct variant {
    variant() = default;
    variant(real_t);
    variant(string_t);
    variant(variant const &) = default;
    variant(variant &&);

    variant& operator=(variant const &) = default;
    variant& operator=(variant &&);
    
    bool operator<(variant const &) const;
    bool operator<=(variant const &) const;
    bool operator>(variant const &) const;
    bool operator>=(variant const &) const;

    operator real_t() const;
    operator string_t() const;
    operator bool() const;
    
    enum type_t {
      vt_uninit = 0,
      vt_real,
      vt_string
    } type = vt_uninit;
    
    real_t real;
    string_t string;
  };
  
  typedef variant variant_t;
}

#endif // ERT_VARIANT_HPP_