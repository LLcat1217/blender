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

/** \file KX_ConstraintWrapper.h
 *  \ingroup ketsji
 */

#ifndef __KX_CONSTRAINTWRAPPER_H__
#define __KX_CONSTRAINTWRAPPER_H__

#include "EXP_Value.h"

class PHY_IConstraint;

class	KX_ConstraintWrapper : public EXP_Value
{
	Py_Header
public:
	KX_ConstraintWrapper(PHY_IConstraint *constraint);
	virtual ~KX_ConstraintWrapper ();

	virtual std::string GetName();
	
#ifdef WITH_PYTHON
	EXP_PYMETHOD_NOARGS(KX_ConstraintWrapper,GetConstraintId);
	EXP_PYMETHOD(KX_ConstraintWrapper,SetParam);
	EXP_PYMETHOD(KX_ConstraintWrapper,GetParam);

	static PyObject *pyattr_get_constraintId(EXP_PyObjectPlus *self_v, const EXP_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_constraintType(EXP_PyObjectPlus *self_v, const EXP_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_breakingThreshold(EXP_PyObjectPlus *self_v, const EXP_PYATTRIBUTE_DEF *attrdef);
	static int pyattr_set_breakingThreshold(EXP_PyObjectPlus *self_v, const EXP_PYATTRIBUTE_DEF *attrdef, PyObject *value);
	static PyObject *pyattr_get_enabled(EXP_PyObjectPlus *self_v, const EXP_PYATTRIBUTE_DEF *attrdef);
	static int pyattr_set_enabled(EXP_PyObjectPlus *self_v, const EXP_PYATTRIBUTE_DEF *attrdef, PyObject *value);
#endif

private:
	PHY_IConstraint *m_constraint;
};

#endif  /* __KX_CONSTRAINTWRAPPER_H__ */
