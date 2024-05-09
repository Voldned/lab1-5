#pragma once

#include "types.h"
#include "triangle.h"

class TriangleT : public Triangle
{
protected:
	string name_texture;
	TEXTURE_VERTEX tv1, tv2, tv3;
public:
	TriangleT(VERTEX pos1, VERTEX pos2, VERTEX pos3, COLOR color, string name_texture);
	TriangleT(VERTEX pos1, VERTEX pos2, VERTEX pos3, COLOR color, string name_texture, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3);
	virtual void Draw();
	virtual map<string, string> GetProperties()override;
	virtual void UpdateProperty(string property, string value)override;
};