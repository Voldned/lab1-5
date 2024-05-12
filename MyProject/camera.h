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
	void PressKeyA(void); // ��� �� �����
	void PressKeyD(void); // ��� �� �����
	void PressKeyW(void); // ��� ������
	void PressKeyS(void); // ��� �����
	void PressKeyQ(void); // ��� �����
	void PressKeyE(void); // ��� ����
#endif
#ifdef CAMERA1
	void PressKeyD(void); // ��� ������
	void PressKeyA(void); // ��� �����
	void PressKeyW(void); // ��� ������
	void PressKeyS(void); // ��� �����
	void PressKeyE(void); // �������� �������
	void PressKeyQ(void); // �������� ������
	void PressKeyZ(void); // ��� �����
	void PressKeyX(void); // ��� ����
	void PressKeyR(void); // �������� �����
	void PressKeyT(void); // �������� ����
	void PressKeyF(void); // �������� ���
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