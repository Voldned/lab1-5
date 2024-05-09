#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "point.h"
#include "drawfunctions.h"

Point::Point(VERTEX pos, COLOR color, float size)
{
	Item();
	SetPos(pos);
	SetColor(color);
	SetSize(size);
	SetName("Point");
	v = vrZero;
}

void Point::Draw()
{
	DrawRound(pos, size/100, color);
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(size);
	glColor3d(color.r, color.g, color.b);
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	glBegin(GL_POINTS);
	glVertex3d(0, 0, 0);
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);*/

}

map<string, string> Point::GetProperties()
{
	map<string, string> result = Item::GetProperties();
	result.insert(std::pair<string, string>("v", VertexToString(v)));
	return result;
}

void Point::UpdateProperty(string property, string value)
{
	Item::UpdateProperty(property, value);
	if (property == "v")
		v = StringToVertex(value);
	if (property == "finishTime")
		finishTime = StringToInt(value);
	if (property == "delAfterMove")
		delAfterMove = value=="yes";
	
}

void Point::Init()
{
	v.x = 0; v.y = 0; v.z = 0;
	move = false;
	startTime = 0;
	finishTime = 0;
	delAfterMove = false;
}

void Point::Start()
{
	move = true;
	startTime = GetTickCount();
}

void Point::Stop()
{
	move = false;
}

bool Point::Move(float speed)
{
	if (move)
	{
		float dt = (GetTickCount() - startTime)/1000.f*speed;
		pos.x += dt*v.x;
		pos.y += dt*v.y;
		pos.z += dt*v.z;
		startTime = GetTickCount();
		if (delAfterMove)
			if (finishTime<GetTickCount()) return true;
	}
	return false;
}
