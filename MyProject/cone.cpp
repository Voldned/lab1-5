#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "Cone.h"
#include "types.h"
#include "drawfunctions.h"
#include "scene.h"

using namespace std;

Cone::Cone()
{
	Item3D();
	SetName("Cone");
};

Cone::Cone(VERTEX pos, float size, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Cone::Cone(VERTEX pos, float size, COLOR color, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	SetColor(color);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Cone::Cone(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex)
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

void Cone::Init()
{
	unsigned N = 10;
	SetName("Cone");
	float x0 = pos.x, y0 = pos.y, z0 = pos.z;
	float dx = size, dy = size, dz = size;

	points.clear();
	lines.clear();
	quads.clear();



	points.push_back(get_VERTEX(x0, y0 + 4 * size, z0));
	for (float angle = 0, tex_cord = 0; angle < 1; tex_cord = fmodf(tex_cord + 1.f / N, 1))
	{
		angle += 1.f / N;
		points.push_back(get_VERTEX(x0 + size * cosf(3.14 * 2 * angle), y0, z0 + size * sinf(3.14 * 2 * angle)));
	}

	for (unsigned l = 1; l <= N; l += 1)
		lines.push_back(get_LINE(0, l));
	for (unsigned l = 1; l <= N; l += 1)
		lines.push_back(get_LINE(l, fmodf(l, N)+1));

	for (unsigned l = 1; l <= N; l += 1)
		triangles.push_back(get_TRIANGLE(0, l, fmodf(l, N) + 1));
}
