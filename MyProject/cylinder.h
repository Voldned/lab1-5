#include "item3d.h"
#include <vector>

using namespace std;

class Cylinder : public Item3D
{
public:
	Cylinder();
	Cylinder(VERTEX pos, float size, int drawtype, int tindex);
	Cylinder(VERTEX pos, float size, COLOR color, int drawtype, int tindex);
	Cylinder(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex);

	void Init();
};
