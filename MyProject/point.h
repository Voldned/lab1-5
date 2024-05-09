#pragma once

#include "types.h"
#include "item.h"

class Point : public Item
{
protected:
	VERTEX v;
	bool move;
	int startTime;
	int finishTime;
	bool delAfterMove;

public:
	Point(VERTEX pos, COLOR color, float size);
	virtual void Draw();
	virtual void UpdateProperty(string property, string value);
	virtual map<string, string> GetProperties()override;
	void Init();
	void Start();
	void Stop();
	bool Move(float speed);

};
