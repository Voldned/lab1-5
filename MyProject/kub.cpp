#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "kub.h"
#include "types.h"
#include "drawfunctions.h"

using namespace std;

Kub::Kub()
{
	Item3D();
	SetName("Kub");
};

Kub::Kub(VERTEX pos, float size, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Kub::Kub(VERTEX pos, float size, COLOR color, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	SetColor(color);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Kub::Kub(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	SetColor(color);
	SetAngle(angle);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

void Kub::Init()
{
	SetName("Kub");
	float x0 = pos.x-size/2, y0 = pos.y-size/2, z0 = pos.z-size/2;
	float dx = size, dy = size, dz = size;

	points.clear();
	lines.clear();
	quads.clear();

	points.push_back(get_VERTEX(x0, y0, z0));
	points.push_back(get_VERTEX(x0 + dx, y0, z0));
	points.push_back(get_VERTEX(x0 + dx, y0 + dy, z0));
	points.push_back(get_VERTEX(x0, y0 + dy, z0));

	points.push_back(get_VERTEX(x0, y0, z0 + dz));
	points.push_back(get_VERTEX(x0 + dx, y0, z0 + dz));
	points.push_back(get_VERTEX(x0 + dx, y0 + dy, z0 + dz));
	points.push_back(get_VERTEX(x0, y0 + dy, z0 + dz));



	lines.push_back(get_LINE(0, 1));
	lines.push_back(get_LINE(1, 2));
	lines.push_back(get_LINE(2, 3));
	lines.push_back(get_LINE(0, 3));

	lines.push_back(get_LINE(4, 5));
	lines.push_back(get_LINE(5, 6));
	lines.push_back(get_LINE(6, 7));
	lines.push_back(get_LINE(7, 4));

	lines.push_back(get_LINE(0, 4));
	lines.push_back(get_LINE(1, 5));
	lines.push_back(get_LINE(2, 6));
	lines.push_back(get_LINE(3, 7));



	quads.push_back(get_QUAD(0, 3, 2, 1));
	quads.push_back(get_QUAD(1, 2, 6, 5));
	quads.push_back(get_QUAD(5, 6, 7, 4));
	quads.push_back(get_QUAD(4, 7, 3, 0));
	quads.push_back(get_QUAD(2, 3, 7, 6));
	quads.push_back(get_QUAD(1, 0, 4, 5));
	
}
