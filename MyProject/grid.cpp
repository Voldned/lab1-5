#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "grid.h"
#include "types.h"
#include "drawfunctions.h"

using namespace std;

Grid::Grid()
{
	Item3D();
	SetName("Grid");
}

Grid::Grid(VERTEX pos, float cellsize, int cellcol, int cellrow)
{
	Item3D();
	SetPos(pos);
	this->cellsize = cellsize;
	this->cellcol = cellcol;
	this->cellrow = cellrow;
	drawtype = 5;
	sdParam = cellsize*0.02f;
	Init();
	SetName("Grid");
}
	
void Grid::CreateSquareDiamand(int x1, int y1, int xn, int yn, int n)
{
	if (n==0) return;

	if ((xn-x1<2)||(yn-y1<2)) return;
	//cout<<"n= "<<n<<endl;
	//cout<< x1<<" "<<y1<<" "<<xn<<" "<<yn<<endl;
	int x0 = (xn - x1)/2+x1;
	int y0 = (yn - y1)/2+y1;

	//cout<<"x0,y0="<< x0<<" "<<y0<<endl;

	points[x1*cellrow+y1].y += random(-sdParam*n, sdParam*n);
	points[x1*cellrow+yn].y += random(-sdParam*n, sdParam*n);
	points[xn*cellrow+yn].y += random(-sdParam*n, sdParam*n);
	points[xn*cellrow+y1].y += random(-sdParam*n, sdParam*n);

	// center
	points[x0*cellrow+y0].y = (points[x1*cellrow+y1].y + points[x1*cellrow+yn].y + points[xn*cellrow+yn].y + points[xn*cellrow+y1].y)/4 + random(-sdParam*n, sdParam*n);

	//left
	points[x1*cellrow+y0].y = (points[x1*cellrow+y1].y + points[x1*cellrow+yn].y + points[x0*cellrow+y0].y)/3 + random(-sdParam*n, sdParam*n);

	//right
	points[xn*cellrow+y0].y = (points[xn*cellrow+y1].y + points[xn*cellrow+yn].y + points[x0*cellrow+y0].y)/3 + random(-sdParam*n, sdParam*n);
	
	//bottom
	points[x0*cellrow+y1].y = (points[x1*cellrow+y1].y + points[xn*cellrow+y1].y + points[x0*cellrow+y0].y)/3 + random(-sdParam*n, sdParam*n);

	//top
	points[x0*cellrow+yn].y = (points[x1*cellrow+yn].y + points[xn*cellrow+yn].y + points[x0*cellrow+y0].y)/3 + random(-sdParam*n, sdParam*n);

	CreateSquareDiamand(x1, y1, x0, y0, n-1);
	CreateSquareDiamand(x1, y0, x0, yn, n-1);
	CreateSquareDiamand(x0, y1, xn, y0, n-1);
	CreateSquareDiamand(x0, y0, xn, yn, n-1);
}

void Grid::Init()
{

	//  формирование точек
	for (int i = 0; i < cellcol; i++)
		for (int j = 0; j < cellrow; j++)
			{
				float x = -cellcol*cellsize/2 + cellsize/2 + cellsize*i + random(-sdParam*2.f, sdParam*2.f);
				float y = 0*(rand()%100/100.f-0.5f)/1;
				float z = -cellrow*cellsize/2 + cellsize/2 + cellsize*j + random(-sdParam*2.f, sdParam*2.f);
				points.push_back(get_VERTEX(pos.x + x, pos.y + y, pos.z + z));
			}

	//  формирование горизонтальных линий
	for (int i = 0; i < cellcol; i++)
		for (int j = 0; j < cellrow-1; j++)
			lines.push_back(get_LINE(j + i*cellrow, j + 1 + i*cellrow));

	//  формирование вертикальных линий
	for (int i = 0; i < cellcol-1; i++)
		for (int j = 0; j < cellrow; j++)
			lines.push_back(get_LINE(j + i*cellrow, j + cellrow + i*cellrow));


	//glEnable(GL_NORMALIZE);
	srand(GetTickCount());

	points[0*cellrow+0].y += 0;
	CreateSquareDiamand(0, 0, cellcol-1, cellrow-1, 8);

	//  формирование полигонов
	for (int j = 0; j < cellrow - 1; j++)
		for (int i = 0; i < cellcol - 1; i++)
			quads.push_back(get_QUAD(j + i*cellrow, j + 1 + i*cellrow, j + cellrow + 1 + i*cellrow, j + cellrow + i*cellrow));

}