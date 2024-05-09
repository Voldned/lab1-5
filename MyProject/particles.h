#pragma once

#include "types.h"
#include "point.h"
#include "line.h"
#include <vector>

class Particles:public Point
{
protected:
	vector<Point *> particles; // ������ ������
	//VERTEX v; // ������ �����������
	VERTEX dV; // ������� ��������� �� ����
	float lifeTime; // ����� ����� �������
	int minCount; // ����������� ���������� ������
	int lastAddParticleTime; // ����� ���������� ��������� �������
	float periodParticle; // ������ ����� ���������� ������
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

