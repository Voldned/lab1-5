#pragma once

#include "types.h"
#include "quad.h"

class QuadT : public Quad
{
protected:
	string name_texture;
	TEXTURE_VERTEX tv1, tv2, tv3, tv4;
public:
	QuadT(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color, string name_texture);
	QuadT(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color, string name_texture, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, TEXTURE_VERTEX tv4);
	virtual void Draw();
	virtual map<string, string> GetProperties()override;
	virtual void UpdateProperty(string property, string value)override;
};