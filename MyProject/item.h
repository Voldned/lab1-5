#pragma once
#include <iostream>
#include "types.h"
#include <map>

using namespace std;

class Item
{
protected:
	VERTEX pos;
	VERTEX angle;
	COLOR color;
	float size;
	string name;
	bool visible;
public:

	Item();
	virtual void Draw();
	virtual void Init();
	void SetSize(float size);
	void SetPos(VERTEX pos);
	void SetAngle(VERTEX angle);
	void SetColor(COLOR color);
	void SetName(string name);
	string GetName();
	float GetSize();
	VERTEX GetPos();
	VERTEX GetAngle();
	COLOR GetColor();
	void SetVisible(bool value);
	bool GetVisible();
	virtual map<string, string> GetProperties();
	virtual void UpdateProperty(string property, string value);
	virtual void MouseDown(float x, float y);
	virtual void MouseUp(float x, float y);
	virtual void MouseMove(float x, float y);
};

