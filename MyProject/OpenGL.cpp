#include <windows.h>
#include <Windowsx.h>
#include <stdio.h>
#include <stdarg.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "OpenGL.h"
#include "glaux.h"


#pragma comment (lib,"opengl32.lib") 
#pragma comment (lib,"glu32.lib")
#pragma comment (lib, "glaux.lib")
#pragma comment(lib,"kernel32.lib")
#pragma comment (lib, "advapi32.lib")

#pragma comment(lib, "legacy_stdio_definitions.lib")

using namespace System::Windows::Forms;

	OpenGL::OpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
	{
		CreateParams^ cp = gcnew CreateParams;

		// Set the position on the form
		cp->X = 0;
		cp->Y = 0;
		cp->Height = iHeight;
		cp->Width = iWidth;

		// Specify the form as the parent.
		cp->Parent = parentForm->Handle;

		// Create as a child of the specified parent and make OpenGL compliant (no clipping)
		cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

		// Create the actual window
		this->CreateHandle(cp);

		m_hDC = GetDC((HWND)this->Handle.ToPointer());

		if (m_hDC)
		{
			MySetPixelFormat(m_hDC);
			ReSizeGLScene(iWidth, iHeight);
			InitGL();
		}
		width = iWidth;  
		height = iHeight;
		scene = new SCENE(width, height);
		camera = new Camera();
	}

	System::Void OpenGL::Render(System::Void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
		glLoadIdentity();									// Reset the current modelview matrix
		/*glTranslated(0, 0, -10);

		glRotated(GetTickCount()/100.f, 0, 0, 1);
	glColor3d(1, 1, 1);
    glBegin(GL_QUADS);
		glVertex3d(-1, -1, 0);
		glVertex3d(-1, 1, 0);
		glVertex3d(1, 1, 0);
		glVertex3d(1, -1, 0);
    glEnd();*/
		if (camera != nullptr)	camera->SetCamera();
		if (scene != nullptr)	scene->Draw();

		SwapBuffers(m_hDC);
	}

	
	OpenGL::~OpenGL(System::Void)
	{
		this->DestroyHandle();
	}

	GLint OpenGL::MySetPixelFormat(HDC hdc)
	{
		static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
		{
			sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
			1,											// Version Number
			PFD_DRAW_TO_WINDOW |						// Format Must Support Window
			PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
			PFD_DOUBLEBUFFER,							// Must Support Double Buffering
			PFD_TYPE_RGBA,								// Request An RGBA Format
			16,										// Select Our Color Depth
			0, 0, 0, 0, 0, 0,							// Color Bits Ignored
			0,											// No Alpha Buffer
			0,											// Shift Bit Ignored
			0,											// No Accumulation Buffer
			0, 0, 0, 0,									// Accumulation Bits Ignored
			16,											// 16Bit Z-Buffer (Depth Buffer)  
			0,											// No Stencil Buffer
			0,											// No Auxiliary Buffer
			PFD_MAIN_PLANE,								// Main Drawing Layer
			0,											// Reserved
			0, 0, 0										// Layer Masks Ignored
		};

		GLint  iPixelFormat;

		// get the device context's best, available pixel format match 
		if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
		{
			MessageBox::Show("ChoosePixelFormat Failed");
			return 0;
		}

		// make that match the device context's current pixel format 
		if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
		{
			MessageBox::Show("SetPixelFormat Failed");
			return 0;
		}

		if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
		{
			MessageBox::Show("wglCreateContext Failed");
			return 0;
		}

		if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}
	
		return 1;
	}

	bool OpenGL::InitGL(GLvoid)										// All setup for opengl goes here
	{
		glShadeModel(GL_SMOOTH);							// Enable smooth shading
		glClearColor(0.1f, 0.2f, 0.3f, 0.5f);				// Black background
		glClearDepth(1.0f);									// Depth buffer setup
		glEnable(GL_DEPTH_TEST);							// Enables depth testing
		glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
		return TRUE;										// Initialisation went ok
	}

	

	GLvoid OpenGL::ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
	{
		if (height == 0)										// Prevent A Divide By Zero By
		{
			height = 1;										// Making Height Equal One
		}

		glViewport(0, 0, width, height);						// Reset The Current Viewport

		glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
		glLoadIdentity();									// Reset The Projection Matrix

		gluPerspective(45.0, (GLfloat)width / height, 1.0, 10000.0);
		// Calculate The Aspect Ratio Of The Window
															//gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

		glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
		glLoadIdentity();									// Reset The Modelview Matrix
	}

	void OpenGL::WndProc(Message %m)
	{
		// Listen for operating system messages
		int x, y;

		switch (m.Msg)
		{
			case WM_LBUTTONDOWN:
			x = GET_X_LPARAM((int)m.LParam);
			y = GET_Y_LPARAM((int)m.LParam);
			camera->MouseDown(x, y, 0);
			scene->MouseDown(x-width/2, height/2-y, 0);
			break;

		case WM_RBUTTONDOWN:
			x = GET_X_LPARAM((int)m.LParam);
			y = GET_Y_LPARAM((int)m.LParam);
			camera->MouseDown(x, y, 1);
			scene->MouseDown(x-width/2, height/2-y, 1);
			break;

		case WM_MBUTTONDOWN:
			x = GET_X_LPARAM((int)m.LParam);
			y = GET_Y_LPARAM((int)m.LParam);
			camera->MouseDown(x, y, 2);
			scene->MouseDown(x-width/2, height/2-y, 2);
			break;

		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
			x = GET_X_LPARAM((int)m.LParam);
			y = GET_Y_LPARAM((int)m.LParam);
			camera->MouseUp(x, y);
			scene->MouseUp(x-width/2, height/2-y);
			break;

		case WM_MOUSEMOVE:
			x = GET_X_LPARAM((int)m.LParam);
			y = GET_Y_LPARAM((int)m.LParam);
			camera->MouseMove(x, y);
			scene->MouseMove(x-width/2, height/2-y);
			break;
			
		case WM_KEYDOWN:
			camera->KeyDown((int)m.LParam);
			break;
		}
		NativeWindow::WndProc(m);
	}