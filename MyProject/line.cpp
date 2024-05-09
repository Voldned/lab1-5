#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "point.h"
#include "line.h"

Line::Line(VERTEX pos1, VERTEX pos2, COLOR color, float size)
	:Point(pos1, color, size)
{
	this->pos2 = pos2;
	this->color2 = color;
	SetName("Line");
}

Line::Line(VERTEX pos1, VERTEX pos2, COLOR color, COLOR color2, float size)
	:Point(pos1, color, size) 
{
	this->pos2 = pos2;
	this->color2 = color2;
	SetName("Line");
}

void Line::Draw()
{
	glPushMatrix();
	glRotated(angle.x, 1, 0, 0);
	glRotated(angle.y, 0, 1, 0);
	glRotated(angle.z, 0, 0, 1);
	glLineWidth(size);
	glBegin(GL_LINES);
		glColor3d(color.r, color.g, color.b);
		glVertex3d(pos.x, pos.y, pos.z);
		glColor3d(color2.r, color2.g, color2.b);
		glVertex3d(pos.x + pos2.x, pos.y + pos2.y, pos.z + pos2.z);
	glEnd();
	glPopMatrix();
}


map<string, string> Line::GetProperties()
{
	map<string, string> result = Point::GetProperties();
	result.insert(std::pair<string, string>("Pos2", VertexToString(pos2)));
	result.insert(std::pair<string, string>("Color2", ColorToString(color2)));
	return result;
}

void Line::UpdateProperty(string property, string value)
{
	Point::UpdateProperty(property, value);
	if (property == "Pos2")
		pos2 = StringToVertex(value);

	if (property == "Color2")
		color2 = StringToColor(value);
}

