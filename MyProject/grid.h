#include "item3d.h"
#include <vector>

using namespace std;

class Grid : public Item3D
{
	float cellsize;
	int cellcol, cellrow;
	float sdParam;
public:
	Grid();
	Grid(VERTEX pos, float cellsize, int cellcol, int cellrow);
	
	void Init();
	void CreateSquareDiamand(int x0, int y0, int xn, int yn, int n);
};
