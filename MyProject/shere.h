#include "item3d.h"
#include <vector>

using namespace std;
class Shere : public Item3D
{
public:
	Shere();
	Shere(VERTEX pos, float size, int drawtype, int tindex);
	Shere(VERTEX pos, float size, COLOR color, int drawtype, int tindex);
	Shere(VERTEX pos, float size, COLOR color, VERTEX angle, int drawtype, int tindex);
	void Init() override;
};

