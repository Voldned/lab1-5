#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "shere.h"
#include "types.h"
#include "drawfunctions.h"

using namespace std;

Shere::Shere()
{
	Item3D();
	tindex = -1;
	drawtype = 0;
	SetName("Shere");
};


Shere::Shere(VERTEX pos, float size, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Shere::Shere(VERTEX pos, float size, COLOR color, int drawtype, int tindex)
{
	Item3D();
	SetPos(pos);
	SetSize(size);
	SetColor(color);
	this->tindex = tindex;
	this->drawtype = drawtype;

	Init();
}

Shere::Shere(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex)
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

void Shere::Init()
{
	SetName("Shere");
	int i = 0, j, l, k = 0, q = 0;
	float a, b;
	float R = size/2;
	int N = 30;
	float da = 2 * 3.1415f / N;
	float dx = 1;
	float x, y, z;

	points.clear();
	lines.clear();
	quads.clear();
   //  формирование точек
	for (l = 0; l < N; l++)
	for (j = 0; j < N; j++)
	{
		a = j*da;
		b = l*da / 2;
		x = R * sin(a)*sin(b);
		y = R * cos(b);
		z = R * cos(a)*sin(b);
		points.push_back(get_VERTEX(x+pos.x, y+pos.y, z+pos.z));
	}

   //  формирование горизонтальных линий
	for (l = 0; l < N; l++)
	{
		for (j = 0; j < N - 1; j++)
		{
			lines.push_back(get_LINE(j + l*N, j + 1 + l*N));
		}
		lines.push_back(get_LINE(l*N, N - 1 + l*N));
	}

//  формирование вертикальных линий
	for (l = 0; l < N - 1; l++)
	for (j = 0; j < N; j++)
	{
		lines.push_back(get_LINE(j + l*N, j + N + l*N));
	}

//  формирование полигонов
	for (j = 0; j < N-1; j++)
	{
		for (l = 0; l < N - 1; l++)
		{
			quads.push_back(get_QUAD(l + j*N, l + 1 + j*N, l + N + 1 + j*N, l + N + j*N));
		}
		quads.push_back(get_QUAD(0 + j*N, 0 + N + j*N, 0 + j*N + N + N-1, 0 + j*N + N - 1));
	}

}
