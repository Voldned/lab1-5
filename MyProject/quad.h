#pragma once

#include "types.h"
#include "Triangle.h"

class Quad : public Triangle
{
protected:
	VERTEX pos4;
	COLOR color4;
public:
	Quad(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color);
	Quad(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color, COLOR color2, COLOR color3, COLOR color4);
	virtual void Draw();
	virtual map<string, string> GetProperties()override;
	virtual void UpdateProperty(string property, string value)override;
};