#include "types.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>

TEXTURE_VERTEX get_TEXTURE_VERTEX(float x, float y)
{
	TEXTURE_VERTEX tv = {x, y};
	return tv;
}

VERTEX get_VERTEX(float x, float y, float z)
{
	VERTEX v = {x, y, z};
	//v.x = x; v.y = y; v.z = z;
	return v;
}

LINE get_LINE(int p1, int p2)
{
	LINE l;
	l.p1 = p1; l.p2 = p2;
	return l;
}

TRIANGLE get_TRIANGLE(int p1, int p2, int p3)
{
	TRIANGLE t;
	t.p1 = p1; t.p2 = p2; t.p3 = p3;
	return t;
}

QUAD get_QUAD(int p1, int p2, int p3, int p4)
{
	QUAD q;
	q.p1 = p1; q.p2 = p2; q.p3 = p3; q.p4 = p4;
	return q;
}

COLOR get_COLOR(float r, float g, float b)
{
	COLOR v;
	v.r = r; v.g = g; v.b = b;
	return v;
}

//   Возвращает вектор, перпендикулярный 2м переданным.
VERTEX Cross(VERTEX v1, VERTEX v2)
{
    VERTEX vNormal; 
    vNormal.x = ((v1.y * v2.z) - (v1.z * v2.y));
 
     vNormal.y = ((v1.z * v2.x) - (v1.x * v2.z));
 
    vNormal.z = ((v1.x * v2.y) - (v1.y * v2.x));
 
    return vNormal;
}

//   возвращает величину нормали
float Magnitude(VERTEX vNormal)
{
    return (float)sqrt( (vNormal.x * vNormal.x) +
                (vNormal.y * vNormal.y) +
                (vNormal.z * vNormal.z) );
}

//   возвращает нормализованный вектор (с длинной 1)
VERTEX Normalize(VERTEX vNormal)
{
    float magnitude = Magnitude(vNormal);
 
    vNormal.x /= magnitude;
    vNormal.y /= magnitude;
    vNormal.z /= magnitude;
 
    return vNormal;
}

//   Возвращает вектор между 2мя точками.
VERTEX Sub(VERTEX v1, VERTEX v2)
{
    VERTEX v;

    v.x = v1.x - v2.x;      
    v.y = v1.y - v2.y;      
    v.z = v1.z - v2.z;      
 
    return v;
}

//   Возвращает сумму векторов.
VERTEX Sum(VERTEX v1, VERTEX v2)
{
    VERTEX v;

    v.x = v1.x + v2.x;      
    v.y = v1.y + v2.y;      
    v.z = v1.z + v2.z;      
 
    return v;
}
//   Возвращает нормаль по трём точкам
VERTEX Normal(VERTEX v1, VERTEX v2, VERTEX v3)
{
    VERTEX V1 = Sub(v3, v1);
    VERTEX V2 = Sub(v2, v1);
 
    VERTEX vNormal = Cross(V1, V2);
 
    vNormal = Normalize(vNormal);
 
    return vNormal;
}

float random(float a, float b)
{
	float result = rand()%1000/1000.f*(b-a)+a;
	return result;
}

std::string FloatToString(float f)
{
string res = "";
char buffer[20];
if (f < 0) res = res + '-';
f = fabs(f);
float whole = (int) f;
float frac = (f - whole)*100;
string res_frac = itoa(frac, buffer, 10);
res = res + itoa(whole, buffer, 10);
res = res + '.';
if (frac>0)
	for (int i = 0; i<(2-strlen(res_frac.c_str())); i++)
		res = res + '0';
res = res +  res_frac;

return res;
}

float StringToFloat(string s)
{
	return atof(s.c_str());
}

std::string IntToString(int i)
{
	string res = "";
	char buffer[20];
	res = itoa(i, buffer, 10);
	return res;
}

int StringToInt(string s)
{
	return (int)atof(s.c_str());
}

std::string VertexToString(VERTEX v)
{
	string result = "";
	result.append(FloatToString(v.x));
	result.append(",");
	result.append(FloatToString(v.y));
	result.append(",");
	result.append(FloatToString(v.z));
	return result;
}

std::string ColorToString(COLOR c)
{
	string result = "";
	result.append(FloatToString(c.r));
	result.append(",");
	result.append(FloatToString(c.g));
	result.append(",");
	result.append(FloatToString(c.b));
	return result;
}

std::string TEXTUREVertexToString(TEXTURE_VERTEX v)
{
	string result = "";
	result.append(FloatToString(v.x));
	result.append(",");
	result.append(FloatToString(v.y));
	return result;
}

VERTEX StringToVertex(string s)
{
	VERTEX result = vrZero;
	int pos = s.find(',');
	if (pos > 0)
	{
		string s2 = s.substr(0, pos);
		result.x = StringToFloat(s2);
		s = s.substr(pos+1);
		pos = s.find(',');
		if (pos > 0)
		{
			s2 = s.substr(0, pos);
			result.y = StringToFloat(s2);
			s = s.substr(pos+1);
			result.z = StringToFloat(s);
		}
	}
	return result;
}

TEXTURE_VERTEX StringToVertexTexture(string s)
{
	TEXTURE_VERTEX result = { 0, 0 };
	int pos = s.find(',');
	if (pos > 0)
	{
		string s2 = s.substr(0, pos);
		result.x = StringToFloat(s2);
		s = s.substr(pos + 1);
		result.y = StringToFloat(s);
		
	}
	return result;
}

COLOR StringToColor(string s)
{
	COLOR result = clBlack;
	int pos = s.find(',');
	if (pos > 0)
	{
		string s2 = s.substr(0, pos);
		result.r = StringToFloat(s2);
		s = s.substr(pos+1);
		pos = s.find(',');
		if (pos > 0)
		{
			s2 = s.substr(0, pos);
			result.g = StringToFloat(s2);
			s = s.substr(pos+1);
			result.b = StringToFloat(s);
		}
	}
	return result;
}
