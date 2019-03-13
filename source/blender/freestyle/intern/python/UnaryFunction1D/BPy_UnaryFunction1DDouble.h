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

/** \file source/blender/freestyle/intern/python/UnaryFunction1D/BPy_UnaryFunction1DDouble.h
 *  \ingroup freestyle
 */

#ifndef __FREESTYLE_PYTHON_UNARYFUNCTION1DDOUBLE_H__
#define __FREESTYLE_PYTHON_UNARYFUNCTION1DDOUBLE_H__

#include "../BPy_UnaryFunction1D.h"

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////////////////

extern PyTypeObject UnaryFunction1DDouble_Type;

#define BPy_UnaryFunction1DDouble_Check(v) (PyObject_IsInstance((PyObject *)v, (PyObject *)&UnaryFunction1DDouble_Type))

/*---------------------------Python BPy_UnaryFunction1DDouble structure definition----------*/
typedef struct {
	BPy_UnaryFunction1D py_uf1D;
	UnaryFunction1D<double> *uf1D_double;
} BPy_UnaryFunction1DDouble;

/*---------------------------Python BPy_UnaryFunction1DDouble visible prototypes-----------*/
int UnaryFunction1DDouble_Init(PyObject *module);


///////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __FREESTYLE_PYTHON_UNARYFUNCTION1DDOUBLE_H__ */
