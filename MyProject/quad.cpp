#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "triangle.h"
#include "quad.h"

Quad::Quad(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color)
	:Triangle(pos1, pos2, pos3, color)
{
	this->pos4 = pos4;
	color4 = color;
	SetName("Quad");
}

Quad::Quad(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color, COLOR color2, COLOR color3, COLOR color4)
	:Triangle(pos1, pos2, pos3, color, color2, color3)
{
	this->pos4 = pos4;
	this->color4 = color4;
	SetName("Quad");
}

void Quad::Draw()
{
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	glRotated(angle.x, 1, 0, 0);
	glRotated(angle.y, 0, 1, 0);
	glRotated(angle.z, 0, 0, 1);
	glScaled(size, size, size);
	glBegin(GL_QUADS);
		glColor3d(color.r, color.g, color.b);
		glVertex3d(0, 0, 0);
		glColor3d(color2.r, color2.g, color2.b);
		glVertex3d(pos2.x, pos2.y, pos2.z);
		glColor3d(color3.r, color3.g, color3.b);
		glVertex3d(pos3.x, pos3.y, pos3.z);
		glColor3d(color4.r, color4.g, color4.b);
		glVertex3d(pos4.x, pos4.y, pos4.z);
	glEnd();
	glPopMatrix();
}

map<string, string> Quad::GetProperties()
{
	map<string, string> result = Triangle::GetProperties();
	result.insert(std::pair<string, string>("Pos4", VertexToString(pos4)));
	result.insert(std::pair<string, string>("Color4", ColorToString(color4)));
	return result;
}

void Quad::UpdateProperty(string property, string value)
{
	Triangle::UpdateProperty(property, value);
	if (property.compare("Pos4") == 0)
		pos4 = StringToVertex(value);
	if (property.compare("Color4") == 0)
		color4 = StringToColor(value);
}