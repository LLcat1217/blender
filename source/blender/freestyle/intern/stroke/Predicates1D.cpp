/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/** \file blender/freestyle/intern/stroke/Predicates1D.cpp
 *  \ingroup freestyle
 */

#include "Predicates1D.h"

#include "../python/Director.h"

namespace Freestyle {

int UnaryPredicate1D::operator()(Interface1D& inter)
{
	return Director_BPy_UnaryPredicate1D___call__(this, inter);
}

int BinaryPredicate1D::operator()(Interface1D& inter1, Interface1D& inter2)
{
	return Director_BPy_BinaryPredicate1D___call__(this, inter1, inter2);
}

} /* namespace Freestyle */
