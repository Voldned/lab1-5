#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "fractal.h"
#include "types.h"
#include "drawfunctions.h"

using namespace std;

Fractal::Fractal()
{
	Item();
	SetName("Fractal");
}


Fractal::Fractal(VERTEX pos, VERTEX pos2, string type, int value)
{
	Item();
	SetPos(pos);
	this->pos2 = pos2;
	this->type = type;
	this->value = value;
	SetName("Fractal");
}

void Fractal::Draw()
{

	if (type.compare("kox")==0)
	{
		glLineWidth(5);
 		DrawKox(value, pos.x, pos.y, pos2.x, pos2.y);
	}
	if (type.compare("levi")==0)
	{
		glLineWidth(5);
 		DrawLevi(value, pos.x, pos.y, pos2.x, pos2.y);
	}

	if (type.compare("kox_a")==0)
	{
		glLineWidth(5);
		int n;
		n = GetTickCount()/300%(value*2);
		if (n>value) n = value+value-n;
		if (n == 0) n = 1;
 		DrawKox(n, pos.x, pos.y, pos2.x, pos2.y);
	}

	if (type.compare("levi_a")==0)
	{
		glLineWidth(5);
		int n;
		n = GetTickCount()/300%(value*2);
		if (n>value) n = value+value-n;
		if (n == 0) n = 1;
 		DrawLevi(n, pos.x, pos.y, pos2.x, pos2.y);
	}

	if (type.compare("mondelbrot")==0)
	{
		DrawMondelbrot();
	}
}