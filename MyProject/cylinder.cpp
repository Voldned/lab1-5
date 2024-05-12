#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "Cylinder.h"
#include "types.h"
#include "drawfunctions.h"
#include "scene.h"

using namespace std;

Cylinder::Cylinder()
{
	Item3D();
	SetName("Cylinder");
};

Cylinder::Cylinder(VERTEX pos, float size, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Cylinder::Cylinder(VERTEX pos, float size, COLOR color, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	SetColor(color);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Cylinder::Cylinder(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex)
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

void Cylinder::Init()
{
	unsigned N = 10;
	SetName("Cylinder");
	float x0 = pos.x, y0 = pos.y, z0 = pos.z;
	float dx = size, dy = size, dz = size;

	points.clear();
	lines.clear();
	quads.clear();



	for (float angle = 0, tex_cord = 0; angle < 1; tex_cord = fmodf(tex_cord + 1.f / N, 1))
	{
		angle += 1.f / N;
		points.push_back(get_VERTEX(x0 + size * cosf(3.14 * 2*angle), y0, z0 + size * sinf(3.14 * 2*angle)));
		points.push_back(get_VERTEX(x0 + size * cosf(3.14 * 2*angle), y0 + 4 * size, z0 + size * sinf(3.14 * 2*angle)));
	}
	
	for (unsigned l = 0; l < 2 * N; l += 1)
		lines.push_back(get_LINE(l, (l + 2) % (2*N)));
	for (unsigned l = 0; l < 2 * N; l += 2)
		lines.push_back(get_LINE(l, l + 1));

	for (unsigned l = 0; l < 2*N; l += 2)
		quads.push_back(get_QUAD(l, l+1, (l+3)% (2 * N), (l+2)%(2 * N)));
}
