#pragma once

#include "types.h"
#include "line.h"

class Triangle : public Line
{
protected:
	VERTEX pos3;
	COLOR color3;
public:
	Triangle(VERTEX pos1, VERTEX pos2, VERTEX pos3, COLOR color);
	Triangle(VERTEX pos1, VERTEX pos2, VERTEX pos3, COLOR color, COLOR color2, COLOR color3);
	virtual void Draw();
	virtual map<string, string> GetProperties()override;
	virtual void UpdateProperty(string property, string value)override;
};