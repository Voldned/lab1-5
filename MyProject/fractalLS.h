#include "item3d.h"

using namespace std;

class FractalLS : public Item
{
	int value;
	string LS, stroka1, rule1, stroka2, rule2, stroka3, rule3;
	int drawtype;
	
public:
	FractalLS();
	FractalLS(VERTEX pos, int value, float size, int drawtype, string LS, string stroka1, string rule1, string stroka2="", string rule2="", string stroka3="", string  rule3="");
	
	void Draw();
	void Init();
};