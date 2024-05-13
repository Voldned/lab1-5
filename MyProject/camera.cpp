#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

#include "camera.h"

#define mButton_Left 0
#define mButton_Right 1
#define mButton_Middle 2

Camera::Camera()
{
	Init();
}

void Camera::Init()
{
#ifdef CAMERA0
	anglez = 0; anglex = 0; rz = 10;
	ex = 0; ey = 0; ez = 0;
	ax = 0; ay = 0; az = 0;
#endif
#ifdef CAMERA1
	eX = 0; eY = 40; eZ = -80;
	aX = 0; aY = 0; aZ = 0;
	moveK = 0.02f;
#endif
	ismousedown = false;
	buttondown = -1;
	ctrlPressed = false;
	enabled = true;
}

#ifdef CAMERA0
void Camera::PressKeyA(void) // шаг по кругу
{
	anglez += 0.1;
}

void Camera::PressKeyD(void) // шаг по кругу
{
	anglez -= 0.1;
}

void Camera::PressKeyW(void) // шаг вперед
{
	rz -= 1;
}

void Camera::PressKeyS(void)// шаг назад
{
	rz += 1;
}

void Camera::PressKeyQ(void) // шаг вверх
{
	ey += 1;
}

void Camera::PressKeyE(void) // шаг вниз
{
	ey -= 1;
}
#endif
#ifdef CAMERA1
void Camera::PressKeyD(void) // шаг вправо
{
	float dx, dz;
	float a = 3.14f / 2;
	float cx_ = float((aX - eX)*cos(a) - (aZ - eZ)*sin(a));
	float cz_ = float((aX - eX)*sin(a) + (aZ - eZ)*cos(a));
	dx = cx_*moveK;
	dz = cz_*moveK;

	eX = eX + dx;   aX = aX + dx;
	eZ = eZ + dz;   aZ = aZ + dz;
}

void Camera::PressKeyA(void) // шаг влево
{
	float dx, dz;
	float a = -3.14f / 2;
	float cx_ = float((aX - eX)*cos(a) - (aZ - eZ)*sin(a));
	float cz_ = float((aX - eX)*sin(a) + (aZ - eZ)*cos(a));
	dx = cx_*moveK;
	dz = cz_*moveK;

	eX = eX + dx;   aX = aX + dx;
	eZ = eZ + dz;   aZ = aZ + dz;
}

void Camera::PressKeyW(void) // шаг вперед
{
	float dx, dz, dy;
	dx = (aX - eX)*moveK;
	dy = (aY - eY)*moveK;
	dz = (aZ - eZ)*moveK;

	eX = eX + dx;	aX = aX + dx;
	
	eY = eY + dy;	aY = aY + dy;

	eZ = eZ + dz;	aZ = aZ + dz;
}

void Camera::PressKeyS(void) // шаг назад
{
	float dx, dz, dy;
	dx = -(aX - eX)*moveK;
	dy = -(aY - eY)*moveK;
	dz = -(aZ - eZ)*moveK;

	eX = eX + dx;	aX = aX + dx;

	eY = eY + dy;	aY = aY + dy;

	eZ = eZ + dz;	aZ = aZ + dz;
}

void Camera::PressKeyE(void) // смотреть направо
{
	float a = 3.14f / 180;
	float cx_ = float((aX - eX)*cos(a) - (aZ - eZ)*sin(a));
	float cz_ = float((aX - eX)*sin(a) + (aZ - eZ)*cos(a));
	aX = cx_ + eX;  aZ = cz_ + eZ;
}
void Camera::PressKeyQ(void)// смотреть налево
{
	float a = -3.14f / 180;
	float cx_ = float((aX - eX)*cos(a) - (aZ - eZ)*sin(a));
	float cz_ = float((aX - eX)*sin(a) + (aZ - eZ)*cos(a));
	aX = cx_ + eX;   aZ = cz_ + eZ;
}

void Camera::PressKeyR(void) // смотреть вверх
{
	float a = 3.14f / 180;
	float cy_ = float((aY - eY)*cos(a) - (aZ - eZ)*sin(a));
	float cz_ = float((aY - eY)*sin(a) + (aZ - eZ)*cos(a));
	aY = cy_ + eY;  aZ = cz_ + eZ;
}
void Camera::PressKeyT(void)// смотреть вниз
{
	float a = -3.14f / 180;
	float cy_ = float((aY - eY)*cos(a) - (aZ - eZ)*sin(a));
	float cz_ = float((aY - eY)*sin(a) + (aZ - eZ)*cos(a));
	aY = cy_ + eY;   aZ = cz_ + eZ;
}

void Camera::PressKeyF(void)// смотреть вниз
{
	aY = 0;   aZ = 0;	aX = 0;
}

void Camera::PressKeyZ(void)// шаг вверх
{
	eY += 1; aY += 1;
}

void Camera::PressKeyX(void) // шаг вниз
{
	eY -= 1; aY -= 1;
}
#endif


void Camera::KeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case 'w': PressKeyW();
		break;
	case 's': PressKeyS();
		break;
	case 'a': PressKeyA();
		break;
	case 'd': PressKeyD();
		break;
	case 'q': PressKeyQ();
		break;
	case 'e': PressKeyE();
		break;
	case 'z': PressKeyZ();
		break;
	case 'x': PressKeyX();
		break;
	case 'r': PressKeyR();
		break;
	case 't': PressKeyT();
		break;
	default:
		break;
	}

}

void Camera::SetEnabled(bool value)
{
	enabled = value;
}

void Camera::SetCamera()
{
	if (ismousedown)
	{
		if (buttondown == mButton_Middle)
			PressKeyW();
		if (buttondown == mButton_Right)
			PressKeyS();
	}

#ifdef CAMERA0
	ex = rz*sin(anglez);
	ez = rz*cos(anglez);
	gluLookAt(ex, ey, ez, ax, ay, az, 0, 1, 0);
#endif
#ifdef CAMERA1
	gluLookAt(eX, eY, eZ, aX, aY, aZ, 0, 1, 0);
#endif
}

void Camera::MouseDown(float x, float y, int button)
{
	if (!enabled) return;
	ismousedown = true;
	buttondown = button;
	mousedownpos.x = x;
	mousedownpos.y = y;
}

void Camera::MouseMove(float x, float y)
{
	if (ismousedown)
	{
		if (buttondown == mButton_Left)
		{
			if (x<mousedownpos.x)
				PressKeyQ();
			if (x>mousedownpos.x)
				PressKeyE();
			if (y<mousedownpos.y)
				PressKeyR();
			if (y>mousedownpos.y)
				PressKeyT();
			mousedownpos.x = x;
			mousedownpos.y = y;
		}
	}
}

void Camera::MouseUp(float x, float y)
{
	ismousedown = false;
	buttondown = -1;
}

