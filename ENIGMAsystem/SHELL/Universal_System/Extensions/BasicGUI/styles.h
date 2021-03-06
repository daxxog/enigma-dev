/** Copyright (C) 2014 Harijs Grinbergs
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

#ifndef BGUI_STYLES_H
#define BGUI_STYLES_H
#include <array>
using std::array;

#include "common.h"

namespace gui
{
	class gui_style{
		public:
			unsigned int id;

			array<font_style,6> font_styles; //0 - default, 1 - hover, 2 - active, 3 - on, 4 - on hover, 5 - on active (this is based on enums)

      array<int,6> sprites;

			rect box;
			rect_offset border;
			rect_offset padding;

			offset image_offset;

			gui_style();
	};
}

#endif
