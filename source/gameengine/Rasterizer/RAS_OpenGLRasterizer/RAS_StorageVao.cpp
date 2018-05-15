/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
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
 * Contributor(s): Tristan Porteries.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

#include "RAS_DisplayArray.h"
#include "RAS_DisplayArrayStorage.h"
#include "RAS_StorageVao.h"
#include "RAS_StorageVbo.h"

struct AttribData {
	int size;
	GLenum type;
	bool normalized;
};

static const AttribData attribData[RAS_AttributeArray::RAS_ATTRIB_MAX] = {
	{3, GL_FLOAT, false}, // RAS_ATTRIB_POS
	{2, GL_FLOAT, false}, // RAS_ATTRIB_UV
	{3, GL_FLOAT, false}, // RAS_ATTRIB_NORM
	{4, GL_FLOAT, false}, // RAS_ATTRIB_TANGENT
	{4, GL_UNSIGNED_BYTE, true} // RAS_ATTRIB_COLOR
};

RAS_StorageVao::RAS_StorageVao(RAS_IDisplayArray *array, RAS_DisplayArrayStorage *arrayStorage,
                               const RAS_AttributeArray::AttribList& attribList)
{
	glGenVertexArrays(1, &m_id);
	glBindVertexArray(m_id);

	RAS_StorageVbo *vbo = arrayStorage->GetVbo();
	vbo->BindVertexBuffer();
	vbo->BindIndexBuffer();

	const RAS_VertexDataMemoryFormat& memoryFormat = array->GetMemoryFormat();

	const unsigned int stride = memoryFormat.size;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, stride, (const void *)memoryFormat.position);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, stride, (const void *)memoryFormat.normal);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_UNSIGNED_BYTE, stride, (const void *)memoryFormat.colors);

	for (const RAS_AttributeArray::Attrib& attrib : attribList) {
		const RAS_AttributeArray::AttribType type = attrib.m_type;
		intptr_t offset = 0;
		switch (type) {
			case RAS_AttributeArray::RAS_ATTRIB_POS:
			{
				offset = memoryFormat.position;
				break;
			}
			case RAS_AttributeArray::RAS_ATTRIB_UV:
			{
				offset = memoryFormat.uvs + (attrib.m_layer * sizeof(float[2]));
				break;
			}
			case RAS_AttributeArray::RAS_ATTRIB_NORM:
			{
				offset = memoryFormat.normal;
				break;
			}
			case RAS_AttributeArray::RAS_ATTRIB_TANGENT:
			{
				offset = memoryFormat.tangent;
				break;
			}
			case RAS_AttributeArray::RAS_ATTRIB_COLOR:
			{
				offset = memoryFormat.colors + (attrib.m_layer * sizeof(int));
				break;
			}
			default:
			{
				BLI_assert(false);
				break;
			}
		}

		const unsigned short loc = attrib.m_loc;
		const AttribData& data = attribData[type];

		if (attrib.m_texco) {
			glClientActiveTexture(GL_TEXTURE0 + loc);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(data.size, data.type, stride, (const void *)offset);
		}
		else {
			glEnableVertexAttribArray(loc);
			glVertexAttribPointer(loc, data.size, data.type, data.normalized, stride, (const void *)offset);
		}
	}

	glClientActiveTexture(GL_TEXTURE0);

	// VBO are not tracked by the VAO excepted for IBO.
	vbo->UnbindVertexBuffer();

	glBindVertexArray(0);
}

RAS_StorageVao::~RAS_StorageVao()
{
	glDeleteVertexArrays(1, &m_id);
}

void RAS_StorageVao::BindPrimitives()
{
	glBindVertexArray(m_id);
}

void RAS_StorageVao::UnbindPrimitives()
{
	glBindVertexArray(0);
}
