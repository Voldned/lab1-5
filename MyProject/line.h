#pragma once

#include "types.h"
#include "point.h"

class Line : public Point
{
protected:
	VERTEX pos2;
	COLOR color2;
public:
	Line(VERTEX pos1, VERTEX pos2, COLOR color, float size);
	Line(VERTEX pos1, VERTEX pos2, COLOR color, COLOR color2, float size);
	virtual void Draw();
	virtual map<string, string> GetProperties()override;
	virtual void UpdateProperty(string property, string value)override;
};