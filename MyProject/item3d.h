#pragma once

#include "types.h"
#include "item.h"
#include <vector>

using namespace std;

class Item3D : public Item
{
public:
	int tindex;
	int drawtype;
	vector <VERTEX> points;
	vector <LINE> lines;
	vector <TRIANGLE> triangles;
	vector <QUAD> quads;
	Item3D();
	~Item3D();
	virtual void Draw();
	map<string, string> GetProperties()override;
	void UpdateProperty(string property, string value)override;
};
