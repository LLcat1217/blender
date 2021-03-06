/*
 * 'Nor' together all inputs
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

/** \file gameengine/GameLogic/SCA_NORController.cpp
 *  \ingroup gamelogic
 */


#include "SCA_NORController.h"
#include "SCA_ISensor.h"
#include "SCA_LogicManager.h"
#include "EXP_BoolValue.h"

/* ------------------------------------------------------------------------- */
/* Native functions                                                          */
/* ------------------------------------------------------------------------- */

SCA_NORController::SCA_NORController(SCA_IObject *gameobj)
	:
	SCA_IController(gameobj)
{
}



SCA_NORController::~SCA_NORController()
{
}



void SCA_NORController::Trigger(SCA_LogicManager *logicmgr)
{

	bool sensorresult = true;

	for (SCA_ISensor *sensor : m_linkedsensors) {
		if (sensor->GetState()) {
			sensorresult = false;
			break;
		}
	}

	for (SCA_IActuator *actuator : m_linkedactuators) {
		logicmgr->AddActiveActuator(actuator, sensorresult);
	}
}



EXP_Value *SCA_NORController::GetReplica()
{
	EXP_Value *replica = new SCA_NORController(*this);
	// this will copy properties and so on...
	replica->ProcessReplica();

	return replica;
}

#ifdef WITH_PYTHON

/* ------------------------------------------------------------------------- */
/* Python functions                                                          */
/* ------------------------------------------------------------------------- */

/* Integration hooks ------------------------------------------------------- */
PyTypeObject SCA_NORController::Type = {
	PyVarObject_HEAD_INIT(nullptr, 0)
	"SCA_NORController",
	sizeof(EXP_PyObjectPlus_Proxy),
	0,
	py_base_dealloc,
	0,
	0,
	0,
	0,
	py_base_repr,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	0, 0, 0, 0, 0, 0, 0,
	Methods,
	0,
	0,
	&SCA_IController::Type,
	0, 0, 0, 0, 0, 0,
	py_base_new
};

PyMethodDef SCA_NORController::Methods[] = {
	{nullptr, nullptr} //Sentinel
};

PyAttributeDef SCA_NORController::Attributes[] = {
	EXP_PYATTRIBUTE_NULL    //Sentinel
};

#endif // WITH_PYTHON

/* eof */
