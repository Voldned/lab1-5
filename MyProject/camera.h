#pragma once

#include "types.h"
#include <string>

#define CAMERA1

class Camera
{
private: 
#ifdef CAMERA0
	float anglez, anglex, rz;
	float ex, ey, ez;
	float ax, ay, az;
#endif
#ifdef CAMERA1
	float eX, eY, eZ;
	float aX, aY, aZ;
	float moveK;
#endif

#ifdef CAMERA0
	void PressKeyA(void); // шаг по кругу
	void PressKeyD(void); // шаг по кругу
	void PressKeyW(void); // шаг вперед
	void PressKeyS(void); // шаг назад
	void PressKeyQ(void); // шаг вверх
	void PressKeyE(void); // шаг вниз
#endif
#ifdef CAMERA1
	void PressKeyD(void); // шаг вправо
	void PressKeyA(void); // шаг влево
	void PressKeyW(void); // шаг вперед
	void PressKeyS(void); // шаг назад
	void PressKeyE(void); // смотреть направо
	void PressKeyQ(void); // смотреть налево
	void PressKeyZ(void); // шаг вверх
	void PressKeyX(void); // шаг вниз
	void PressKeyR(void); // смотреть вверх
	void PressKeyT(void); // смотреть вниз
	void PressKeyF(void); // смотреть вни
#endif
	bool ismousedown;
	bool ctrlPressed;
	int buttondown;
	VERTEX mousedownpos;
	bool enabled;
public:
	Camera();
	void Init();
	void KeyDown(int i);
	void SetEnabled(bool value);
	void SetCamera();
	void MouseDown(float x, float y, int button);
	void MouseMove(float x, float y);
	void MouseUp(float x, float y);
};