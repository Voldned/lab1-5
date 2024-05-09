#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "line.h"
#include "triangle.h"

Triangle::Triangle(VERTEX pos1, VERTEX pos2, VERTEX pos3, COLOR color)
	:Line(pos1, pos2, color, 1)
{
	this->pos3 = pos3;
	color3 = color;
	SetName("Triangle");
}

Triangle::Triangle(VERTEX pos1, VERTEX pos2, VERTEX pos3, COLOR color, COLOR color2, COLOR color3)
	:Line(pos1, pos2, color, color2, 1)
{
	this->pos3 = pos3;
	this->color3 = color3;
	SetName("Triangle");
}

void Triangle::Draw()
{
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	glRotated(angle.x, 1, 0, 0);
	glRotated(angle.y, 0, 1, 0);
	glRotated(angle.z, 0, 0, 1);
	glScaled(size, size, size);
	glBegin(GL_TRIANGLES);
		glColor3d(color.r, color.g, color.b);
		glVertex3d(0, 0, 0);
		glColor3d(color2.r, color2.g, color2.b);
		glVertex3d(pos2.x, pos2.y, pos2.z);
		glColor3d(color3.r, color3.g, color3.b);
		glVertex3d(pos3.x, pos3.y, pos3.z);
	glEnd();
	glPopMatrix();
}

map<string, string> Triangle::GetProperties()
{
	map<string, string> result = Line::GetProperties();
	result.insert(std::pair<string, string>("Pos3", VertexToString(pos3)));
	result.insert(std::pair<string, string>("Color3", ColorToString(color3)));
	return result;
}

void Triangle::UpdateProperty(string property, string value)
{
	Line::UpdateProperty(property, value);
	if (property == "Pos3")
		pos3 = StringToVertex(value);
	if (property == "Color3")
		color3 = StringToColor(value);
}