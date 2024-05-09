#pragma once

#include "types.h"
#include "point.h"
#include "line.h"
#include <vector>

class Particles:public Point
{
protected:
	vector<Point *> particles; // массив частий
	//VERTEX v; // вестор направления
	VERTEX dV; // разброс скоростей по осям
	float lifeTime; // время жизни частицы
	int minCount; // минимальное количество частиц
	int lastAddParticleTime; // время добавления последней частицы
	float periodParticle; // период между появлением частиц
	float speed;
public:
	~Particles();
	Particles(VERTEX pos, COLOR color, float size, VERTEX pos2);
		virtual void Draw();
	virtual void Init();
	virtual void Start();
	void StartParticle(Point * particle);
	virtual void Stop();
	void AddParticle();
	virtual map<string, string> GetProperties()override;
	virtual void UpdateProperty(string property, string value);
};

