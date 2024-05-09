#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <string>

#include "particles.h"
#include "drawfunctions.h"

Particles::~Particles()
{
	particles.clear();
}

Particles::Particles(VERTEX pos, COLOR color, float size, VERTEX v)
	:Point(pos, color, size)
{
	SetName("Particles");

	this->v = v;
	
	Init();
}


void Particles::Init()
{
	lifeTime = 1000;
	dV.x = 0.1; dV.y = 0.2; dV.z = 0.1;
	minCount = 10;
	periodParticle = lifeTime/minCount; 
	lastAddParticleTime = 0;
	move = false;
	speed = 1;

	AddParticle();
	Start();
}

void Particles::Draw()
{
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	for (int i =0; i<particles.size(); i++)
	{
		bool del = false;
		if (move)
			del = particles[i]->Move(speed);
		if (del)
			{
				particles.erase(particles.begin() + i);
				i--;
			}
		else
			particles[i]->Draw();
	}

	if (move)
		if (particles.size()<minCount) AddParticle();
	glPopMatrix();
}

void Particles::AddParticle()
{
	if (move)
		if (lastAddParticleTime + periodParticle>GetTickCount()) return;

	Point * point = new Point(vrZero, color, size);
	point->Init();
	lastAddParticleTime = GetTickCount();
	if (move)
		StartParticle(point);

	particles.push_back(point);
}

void Particles::StartParticle(Point * particle)
{
	string s = VertexToString(get_VERTEX(v.x + random(-dV.x, dV.x),
			    v.y + random(-dV.y, dV.y), v.z + random(-dV.z, dV.z)));
		particle->UpdateProperty("v", s);

		particle->UpdateProperty("finishTime", IntToString( int(GetTickCount()+lifeTime)));

		particle->UpdateProperty("delAfterMove", "yes");

		particle->Start();
}

void Particles::Start()
{
	for (int i =0; i<particles.size(); i++)
	{
		StartParticle(particles[i]);
	}
	move = true;
}

void Particles::Stop()
{
	Point::Stop();
}

map<string, string> Particles::GetProperties()
{
	map<string, string> result = Point::GetProperties();
	result.insert(std::pair<string, string>("dV", VertexToString(dV)));
	result.insert(std::pair<string, string>("Time", IntToString(lifeTime)));
	result.insert(std::pair<string, string>("Count", IntToString(minCount)));
	result.insert(std::pair<string, string>("Speed", FloatToString(speed)));
	
	return result;
}

void Particles::UpdateProperty(string property, string value)
{
	Point::UpdateProperty(property, value);

	if (property == "dV")
		dV = StringToVertex(value);
	if (property == "Time")
	{
		lifeTime = StringToInt(value);
		periodParticle = lifeTime/minCount; 
	}

	if (property == "Count")
	{
		minCount = StringToInt(value);
		periodParticle = lifeTime/minCount; 
	}

	if (property == "Speed")
	
		speed = StringToFloat(value);
	
	
}