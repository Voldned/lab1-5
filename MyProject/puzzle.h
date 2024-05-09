#pragma once

#include "quadt.h"

typedef struct {
		float x, y, x0, y0, xc, yc;
		bool complete;
		QuadT * quad;
}PuzzleItem;

class Puzzle:public QuadT
{
protected:
	int tindex;
public:
	bool gridcreate;
	PuzzleItem * objects;
	int n_objects;
	int width, height;
	float gwidth, gheight;
	int col, row;
	int selectItem;
	float mousedownx, mousedowny;

	Puzzle(VERTEX pos1, float width, float height, int col, int row, string name_texture);
	~Puzzle();
	void Draw();
	void Init();
	void SetWidth(int w);
	void SetHeight(int h);
	void SetPuzzleGridSize(int gw, int gh);
	void Schufle();
	void MouseDown(float x, float y);
	void MouseUp(float x, float y);
	void MouseMove(float x, float y);
	bool Complete();
	virtual map<string, string> GetProperties()override;
	virtual void UpdateProperty(string property, string value);
};
