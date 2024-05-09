#include "item3d.h"
#include <vector>

using namespace std;

class Fractal : public Item
{
	string type;
	VERTEX pos2;
	int value;
public:
	Fractal();
	Fractal(VERTEX pos, VERTEX pos2, string type, int value);
	
	void Draw();

};