#include "fractalLS.h"
#include "types.h"
#include "drawfunctions.h"
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

FractalLS::FractalLS()
{
	Item();
	SetName("FractalLS");
}

FractalLS::FractalLS(VERTEX pos, int value, float size, int drawtype, string LS, string stroka1, string rule1, string stroka2, string rule2, string stroka3, string rule3)
{
	Item();
	SetPos(pos);
	SetSize(size);
	this->LS = LS;
	this->value = value;
	this->stroka1 = stroka1;
	this->rule1 = rule1;
	this->stroka2 = stroka2;
	this->rule2 = rule2;
	this->stroka3 = stroka3;
	this->rule3 = rule3;
	this->drawtype = drawtype;
	Init();
	SetName("FractalLS");
}


string UseRule(string s, string s1, string r1, string s2 = "", string r2 = "", string s3 = "", string r3 = "")
{
	int n = s.length()-s1.length()+1; string s0=""; string s00;
	for (int i=0; i<n; i++)
	{   s00 = s.substr(i, s1.length());
   		   if (s1.compare(s00)==0) s0 = s0 + r1;
  	     else
			 if ((s2!="")&&(s2.compare(s00)==0))  	s0 = s0 + r2;
			else
				if ((s3!="")&&(s3.compare(s00)==0)) 	s0 = s0 + r3;
				else s0 = s0 + s[i];
	}
	return s0;
}

void DrawLSystem(string s, float w)
{	int n = s.length();
	for (int i=0; i<n;i++)
	{ switch (s[i])
		{     case 'F':
			DrawLine(0, 0, 0, w, 0, 0, 1, 1, 1);
			glTranslated(w, 0, 0);
			break;
			case '+':  	glRotated(60, 0, 0, 1);
			break;
			case '-':    	glRotated(60, 0, 0, -1);
			break;
		}
	}
}

void DrawLSystem2(string s, float w)
{
	glVertex2f(0, 0);
	int n = s.length();
	for (int i=0; i<n;i++)
	{
			switch (s[i])
			{
				case 'F':
					DrawLine(0, 0, 0, w, 0, 0, 1, 1, 1);
					glTranslated(w, 0, 0);
				break;
				case '+':
					glRotated(90, 0, 0, 1);
				break;
				case '-':
					glRotated(90, 0, 0, -1);
				break;
			}

	}
}

void DrawLSystem3(string s, float w)
{
	glVertex2f(0, 0);
	int n = s.length();
	for (int i=0; i<n;i++)
	{
			switch (s[i])
			{
				case 'F':
					DrawLine(0, 0, 0, w, 0, 0, 1, 1, 1);
					glTranslated(w, 0, 0);
				break;
				case '+':
					glRotated(20, 0, 0, 1);
				break;
				case '-':
					glRotated(20, 0, 0, -1);
				break;
				case '[':
					glPushMatrix();
				break;
				case ']':
					glPopMatrix();
				break;
			}

	}
}

void DrawLSystem4(string s, float w)
{
	glVertex2f(0, 0);
	int n = s.length();
	float r = 0.1f; 
	for (int i=0; i<n;i++)
	{
			switch (s[i])
			{
				case 'F':
					glLineWidth((1-r)*10);
					DrawLine(0, 0, 0, w, 0, 0, r, r, r);
					glTranslated(w, 0, 0);
				break;
				case '+':
					glRotated(rand()/ 100 %20, 0, 0, 1);
				break;
				case '-':
					glRotated((rand()/ 100 %25), 0, 0, -1);
				break;
				case '[':
					glPushMatrix();
				break;
				case ']':
					glPopMatrix();
				break;
				case '1':
					r/=1.25;
				break;
				case '2':
					r*=1.25;
				break;
			}

	}
}

void FractalLS::Init()
{
	for (int i = 1; i <= value; i++)
		{
			LS = UseRule(LS, stroka1, rule1, stroka2, rule2, stroka3, rule3); // применение правила
			size = size /3;
		}

}

void FractalLS::Draw()
{
	switch (drawtype)
	{
		case 1:
			DrawLSystem(LS, size);
		break;
		case 2:
			DrawLSystem2(LS, size);
		break;
		case 3:
			glRotated(90, 0, 0, 1);
			DrawLSystem3(LS, size);
		break;
		case 4:
			glRotated(90, 0, 0, 1);
			DrawLSystem4(LS, size);
		break;
	default:
		break;
	}
	
}
