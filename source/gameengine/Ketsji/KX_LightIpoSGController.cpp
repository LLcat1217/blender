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

/** \file gameengine/Ketsji/KX_LightIpoSGController.cpp
 *  \ingroup ketsji
 */


#include "KX_LightIpoSGController.h"
#include "KX_LightObject.h"
#include "RAS_ILightObject.h"

bool KX_LightIpoSGController::Update(SG_Node *node)
{
	if (!SG_Controller::Update(node)) {
		return false;
	}

	KX_LightObject *kxlight = static_cast<KX_LightObject *>(node->GetObject());
	RAS_ILightObject *lightobj = kxlight->GetLightData();

	if (m_modify_energy) {
		lightobj->m_energy = m_energy;
	}

	if (m_modify_color) {
		lightobj->m_color = m_col_rgb;
	}

	if (m_modify_dist) {
		lightobj->m_distance = m_dist;
	}

	return true;
}
