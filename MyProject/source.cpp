#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glaux.h"
#include "drawfunctions.h"
#include "types.h"
#include "scene.h"

using namespace std;
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib, "glaux.lib")
#pragma comment(lib,"kernel32.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

SCENE * scene;

#define CAMERA1

#ifdef CAMERA0
	float anglez = 0, anglex = 0, rz = 10;
	float ex = 0, ey = 0, ez = 0;
	float ax = 0, ay = 0, az = 0;
#endif
#ifdef CAMERA1
	double eX = 0, eY = 1, eZ = 1;
	double aX = 0, aY = 0, aZ = -10;
	float moveK = 0.02; 
#endif


void CALLBACK resize(int width,int height)
{
   InitOpenGL(width, height);
}

void CALLBACK display(void)
{
 glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 glLoadIdentity();

 gluLookAt( 0,0,5, 0,0,0, 0,1,0 );

#ifdef CAMERA0
 ex = rz*sin(anglez);
 ez = rz*cos(anglez);
 gluLookAt(ex, ey, ez, ax, ay, az, 0, 1, 0);
#endif
#ifdef CAMERA1
 gluLookAt(eX, eY, eZ, aX, aY, aZ, 0, 1, 0);
#endif

 if (scene!=nullptr)
	scene->Draw();

 //Draw();
 
 auxSwapBuffers();
}

#ifdef CAMERA0
void CALLBACK PressKeyA(void) // шаг по кругу
{	   anglez+=0.1;    }

void CALLBACK PressKeyD(void) // шаг по кругу
{	  anglez-=0.1;     }

void CALLBACK PressKeyW(void) // шаг вперед
{		rz-=1;       }

void CALLBACK PressKeyS(void)// шаг назад
{ 		rz+=1;       }

void CALLBACK PressKeyQ(void) // шаг вверх
{		ey+=1;       }

void CALLBACK PressKeyE(void) // шаг вниз
{		ey-=1;       }
#endif
#ifdef CAMERA1
void CALLBACK PressKeyD(void) // шаг вправо
{
	float dx, dz;
    float a = 3.14/2;
    float cx_ = (aX-eX)*cos(a) - (aZ-eZ)*sin(a);
    float cz_ = (aX-eX)*sin(a) + (aZ-eZ)*cos(a);
    dx = cx_*moveK;
    dz = cz_*moveK;

   eX = eX + dx;   aX = aX + dx;   
   eZ = eZ + dz;   aZ = aZ + dz;   
}

void CALLBACK PressKeyA (void) // шаг влево
{
    float dx, dz;
    float a = -3.14/2;
    float cx_ = (aX-eX)*cos(a) - (aZ-eZ)*sin(a);
    float cz_ = (aX-eX)*sin(a) + (aZ-eZ)*cos(a);
    dx = cx_*moveK;
    dz = cz_*moveK;

    eX = eX + dx;   aX = aX + dx;   
    eZ = eZ + dz;   aZ = aZ + dz;   
}

void CALLBACK PressKeyW(void) // шаг вперед
{
    float dx, dz;
    dx = (aX - eX)*moveK;
    dz = (aZ - eZ)*moveK;

    eX = eX + dx;   
    aX = aX + dx;   
    eZ = eZ + dz;   
    aZ = aZ + dz;   
}

void CALLBACK PressKeyS(void) // шаг назад
{
    float dx, dz;
    dx =  - (aX - eX)*moveK;
    dz = - (aZ - eZ)*moveK;

    eX = eX + dx;   
    aX = aX + dx;   
    eZ = eZ + dz;   
    aZ = aZ + dz;   
}

void CALLBACK PressKeyE(void) // шаг направо
{
    float a = 3.14/180*2;
    float cx_ = (aX-eX)*cos(a) - (aZ-eZ)*sin(a);
    float cz_ = (aX-eX)*sin(a) + (aZ-eZ)*cos(a);
    aX = cx_ + eX;  aZ = cz_ + eZ;
}
void CALLBACK PressKeyQ(void)// шаг налево
{
    float a = -3.14/180*2;
    float cx_ = (aX-eX)*cos(a) - (aZ-eZ)*sin(a);
    float cz_ = (aX-eX)*sin(a) + (aZ-eZ)*cos(a);
    aX = cx_ + eX;   aZ = cz_ + eZ;
}

void CALLBACK PressKeyZ(void)// шаг вверх
{		eY+=1; aY+=1;      }

void CALLBACK PressKeyX(void)
{		eY-=1; aY-=1;      }// шаг вниз
#endif

void CALLBACK MouseDown(AUX_EVENTREC *event)
{
	float x = (event->data[AUX_MOUSEX]-300)/40.0;
	float y = (300-event->data[AUX_MOUSEY])/40.0;
	MouseDown(x, y);
}

void main()
{
    auxInitPosition( 0, 0, 600, 600);
    auxInitDisplayMode( AUX_RGB | AUX_DEPTH | AUX_DOUBLE );
  

#if defined(CAMERA0) || defined(CAMERA1)
	auxKeyFunc(AUX_w, PressKeyW);
    auxKeyFunc(AUX_s, PressKeyS);
    auxKeyFunc(AUX_a, PressKeyA);
    auxKeyFunc(AUX_d, PressKeyD);
	auxKeyFunc(AUX_q, PressKeyQ);
	auxKeyFunc(AUX_e, PressKeyE);
#endif

#ifdef CAMERA1
	auxKeyFunc(AUX_z, PressKeyZ);
	auxKeyFunc(AUX_x, PressKeyX);
#endif

	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, MouseDown);

    auxInitWindow( "Glaux Template" );
	scene = new SCENE();
    auxIdleFunc(display);
    auxReshapeFunc(resize);
    auxMainLoop(display);
}
