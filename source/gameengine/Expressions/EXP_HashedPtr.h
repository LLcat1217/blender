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
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 */

/** \file EXP_HashedPtr.h
 *  \ingroup expressions
 */

#ifndef __EXP_HASHEDPTR_H__
#define __EXP_HASHEDPTR_H__

#ifdef WITH_CXX_GUARDEDALLOC
#include "MEM_guardedalloc.h"
#endif

class CHashedPtr
{
	void* m_valptr;

public:
	CHashedPtr(void* val);

	unsigned int hash() const;

	inline friend bool operator ==( const CHashedPtr & rhs,const CHashedPtr & lhs)
	{
		return rhs.m_valptr == lhs.m_valptr;
	}


#ifdef WITH_CXX_GUARDEDALLOC
	MEM_CXX_CLASS_ALLOC_FUNCS("GE:CHashedPtr")
#endif
};

#endif  /* __EXP_HASHEDPTR_H__ */
