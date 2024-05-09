#include "item3d.h"
#include <vector>

using namespace std;

class Kub : public Item3D
{
public:
	Kub();
	Kub(VERTEX pos, float size, int drawtype, int tindex);
	Kub(VERTEX pos, float size, COLOR color, int drawtype, int tindex);
	Kub(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex);
	void Init();
};
