#include "item3d.h"
#include <vector>

using namespace std;

class Cone : public Item3D
{
public:
	Cone();
	Cone(VERTEX pos, float size, int drawtype, int tindex);
	Cone(VERTEX pos, float size, COLOR color, int drawtype, int tindex);
	Cone(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex);

	void Init();
};
#pragma once
