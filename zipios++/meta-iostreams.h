#pragma once
/*
  Zipios++ - a small C++ library that provides easy access to .zip files.
  Copyright (C) 2000-2015  Thomas Sondergaard

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

/** \file
 * Includes the different iostream libraries
 */

#include "zipios++/zipios-config.h"

#include <iostream>
#include <fstream>
#include <sstream>


namespace zipios
{


/** \brief An output stream using strings.
 *
 * This object is used whenever we want to output a buffer from
 * a string and convert that to a string.
 */
typedef std::ostringstream OutputStringStream;


} // zipios namespace
// vim: ts=2 sw=2 et
