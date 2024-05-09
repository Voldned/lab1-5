#include "item.h"
#include "types.h"
#include <string>

using namespace std;

Item::Item()
{
	pos.x = 0; pos.y = 0; pos.z = 0;
	angle.x = 0; angle.y = 0; angle.z = 0;
	color.r = 1; color.g = 1; color.b = 1;
	size = 1;
	name = "Item";
	visible = true;
};

string Item::GetName()
{
	return name;
}

void Item::Draw()
{
}

void Item::Init()
{
}

void Item::SetSize(float size)
{
	this->size = size;
}

void Item::SetPos(VERTEX pos)
{
	this->pos = pos;
}

void Item::SetAngle(VERTEX angle)
{
	this->angle = angle;
}

void Item::SetColor(COLOR color)
{
	this->color = color;
}

void Item::SetName(string name)
{
	this->name = name;
}

float Item::GetSize()
{
	return size;
}
VERTEX Item::GetPos()
{
	return pos;
}

VERTEX Item::GetAngle()
{
	return angle;
}

COLOR Item::GetColor()
{
	return color;
}

map<string, string> Item::GetProperties()
{
	map<string, string> result;
	result.insert(std::pair<string, string>("Name", GetName()));
	result.insert(std::pair<string, string>("Size", FloatToString(GetSize())));
	result.insert(std::pair<string, string>("Pos", VertexToString(GetPos())));
	result.insert(std::pair<string, string>("Color", ColorToString(GetColor())));
	result.insert(std::pair<string, string>("Angle", VertexToString(GetAngle())));
	return result;
}

void Item::UpdateProperty(string property, string value)
{
	if (property == "Size")
	{
		SetSize(StringToFloat(value));
		Init();
	}

	if (property == "Pos")
	{
		SetPos(StringToVertex(value));
		Init();
	}

	if (property == "Color")
		SetColor(StringToColor(value));

	if (property == "Angle")
		SetAngle(StringToVertex(value));
}

void Item::SetVisible(bool value)
{
	visible = value;
}

bool Item::GetVisible()
{
	return visible;
}

void Item::MouseDown(float x, float y){};
void Item::MouseUp(float x, float y){};
void Item::MouseMove(float x, float y){};