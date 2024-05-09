#pragma once

#include <windows.h>
#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "scene.h"
#include "camera.h"

using namespace System::Windows::Forms;

ref class OpenGL : public System::Windows::Forms::NativeWindow
{
	private:
		HDC m_hDC;
		HGLRC m_hglrc;
	public:
		SCENE * scene;
		Camera * camera;
		int width, height;
		OpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight);
		
		System::Void Render(System::Void);
		~OpenGL(System::Void);
		virtual void WndProc(Message %m) override;
		GLint MySetPixelFormat(HDC hdc);
		bool InitGL(GLvoid);
		GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
};

