#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <string>

#include "puzzle.h"
#include "drawfunctions.h"

Puzzle::Puzzle(VERTEX pos1, float width, float height, int col, int row, string name_texture)
	:QuadT(pos1, pos2, pos3, pos4, clWhite, name_texture)
{
	SetPos(pos);
	this->pos2 = Sum(pos, get_VERTEX(pos.x, pos.y + height));
	this->pos3 = Sum(pos, get_VERTEX(pos.x + width, pos.y + height));
	this->pos4 = Sum(pos, get_VERTEX(pos.x + width, pos.y));
	this->col = col; this->row = row;
	this->width = width;
	this->height = height;

	gridcreate = false;
	n_objects = 0;
	selectItem =-1;
	SetName("Puzzle");

	Init();
}

void Puzzle::Init()
{
	SetPuzzleGridSize(col, row);
}

Puzzle::~Puzzle()
{
	if (gridcreate)
	{
		for (int i = 0; i<n_objects; i++)
			delete objects[i].quad;
			
	}
}

void Puzzle::Draw()
{
	if (!gridcreate)
		QuadT::Draw();
	else
	{
		glPushMatrix();
		glTranslated(pos.x, pos.y, pos.z);

		if (!Complete())
		{
			DrawLine(-width/2, -height/2, -width/2, height/2, 1.0f, 1.0f, 1.0f);
			DrawLine(width/2, -height/2, width/2, height/2, 1.0f, 1.0f, 1.0f);
			DrawLine(-width/2, -height/2, width/2, -height/2, 1.0f, 1.0f, 1.0f);
			DrawLine(-width/2, height/2, width/2, height/2, 1.0f, 1.0f, 1.0f);
		}
		for (int i = 0; i<n_objects; i++)
		{
	
				glPushMatrix();
				glTranslated(objects[i].x, objects[i].y, 0);
				objects[i].quad->Draw();
				glLineWidth(2);
				if (!objects[i].complete)
				{
					DrawLine(0, 0, 0, gheight, 1.0f, 1.0f, 1.0f);
					DrawLine(0, gheight, gwidth, gheight, 1.0f, 1.0f, 1.0f);
					DrawLine(gwidth, gheight, gwidth, 0, 1.0f, 1.0f, 1.0f);
					DrawLine(gwidth, 0, 0, 0, 1.0f, 1.0f, 1.0f);
				}
				glPopMatrix();
		};
		glPopMatrix();
	}
}

void Puzzle::SetWidth(int w)
{
	width = w;
}
void Puzzle::SetHeight(int h)
{
	height = h;
}

void Puzzle::SetPuzzleGridSize(int gw, int gh)
{
	
	objects = (PuzzleItem *) malloc(gw * gh * sizeof(PuzzleItem ));
	int k =0;
	gwidth= (1.0f*width)/ gw;
	gheight = (1.0f*height)/ gh;

	float dtx = 1.0f/ gw;
	float dty = 1.0f/ gh;
	for (int i = 0; i<gw; i++)
		for (int j = 0; j<gh; j++)
		{
			VERTEX pos1 = get_VERTEX(0, 0);
			VERTEX pos2 = get_VERTEX(0, gheight);
			VERTEX pos3 = get_VERTEX(gwidth, gheight);
			VERTEX pos4 = get_VERTEX(gwidth, 0);

			TEXTURE_VERTEX tx1 = get_TEXTURE_VERTEX(i*dtx, j*dty);
			TEXTURE_VERTEX tx2 = get_TEXTURE_VERTEX(i*dtx, (j+1)*dty);
			TEXTURE_VERTEX tx3 = get_TEXTURE_VERTEX((i+1)*dtx, (j+1)*dty);
			TEXTURE_VERTEX tx4 = get_TEXTURE_VERTEX((i+1)*dtx, j*dty);

			objects[k].quad = new QuadT(pos1, pos2, pos3, pos4, color, name_texture, tx1, tx2, tx3, tx4); 
			objects[k].x = -width/2+i*gwidth;
			objects[k].y = -height/2+j*gheight;
			objects[k].xc = objects[k].x;
			objects[k].yc = objects[k].y;
			objects[k].complete = false;
			k++;
		}
	n_objects = k;

	gridcreate = true;
	Schufle();
}

void Puzzle::Schufle()
{
	srand(GetTickCount());
	for (int i = 1; i<50; i++)
	{
		int i1 = rand()%n_objects;
		int i2 = rand()%n_objects;
		float t = objects[i1].x;
		objects[i1].x = objects[i2].x;
		objects[i2].x = t;
		t = objects[i1].y;
		objects[i1].y = objects[i2].y;
		objects[i2].y = t;
	}
}

void Puzzle::MouseDown(float x, float y)
{
	float fx = 1.f* x * width;
	float fy = 1.f* y * height;
	if (gridcreate)
	{
		for (int i = n_objects-1; i>=0; i--)
			if (!objects[i].complete)
			if ((objects[i].x<fx) && (objects[i].x+gwidth>fx) && (objects[i].y<fy) && (objects[i].y+gheight>fy))
			{
				mousedownx = fx;
				mousedowny = fy;
				objects[i].x0 = objects[i].x;
				objects[i].y0 = objects[i].y;
				PuzzleItem Item = objects[i];
				for (int j = i; j<n_objects-1; j++)
					objects[j] = objects[j+1];
				objects[n_objects-1] = Item;
				selectItem = n_objects-1;
				break;
			}
	}
}

void Puzzle::MouseUp(float x, float y)
{
	if (selectItem>-1)
	{
		float d = pow(objects[selectItem].x - objects[selectItem].xc, 2) 
			+ pow(objects[selectItem].y - objects[selectItem].yc, 2);
		d=pow(d, 0.5f);
		if (d<0.1)
		{
			objects[selectItem].x = objects[selectItem].xc; 
			objects[selectItem].y = objects[selectItem].yc;
			objects[selectItem].complete = true;
		}
	}

	selectItem = -1;
}

void Puzzle::MouseMove(float x, float y)
{
	float fx = 1.f* x * width;
	float fy = 1.f* y * height;

	if (gridcreate)
		if (selectItem>-1)
		{
			objects[selectItem].x = objects[selectItem].x0 + (fx - mousedownx);
			objects[selectItem].y = objects[selectItem].y0 + (fy - mousedowny);
		}
}
bool Puzzle::Complete()
{
	for (int i = n_objects-1; i>=0; i--)
		if (!objects[i].complete) return false;
	return true;
}


map<string, string> Puzzle::GetProperties()
{
	map<string, string> result = QuadT::GetProperties();
	result.insert(std::pair<string, string>("width", IntToString(width)));
	result.insert(std::pair<string, string>("height", IntToString(height)));
	result.insert(std::pair<string, string>("col", IntToString(col)));
	result.insert(std::pair<string, string>("row", IntToString(row)));
	return result;
}

void Puzzle::UpdateProperty(string property, string value)
{
	QuadT::UpdateProperty(property, value);

	if (property == "width")
	{
		width = StringToInt(value);
		Init();
	}
	if (property == "height")
	{
		height = StringToInt(value);
		Init();
	}
	if (property == "col")
	{
		col = StringToInt(value);
		Init();
	}
	if (property == "row")
	{
		row = StringToInt(value);
		Init();
	}
	
}