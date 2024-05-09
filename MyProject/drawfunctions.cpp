#include <math.h>
#include <iostream>
#include <stdio.h>
#include <io.h>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "drawfunctions.h"
#include "glaux.h"

//#include "scene.h"
float xfrom = 0;
float xto = 10;
float v = 5;
int startTime = 0;

float vx = 5;
float yfrom = 0;
float yto = 10;
float vy = 3;
int startTimex = 0;
int startTimey = 0;

float vr = 90;
float rx = 10;
float ry = 5;

typedef double (*pf)(double x);

bool createMas = false;
float **masF, **masFF;
int masSize;

GLuint	texture[3];

//struct mans {
//     float x, y;
//     bool run;
//     float vx, vy;
//     float tox, toy;
//} man;

/*
struct Bone
 {
     int   parent_index;  // индекс родителя
     float angle; // угол поворота 
 	  float length; // длина 
};

// количество элементов
	const int nBones = 22; 	

	// объявление массива
	Bone bones[nBones];

	Bone getBone(int parent_index, float angle, float length) 
{
	Bone B;
	B.parent_index = parent_index;
	B.angle = angle;
	B.length = length;
	return B;
}
	void InitBones()
{
	bones[0] = getBone(-1, 0, 0);
	bones[1] = getBone(0, 0, 2);
	bones[2] = getBone(1, -80, 2);
	bones[3] = getBone(2, -10, 2);
	bones[4] = getBone(3, 10, 1);
	bones[5] = getBone(3, 0, 1);	
	bones[6] = getBone(3, -10, 1);	

	bones[7] = getBone(0, -180, 2);
	bones[8] = getBone(7, 80, 2);
	bones[9] = getBone(8, 10, 2);
	bones[10] = getBone(9, 10, 1);
	bones[11] = getBone(9, 0, 1);	
	bones[12] = getBone(9, -10, 1);	

	bones[13] = getBone(0, 90, 2);
	bones[14] = getBone(0, -90, 5);
	bones[15] = getBone(14, 30, 3);
	bones[16] = getBone(15, -25, 4);
	bones[17] = getBone(14, -30, 3);
	bones[18] = getBone(17, 25, 4);

	bones[19] = getBone(13, -30, 2);
	bones[20] = getBone(13, 30, 2);
	bones[21] = getBone(19, 120, 2);
}

	void DrawBone(int curBone)
{
	float x, y;
	x = cos(bones[curBone].angle/180*3.14f) * bones[curBone].length;
	y = sin(bones[curBone].angle/180*3.14f) * bones[curBone].length;

	DrawLine(0, 0, 0, x, y, 0, 1, 1, 1);

	glPushMatrix();
	glTranslated(x, y, 0);
	glRotated(bones[curBone].angle, 0, 0, 1);

	int i;
	for (i = curBone + 1; i <= nBones; i++)
		if (bones[i].parent_index == curBone)
				DrawBone(i);
	glPopMatrix();
}

void DrawBones()
{
bones[2].angle = -80 + 10 * sin(GetTickCount()/1000.0f);
float sin_t = sin(GetTickCount()/1000.0f);
float cos_t = cos(GetTickCount()/1000.0f);

bones[15].angle =  40 * sin_t + 5;
bones[16].angle =  10 * sin_t - 15;
bones[17].angle =  -40 * sin_t + 5;
bones[18].angle =  -10 * sin_t - 15;

DrawBone(0);
}
*/

/*
GLuint box;
GLvoid BuildLists()     //создаем список отображения
{
	LoadBMP(&texture[0], "wall1.bmp"); 
    LoadBMP(&texture[1], "wall2.bmp");
	GLuint  quad; 
	box=glGenLists(2);      //создаем два списка
	quad = box + 1;
	glNewList(quad,GL_COMPILE);    // Новый откомпилированный список
	glBegin(GL_QUADS); 
		glTexCoord2f(0, 0);
		glVertex3f(0, 0, 0); // Верхний правый угол текстуры 
		glTexCoord2f(0, 1);
		glVertex3f(0, 1, 0);   // Верхний левый угол текстуры 
		glTexCoord2f(1, 1);
		glVertex3f(1, 1, 0);    // Нижний левый угол текстуры 
		glTexCoord2f(1, 0);
		glVertex3f(1, 0, 0);   // Нижний правый угол текстуры 
		glEnd();                        // Закончили рисование четырехугольников
	glEndList(); // Закончили создание списка
glNewList(box,GL_COMPILE);    // Новый откомпилированный список box
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glEnable (GL_TEXTURE_2D);
		glPushMatrix();
			glTranslated(-0.5, -0.5, -0.5);
			glCallList(quad);
			glTranslated(0, 0, 1);
			glCallList(quad);
			glRotated(90, 0, 1, 0);
			glCallList(quad);
			glTranslated(0, 0, 1);
			glCallList(quad);
			glTranslated(0, 1, -1);
			glRotated(90, 1, 0, 0);
			glBindTexture(GL_TEXTURE_2D, texture[1]);
			glCallList(quad);
			glTranslated(0, 0, 1);
			glCallList(quad);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glEndList(); // Закончили создание списка box
}

void DrawLists()
{
glPushMatrix();
	int n = 5;
	int m = 5;
	for (int j = -n; j<=n; j++)
		for (int i = -m; i<=m; i++)
		{
			glPushMatrix();
				glTranslated(i, j, 0);
				glCallList(box); 
			glPopMatrix();
		}
	glPopMatrix();
}

void DrawLists2()
{
	glPushMatrix();
	int n = 5;	int m = 5;
	int mas[6][3] = {{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1}};
	for (int j = 0; j<=n; j++)
	{		for (int i = -m; i<=m; i++)
		      	for (int k = -m; k<=m; k++)
       		{	glPushMatrix();
						glTranslated(i, j, k);
						glColor3d(mas[m][0],mas[m][1],mas[m][2]);
						glCallList(box); 
					glPopMatrix();
				}
		m--;
	}
	glPopMatrix();
}
*/


GLuint  base;      // База списка отображения для фонта
GLuint  basev;      // База списка отображения для фонта
GLYPHMETRICSFLOAT gmf[256];  // Массив с информацией о нашем шрифте

GLvoid BuildFont(GLvoid)  // Построение нашего растрового шрифта
{  HFONT  font;            // Идентификатор фонта
  base = glGenLists(256);  // Выделим место для 256 символов 
  font = CreateFont( 16,        // Высота фонта
                                  8,        // Ширина фонта
                                  0,        // Угол отношения
                                  0,        // Угол наклона
                   FW_BOLD,        // Ширина шрифта
                         FALSE,        // Курсив
                         FALSE,        // Подчеркивание
                         FALSE,        // Перечеркивание
           ANSI_CHARSET,      // Идентификатор набора символов
          OUT_TT_PRECIS,       // Точность вывода
CLIP_DEFAULT_PRECIS,   // Точность отсечения
ANTIALIASED_QUALITY,    // Качество вывода
FF_DONTCARE|DEFAULT_PITCH,  // Семейство и шаг
                                    "Arial");      // Имя шрифта

     SelectObject(auxGetHDC(), font);        // Выбрать шрифт, 
   wglUseFontBitmaps(auxGetHDC(), 0, 256, base); // Построить 256 символов начиная c 0

}
GLvoid KillFont(GLvoid) 
{
   glDeleteLists(base, 256);
   glDeleteLists(basev, 256);
}

GLvoid glPrint(float x, float y, float z, char text[256]) 
{
	 glPushMatrix();
	 glTranslated(x, y, z);
	 glRasterPos2f(0, 0); // Позиционирование текста на экране

	glPushAttrib(GL_LIST_BIT);  // Протолкнуть биты списка отображения
	glListBase(base);          // Задать базу символов в 0

	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text); // Текст списками отображения, количество списков, тип индексов, индексы списков

	glPopAttrib(); // Возврат битов списка отображения 	 
	glPopMatrix();
}


GLvoid BuildVERTEXFont(GLvoid)           // Строим растровый шрифт
{  HFONT  font;                     // Идентификатор шрифта Windows
  basev = glGenLists(256);          // массив для 256 букв
  font = CreateFont(   
            100,          // высота шрифта
              0,            // ширина знакоместа
              0,            //Угол перехода
              0,            //Угол направления
  FW_BOLD,              //Ширина шрифта
              FALSE,        // Курсив
              FALSE,        // Подчеркивание
              FALSE,        // Перечеркивание
              ANSI_CHARSET,       //Идентификатор кодировки
              OUT_TT_PRECIS,       // Точность вывода
              CLIP_DEFAULT_PRECIS,       //Точность отсечения
              ANTIALIASED_QUALITY,// Качество вывода
              FF_DONTCARE|DEFAULT_PITCH, // Семейство и Шаг
              "Courier New");          // Имя шрифта
SelectObject(auxGetHDC(), font);       //Выбрать шрифт, созданный нами

wglUseFontOutlines( auxGetHDC(),         // Выбрать текущий контекст устройства (DC)
               0,            // Стартовый символ
               256,          // Количество создаваемых списков отображения
               basev,         // Стартовое значение списка отображения
                    0.0f,       //Отклонение от настоящего контура
                   0.5f,       //Толщина шрифта по оси Z
				WGL_FONT_LINES,
				//Использовать линии, или полигоны(WGL_FONT_POLYGONS)
                    gmf);       //буфер адреса для данных списка отображения
}

GLvoid glPrintV(float x, float y, float z, char text[256], float ax, float ay, float az, float r, float g, float b)   
{
  float         length=0;     // Переменная для нахождения

  glPushMatrix();

  for (unsigned int loop=0;loop<(strlen(text));loop++)//Цикл поиска размера строки
   {
     length+=gmf[(unsigned char)text[loop]].gmfCellIncX;
    // Увеличение размера на ширину символа
  }

   glTranslated(x, y, z);
  glRotatef(ax,1.0f,0.0f,0.0f);     // Поворот по оси X
  glRotatef(ay,0.0f,1.0f,0.0f);     // Поворот по оси Y
  glRotatef(az,0.0f,0.0f,1.0f);     // Поворот по оси Z
  glTranslated(-length/2, 0, 0);
  
  glColor3f(r, g, b);
  glRasterPos2f(0, 0); // Позиционирование текста на экране

  glPushAttrib(GL_LIST_BIT);      // Протолкнуть биты списка отображения ( НОВОЕ )

  glListBase(basev);       
  glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);// Текст списками отображения(НОВОЕ)

  glPopAttrib(); // Возврат битов списка отображения ( НОВОЕ )
  glPopMatrix();
}

int fps;
int frameCount=0;
int lastTimeCalcfps;

void CalcFPS()
{   frameCount++;    //  количество кадров отрисовки
	int t = GetTickCount();  // текущее время
	// если прошло больше секунды, то пересчитываем fps
	if (t - lastTimeCalcfps>1000)
	{
		fps = frameCount;
		frameCount = 0;
		lastTimeCalcfps = t;
	}
}

void DrawFPS()
{
	glColor3d(1, 1, 1);
   char buffer[20];
   char *p;  // указатель на результат
   p = _itoa(int(fps), buffer, 10);
   glPrint(0, 0, -10, "FPS"); 
   glPrint(0.5, 0, -10, buffer); 
}


void DrawKub_(float x, float y, float z, float w, float r, float g, float b, float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);
		if (solid) auxSolidCube(w);
		else auxWireCube(w);
		glPopMatrix();
}

void DrawBox_(float x, float y, float z, float w, float h, float d, float r, float g, float b, float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);
		if (solid) auxSolidBox(w, h, d);
		else auxWireBox(w, h, d);
		glPopMatrix();
}



void DrawCylinder_(float x, float y, float z, float radius, float h, float r, float g, float b, float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);
		if (solid) auxSolidCylinder(radius, h);
		else auxWireCylinder(radius, h);
		glPopMatrix();
}
void DrawCone_(float x, float y, float z, float radius, float h, float r, float g, float b, float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);
		if (solid) auxSolidCone(radius, h);
		else auxWireCone(radius, h);
		glPopMatrix();
}

void DrawIcosahedron_(float x, float y, float z, float w, float r, float g, float b, float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);
//		glEnable(GL_TEXTURE_GEN_S);
// glEnable(GL_TEXTURE_GEN_T);
//	glEnable (GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texture[0]);
	if (solid) auxSolidIcosahedron(w);
		else auxWireIcosahedron(w);
		glPopMatrix();
 // glDisable (GL_TEXTURE_2D);
// glDisable(GL_TEXTURE_GEN_S);
 //1glDisable(GL_TEXTURE_GEN_T);

}
void DrawIcosahedron_(VERTEX p, float w, COLOR color, VERTEX angle, bool solid)
{
	DrawIcosahedron_(p.x, p.y, p.z, w, color.r, color.g, color.b, angle.x, angle.y, angle.z, solid);
}

void DrawTeapot_(float x, float y, float z, float w, float r, float g, float b, float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);
		if (solid) auxSolidTeapot(w);
		else auxWireTeapot(w);
		glPopMatrix();
}

void DrawTorus_(float x, float y, float z, float r1, float r2, float r, float g, float b, float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);
		if (solid) auxSolidTorus(r1, r2);
		else auxWireTorus(r1, r2);
		glPopMatrix();
}

void DrawSphere_(float x, float y, float z, float radius, float r, float g, float b,  float ax, float ay, float az, bool solid)
{
		glPushMatrix();
		glTranslated(x, y, z);
		glRotated(ax, 1, 0, 0);
		glRotated(ay, 0, 1, 0);
		glRotated(az, 0, 0, 1);
		glColor3d(r, g, b);

	    if (solid) auxSolidSphere(radius);
		else auxWireSphere(radius);
		glPopMatrix();
}

void DrawSphere_(VERTEX p, float radius, COLOR color,  VERTEX angle, bool solid)
{
	DrawSphere_(p.x, p.y, p.z, radius, color.r, color.g, color.b, angle.x, angle.y, angle.z, solid);
}

void InitOpenGL(int width, int height)
{
   glViewport(0,0,width,height);
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   gluPerspective(45.0, (GLfloat)width / height, 1.0, 10000.0);
   //glFrustum(-1.0,1.0,-1.0,1.0,1.5,100.0);

   glMatrixMode( GL_MODELVIEW );

   glEnable(GL_DEPTH_TEST); 
   glClearColor(0.2f, 0.3f, 0.4f, 0.0);

   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
   glEnable(GL_POINT_SMOOTH);

   //InitBones();

   //drawhouse
 // LoadHouseTextures(); 
   
   //drawsity
   //LoadBMP(&texture[0], "dom2.bmp"); 
   //LoadBMP(&texture[1], "Sky.bmp");
   //LoadBMP(&texture[2], "Grass.bmp");
  
   //drawman
   //InitMan();

  // LoadBMP(&texture[0], "iron.bmp");

//   BuildLists();
  // BuildFont();
   //BuildVERTEXFont();
}
 
void DrawPoint(float x, float y, float z, float r, float g, float b)
{
    glColor3d(r, g, b);
	glBegin(GL_POINTS);
	    glVertex3d(x, y, z);
    glEnd();
}

void DrawPoint(float x, float y, float z, float r, float g, float b, float size)
{
	glPointSize(size);
    glColor3d(r, g, b);
	glBegin(GL_POINTS);
	    glVertex3d(x, y, z);
    glEnd();
}

void DrawPoint(float x, float y, float size)
{
	glPointSize(size);
    glColor3d(1, 1, 1);
	glBegin(GL_POINTS);
	    glVertex2d(x, y);
    glEnd();
}

void DrawPoint(VERTEX v, COLOR color, float size)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(size);
    glColor3d(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	    glVertex3d(v.x, v.y, v.z);
    glEnd();
	glDisable(GL_BLEND);
}

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1, float r2, float g2, float b2)
{
	glBegin(GL_LINES);
    glColor3d(r1, g1, b1);
    glVertex3d(x1, y1, z1);
    glColor3d(r2, g2, b2);
    glVertex3d(x2, y2, z2);
    glEnd();
}

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1)
{
	DrawLine(x1, y1, z1, x2, y2, z2, r1, g1, b1, r1, g1, b1); 
}

void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1, float r2, float g2, float b2)
{
	DrawLine(x1, y1, 0, x2, y2, 0, r1, g1, b1, r2, g2, b2); 
}

void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1)
{
	DrawLine(x1, y1, 0, x2, y2, 0, r1, g1, b1, r1, g1, b1); 
}

void DrawLine(float x1, float y1, float x2, float y2)
{
	DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1, 1, 1, 1); 
}

void DrawLine(float x1, float y1, float x2, float y2, float size)
{
	glLineWidth(size);
	DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1, 1, 1, 1); 
}

void DrawLine(VERTEX v1, VERTEX v2, COLOR c1, COLOR c2)
{
	DrawLine(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, c1.r, c1.g, c1.b, c2.r, c2.g, c2.b); 
}

void DrawLine(VERTEX v1, VERTEX v2, COLOR c)
{
	DrawLine(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, c.r, c.g, c.b, c.r, c.g, c.b); 
}

void DrawLine(VERTEX v1, VERTEX v2, COLOR c, float size)
{
	glLineWidth(size);
	DrawLine(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, c.r, c.g, c.b, c.r, c.g, c.b); 
}

void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3)
{
	glBegin(GL_TRIANGLES);
    glColor3d(r1, g1, b1);
    glVertex3d(x1, y1, z1);
    glColor3d(r2, g2, b2);
    glVertex3d(x2, y2, z2);
    glColor3d(r3, g3, b3);
    glVertex3d(x3, y3, z3);
    glEnd();
}

void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1)
{
	DrawTriangle(x1, y1, z1, x2, y2, z2, x3, y3, z3, r1, g1, b1, r1, g1, b1, r1, g1, b1);
}

void DrawTriangle(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c)
{
	DrawTriangle(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, c.r, c.g, c.b);
}
void DrawTriangle(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c1, COLOR c2, COLOR c3)
{
	DrawTriangle(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, c1.r, c1.g, c1.b, c2.r, c2.g, c2.b, c3.r, c3.g, c3.b);
}

void DrawTriangleT(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, int tindex)
{
	DrawTriangleT(v1, v2, v3, c, c, c, tv1, tv2, tv3, tindex);
}

void DrawTriangleT(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c, COLOR c2, COLOR c3, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, int tindex)
{
	glEnable (GL_TEXTURE_2D);
	glColor3f(c.r, c.g, c.b);
	glBindTexture(GL_TEXTURE_2D, tindex);
    glBegin(GL_TRIANGLES);    
		glTexCoord2f(tv1.x, tv1.y);
		glVertex3d(v1.x, v1.y, v1.z);
		glColor3f(c2.r, c2.g, c2.b);
		glTexCoord2f(tv2.x, tv2.y);
		glVertex3d(v2.x, v2.y, v2.z);
		glColor3f(c3.r, c3.g, c3.b);
		glTexCoord2f(tv3.x, tv3.y);
		glVertex3d(v3.x, v3.y, v3.z);
    glEnd();

	glDisable(GL_TEXTURE_2D);
}

void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3, float r4, float g4, float b4)
{
	glBegin(GL_QUADS);
	glColor3d(r1, g1, b1);
    glVertex3d(x1, y1, z1);
    glColor3d(r2, g2, b2);
    glVertex3d(x2, y2, z2);
    glColor3d(r3, g3, b3);
    glVertex3d(x3, y3, z3);
	glColor3d(r4, g4, b4);
    glVertex3d(x4, y4, z4);
    glEnd();
}

void DrawQuadNormal(VERTEX v1,VERTEX v2, VERTEX v3, VERTEX v4, COLOR c1, COLOR c2, COLOR c3, COLOR c4)
{
	VERTEX n1, n2, n3, n4;
	glBegin(GL_QUADS);
	glColor3d(c1.r, c1.g, c1.b);
	n1 = Normal(v1, v4, v2);
	glNormal3f(n1.x, n1.y, n1.z);
    glVertex3d(v1.x, v1.y, v1.z);

	glColor3d(c2.r, c2.g, c2.b);
	n2 = Normal(v2, v1, v3);
	glNormal3f(n2.x, n2.y, n2.z);
    glVertex3d(v2.x, v2.y, v2.z);

	glColor3d(c3.r, c3.g, c3.b);
	n3 = Normal(v3, v2, v4);
	glNormal3f(n3.x, n3.y, n3.z);
    glVertex3d(v3.x, v3.y, v3.z);

	glColor3d(c4.r, c4.g, c4.b);
	n4 = Normal(v4, v3, v1);
	glNormal3f(n4.x, n4.y, n4.z);
    glVertex3d(v4.x, v4.y, v4.z);
    glEnd(); 

	//glBegin(GL_LINES);
    //glVertex3d(v1.x, v1.y, v1.z);
	//glVertex3d(v1.x+n1.x/3, v1.y+n1.y/3, v1.z+n1.z/3);

	//glVertex3d(v2.x, v2.y, v2.z);
	//glVertex3d(v2.x+n2.x/3, v2.y+n2.y/3, v2.z+n2.z/3);

	//glVertex3d(v3.x, v3.y, v3.z);
	//glVertex3d(v3.x+n3.x/3, v3.y+n3.y/3, v3.z+n3.z/3);

	//glVertex3d(v4.x, v4.y, v4.z);
	//glVertex3d(v4.x+n4.x/3, v4.y+n4.y/3, v4.z+n4.z/3);
	//glEnd();
}

void DrawQuadNormalT(VERTEX v1,VERTEX v2, VERTEX v3, VERTEX v4, COLOR c, GLuint texture)
{
	glEnable (GL_TEXTURE_2D);
	glColor3f(1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, texture);

	VERTEX n1, n2, n3, n4;
	glBegin(GL_QUADS);
	glColor3d(c.r, c.g, c.b);
	n1 = Normal(v1, v4, v2);
	glNormal3f(n1.x, n1.y, n1.z);
	glTexCoord2f(0, 0);
    glVertex3d(v1.x, v1.y, v1.z);

	n2 = Normal(v2, v1, v3);
	glNormal3f(n2.x, n2.y, n2.z);
	glTexCoord2f(0, 1);
    glVertex3d(v2.x, v2.y, v2.z);

	n3 = Normal(v3, v2, v4);
	glNormal3f(n3.x, n3.y, n3.z);
	glTexCoord2f(1, 1);
    glVertex3d(v3.x, v3.y, v3.z);

	n4 = Normal(v4, v3, v1);
	glNormal3f(n4.x, n4.y, n4.z);
	glTexCoord2f(1, 0);
    glVertex3d(v4.x, v4.y, v4.z);
    glEnd();

	glDisable(GL_TEXTURE_2D);
}

void DrawQuadNormal(VERTEX v1,VERTEX v2, VERTEX v3, VERTEX v4, COLOR c)
{
	DrawQuadNormal(v1,v2, v3, v4, c, c, c, c);
}

void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1)
{
	DrawQuad(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, r1, g1, b1, r1, g1, b1, r1, g1, b1, r1, g1, b1);
}

void DrawQuad(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, COLOR c)
{
	DrawQuad(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, v4.x, v4.y, v4.z, c.r, c.g, c.b, c.r, c.g, c.b, c.r, c.g, c.b, c.r, c.g, c.b);
}

void DrawQuad(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, COLOR c1, COLOR c2, COLOR c3, COLOR c4)
{
	DrawQuad(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, v4.x, v4.y, v4.z, c1.r, c1.g, c1.b, c2.r, c2.g, c2.b, c3.r, c3.g, c3.b, c4.r, c4.g, c4.b);
}

void DrawRect(float x1, float y1, float z1, float w, float h, float r1, float g1, float b1)
{
	DrawQuad(x1-w/2, y1-h/2, z1, 
             x1+w/2, y1-h/2, z1, 
             x1+w/2, y1+h/2, z1, 
             x1-w/2, y1+h/2, z1, 
			 r1, g1, b1);
}

void DrawRect(float x1, float y1, float w, float h, float r1, float g1, float b1)
{
	DrawQuad(x1-w/2, y1-h/2, 0, 
             x1+w/2, y1-h/2, 0, 
             x1+w/2, y1+h/2, 0, 
             x1-w/2, y1+h/2, 0, 
			 r1, g1, b1);
}

void DrawRect(float x1, float y1, float w, float h)
{
	DrawQuad(x1-w/2, y1-h/2, 0, 
             x1+w/2, y1-h/2, 0, 
             x1+w/2, y1+h/2, 0, 
             x1-w/2, y1+h/2, 0, 
			 1, 1, 1);
}

void DrawPolygon(float **mas, int n, float r1, float g1, float b1)
{
  	glColor3d(r1, g1, b1);
	glBegin(GL_POLYGON);
	for (int i=0; i<n; i++)
		glVertex3d(mas[i][0], mas[i][1], mas[i][2]);
    glEnd();
}

void DrawCircle(float x, float y, float z, float radius, float r1, float g1, float b1)
{ // передаются координаты центра, радиус и цвет окружности
   glColor3d(r1, g1, b1);
   int n = 60;
   glBegin(GL_LINE_LOOP);
      for (int i = 0; i<n; i++)
          glVertex3d(x+radius*sin(i*2*3.14/n),
                            y+radius*cos(i*2*3.14/n), z);
    glEnd();
}

void DrawCircle(VERTEX p, float radius, COLOR c)
{ // передаются координаты центра, радиус и цвет окружности
	DrawCircle(p.x, p.y, p.z, radius, c.r, c.g, c.b);
}

void DrawRound(float x, float y, float z, float radius, float r1, float g1, float b1)
{ // передаются координаты центра, радиус и цвет круга
   glColor3d(r1, g1, b1);
   int n = 60;
   glBegin(GL_TRIANGLE_FAN);
      for (int i = 0; i<n; i++)
          glVertex3d(x+radius*sin(i*2*3.14/n),
                            y+radius*cos(i*2*3.14/n), z);
    glEnd();
}

void DrawRound(float x, float y, float radius)
{ // передаются координаты центра, радиус
  DrawRound(x, y, 0, radius, 1, 1, 1);
}


void DrawRound(VERTEX p, float radius, COLOR c)
{ // передаются координаты центра, радиус и цвет круга
	DrawRound(p.x, p.y, p.z, radius, c.r, c.g, c.b);
}

void DrawLines()
{
  float dx = 1;
  for (int i = -10; i<=10; i++)
	DrawLine(i*dx, -10, 0, i*dx, 10, 0, 1, 1, 1);
}

void Drawpoints()
{
	DrawLine(0, -10, 0, 0, 10, 0, 1, 1, 1);
	DrawLine(-10, 0, 0, 10, 0, 0, 1, 1, 1);

	glPointSize (20);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor3d(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,3.0);
	glVertex2f(4.0,3.0);
	glVertex2f(6.0,1.5);
	glVertex2f(4.0,0.0);
	glEnd(); 

}

void DrawTriangles()
{
	DrawTriangle(get_VERTEX(-5, 0), get_VERTEX(1, 2), get_VERTEX(4, -5),
		get_COLOR(1, 0, 0), get_COLOR(0, 1, 0), get_COLOR(0, 0, 1));
}

void DrawGrid(float r, float g, float b)
{
	float dx = 1;
	for (int i = -10; i<=10; i++)
		DrawLine(i*dx, -10, 0, i*dx, 10, 0, r, g, b);
}

void DrawOneKube()
{
    glLineWidth(2);
	glTranslated(0, 0, 10); DrawGrid(1, 1, 1);	glRotated(90, 0, 0, 1);  DrawGrid(1, 1, 1);

	glPushMatrix();
	glTranslated(0, 0, -20);
	DrawGrid(1, 0, 0);	glRotated(90, 0, 0, 1);        DrawGrid(1, 0, 0);
	
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 0, -10);
	glRotated(90, 0, 1, 0);	DrawGrid(0, 1, 0); glRotated(90, 0, 0, 1);	DrawGrid(0, 1, 0);

	glTranslated(0, 0, 20);
	DrawGrid(0, 0, 1);	glRotated(90, 0, 0, 1);    DrawGrid(0, 0, 1);
	glPopMatrix();

	glTranslated(0, 10, -10);
	glRotated(90, 1, 0, 0);	DrawGrid(1, 1, 0); glRotated(90, 0, 0, 1);	DrawGrid(1, 1, 0);

	glTranslated(0, 0, 20);
	DrawGrid(0, 1, 1);	glRotated(90, 0, 0, 1);    DrawGrid(0, 1, 1);

}


void DrawKube()
{
    glTranslated(0, 0, -50 );
   glRotated(GetTickCount()/10.f, 0.1, 0.5, 0.3);

   // glRotated(40.f, 0.1, 0.5, 0.3);
  
     DrawOneKube();
}


void DrawMoving1()
{
    glTranslated(0, 0, -30 );
 
	DrawRect(0-1.2f, 0, 0.4f, 10);
	DrawRect(10+1.2f, 0, 0.4f, 10);
	float x = 0, y = 0;

	if (startTime==0) startTime = GetTickCount();

	float dt = (GetTickCount() - startTime)/1000.f;

	x = xfrom + v*dt;
	//if (x>xto) startTime = GetTickCount();

	if (((x>xto) &&(xto>xfrom)) || ((x<xto) &&(xto<xfrom)))
		{
			v = -v;
			float xtemp = xto;
			xto = xfrom;
			xfrom = xtemp;

			startTime = GetTickCount();
	}
	DrawRound(x, y, 1);
}

void DrawMoving2()
{

	glTranslated(0, 0, -30 );
 
    DrawRect(0-1.2f, 5, 0.4f, 12.8f);
	DrawRect(10+1.2f, 5, 0.4f, 12.8f);

    DrawRect(5, 0-1.2f, 12, 0.4f);
	DrawRect(5, 10+1.2f, 12, 0.4f);

	float x = 0;	float y = 0;

	if (startTimex==0) startTimex = GetTickCount();
	if (startTimey==0) startTimey = GetTickCount();

	float dtx = (GetTickCount() - startTimex)/1000.f;
	float dty = (GetTickCount() - startTimey)/1000.f;

	x = xfrom + vx*dtx;	
    y = yfrom + vy*dty;

	if (((x>xto) &&(xto>xfrom)) || ((x<xto) &&(xto<xfrom)))
		{
			vx = -vx;
			float xtemp = xto;
			xto = xfrom;
			xfrom = xtemp;

			startTimex = GetTickCount();
	}
	if (((y>yto) &&(yto>yfrom)) || ((y<yto) &&(yto<yfrom)))
		{
			vy = -vy;
			float ytemp = yto;
			yto = yfrom;
			yfrom = ytemp;

			startTimey = GetTickCount();
		}

	DrawRound(x, y, 1);

}

void DrawMoving3()
{
	  glTranslated(0, 0, -30 );

      float dt = (GetTickCount() - startTime)/1000.f;

	  float x = rx * sin(dt*vr/60.f);
	  float y = ry * cos(dt*vr/60.f);

	  DrawRound(x, y, 0.5);
}

void DrawMoving4()
{
	  glTranslated(0, 0, -30 );

      float dt = (GetTickCount() - startTime)/1000.f;

      float x = rx*sin(dt*vx/0.7f);
	  float y = ry*cos(dt*vy/1.2f);


	  DrawRound(x, y, 0.5);
}

void DrawMoving5()
{
	 glTranslated(0, 0, -60 );
     float scale = (sin(GetTickCount()/1000.f) + 2)/2.f;
	 
 	  glScaled(scale, scale, 1);
      glRotated(GetTickCount()/10.f, 0.1, 0.2, 1);

	 DrawOneKube();
}

void DrawCamera1()
{
	DrawOneKube();
}

void DrawOs()
{
  glPushMatrix();
  float dx = 2; 
  DrawLine(-10*dx, 0, 10*dx, 0);
  DrawLine(0, -10*dx, 0, 10*dx);
  for (int i=-10; i<=10; i++)
  {
     DrawLine(i*dx, 0.1f*dx, i*dx, -0.1f*dx);
     DrawLine(0.1f*dx, i*dx, -0.1f*dx, i*dx);
  }
  glPopMatrix();
}

float f(float x)
{
	return (sin(2*x));
}

void DrawFunc()
{
	float x, x1 = -10, x2 = 10;
	int n = 100;
	float dx = (x2 - x1)/n;
	DrawOs();

	glBegin(GL_POINTS);             // рисование точек
//	glBegin(GL_LINE_STRIP);     //  рисование линий 
		glColor3f(1, 0, 0);
 		for (x=x1; x<=x2; x +=dx)
			{
			glVertex3f(x, f(x), 0);
			}
	glEnd();
}
void GenerateMasByFunc(float **mas, float x1, float x2, float dx)
{
	for (int i = 0; i<masSize; i++)
		{
			mas[0][i] = x1 + dx * i; 
			mas[1][i] = f(x1 + dx * i); 
		}
}

void DrawFuncMas(float **mas, float xScale, float yScale, float r, float g, float b)
{
		glBegin(GL_LINE_STRIP);
		glColor3f(r, g, b);
		for (int i = 0; i<masSize; i++)
		{
			glVertex3f(mas[0][i] * xScale, mas[1][i] * yScale, 0);
		}
	glEnd();
}

void DrawFuncMasExample()
{
	float xScale = 1, yScale = 1, x1 = -10, x2 = 10, dx = 0.1f; masSize = int((x2 - x1)/dx);
	if (!createMas) 
	{
		masF = new float *[2];
		masF[0] = new float [masSize];
		masF[1] = new float [masSize];
		GenerateMasByFunc(masF, x1, x2, dx);
		createMas = true;
	}
	DrawOs();
	DrawFuncMas(masF, xScale, yScale, 1, 0, 0);
}

void DeleteMas()
{
	if (createMas) 
		{
			delete masF[0];
			delete masF[1];
			delete masF;
		}
}

void CalcDFuncMas(float **mas, float **dmas, float dx)
{
	for (int i = 0; i<masSize; i++)
	{
		dmas[0][i] = mas[0][i];
		if (i<masSize-1)
			dmas[1][i] = (mas[1][i+1]-mas[1][i])/dx;
		else
			dmas[1][i] = (mas[1][i]-mas[1][i-1])/dx;
	}
}

void DrawFuncMasExample2()
{
	float xScale = 1, yScale = 1, x1 = -10, x2 = 10, 
    dx = 0.1f; 
    masSize = int((x2 - x1)/dx);
	if (!createMas) 
	{
			masF = new float *[2];
			masF[0] = new float [masSize];
			masF[1] = new float [masSize];

			GenerateMasByFunc(masF, x1, x2, dx);
		createMas = true;

		masFF = new float *[2];
		masFF[0] = new float [masSize];
		masFF[1] = new float [masSize];

		CalcDFuncMas(masF, masFF, dx);
	}
	DrawOs();

	DrawFuncMas(masF, xScale, yScale, 1, 0, 0);
	DrawFuncMas(masFF, xScale, yScale, 0, 1, 0);
}

void DrawFuncParam(int type)
{
	float t1 = 0, t2 = 2*3.14f, dt = 0.1f;
	float t = t1, x, y;  float xScale = 3, yScale = 3;
	DrawOs();
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 1);
	float r1 = 100, r2 = 25, o1 = 1, o2 = 500;
	
	while (t<t2) 
	{
		switch (type)
		{
		case 1: x = sin(2*t);   y = cos(3*t);
			break;
		case 2:	x=sin(3*t), y=cos(5*t);
			break;
		case 3:	x=sin(2*t)*cos(2*t);y = 2*cos(2*t)*sin(4*t);
			break;
		case 4:	x = 16*sin(t)*sin(t)*sin(t)/10;y = (13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t))/10;
			break;
		case 5:	
			x = (r1*(1+cos(7*t))*cos(o1*t)+r2*cos(o2*t))/100;y = (r1*(1+cos(7*t))*sin(o1*t)+r2*sin(o2*t))/100;
			break;
		default:
			x = t;   y = t;
			break;
		}
		
		glVertex3f(x * xScale, y * yScale, 0);
		t +=dt;
	}
	glEnd();
}

void DrawFuncParam2()
{	float t1=0, t2=2*3.14f, dt=0.001f, r1=100, r2=25, o1=1, o2=500;
	float t = t1, x, y, xScale = 3, yScale = 3; glBegin(GL_LINE_STRIP);
	while (t<t2) 
	{	glColor3d(1, 1, 1);
		if ( (t>t2/14) & (t<3*t2/14)) glColor3d(1, 0, 0);
		if ( (t>3*t2/14) & (t<5*t2/14)) glColor3d(0, 1, 0);
		if ( (t>5*t2/14) & (t<7*t2/14)) glColor3d(0, 0, 0);
		if ( (t>7*t2/14) & (t<9*t2/14)) glColor3d(1, 1, 0);
		if ( (t>9*t2/14) & (t<11*t2/14)) glColor3d(0, 1, 1);
		if ( (t>11*t2/14) & (t<13*t2/14)) glColor3d(1, 0, 1);
		x = r1*(1+cos(7*t))*cos(o1*t)+r2*cos(o2*t);
		y = r1*(1+cos(7*t))*sin(o1*t)+r2*sin(o2*t);
		glVertex3f(x * xScale, y * yScale, 0);
		t +=dt;	}
	glEnd();
}

float f2(float x, float y)
{
	return  2*(sin(x)+cos(y));
	//return (x*x+y*y)/10; 
}

void DrawFunc3D(int type)
{
	float x, x1 = -10, x2 = 10;
	float y, y1 = -10, y2 = 10;
	int n = 100;
	float dx = (x2 - x1)/n;
	float dy = (y2 - y1)/n;
	glPushMatrix();
	DrawOs();
	glRotated(90, 0, 1, 0);
	DrawOs();
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPointSize(5);
	glLineWidth(1);
	switch (type)
	{
	case 1:
	glBegin(GL_POINTS);             // рисование точек
	 for (x=x1; x<=x2; x +=dx)
			for (y=y1; y<=y2; y +=dy)
				{
					glVertex3f(x, f2(x,y), y);
				}
		glEnd();
		break;
	case 2:
	glColor3f(0, 1, 0);
	for (x=x1; x<=x2; x +=dx)
	{
	glBegin(GL_LINE_STRIP);     //  рисование линий 
		for (y=y1; y<=y2; y +=dy)
				glVertex3f(x, f2(x,y), y);
	glEnd();
	}
	for (y=y1; y<=y2; y +=dy)
	{
		glBegin(GL_LINE_STRIP);     //  рисование линий 
	 for (x=x1; x<=x2; x +=dx)
			glVertex3f(x, f2(x,y), y);
		glEnd();
	}
	break;
	case 3:
	for (x=x1; x<=x2; x +=dx)
		for (y=y1; y<=y2; y +=dy)
		{
		DrawQuad(get_VERTEX(x, f2(x,y), y), get_VERTEX(x+dx, f2(x+dx,y), y),
			get_VERTEX(x+dx, f2(x+dx,y+dy), y+dy), get_VERTEX(x, f2(x,y+dy), y+dy), 
			get_COLOR(0, 0, 1));
		}
	
	break;
	default:
		break;
	}

}

void DrawTriangleT(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3,
      float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, int tindex)
{
glEnable (GL_TEXTURE_2D);
glColor3f(1.0f,1.0f,1.0f);
glBindTexture(GL_TEXTURE_2D, tindex);
  glBegin(GL_TRIANGLES);    
    glTexCoord2f(tx1, ty1);  glVertex3d(x1, y1, z1);
    glTexCoord2f(tx2, ty2);  glVertex3d(x2, y2, z2);
    glTexCoord2f(tx3, ty3);  glVertex3d(x3, y3, z3);
  glEnd();
glDisable(GL_TEXTURE_2D);
}

void DrawQuadT(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, float tx4, float ty4, int tindex)
{
glEnable (GL_TEXTURE_2D);
glColor3f(1.0f,1.0f,1.0f);
glBindTexture(GL_TEXTURE_2D, tindex);
  glBegin(GL_QUADS);    
    glTexCoord2f(tx1, ty1);    glVertex3d(x1, y1, z1);
    glTexCoord2f(tx2, ty2);    glVertex3d(x2, y2, z2);
    glTexCoord2f(tx3, ty3);    glVertex3d(x3, y3, z3);
    glTexCoord2f(tx4, ty4);    glVertex3d(x4, y4, z4);
  glEnd();
glDisable(GL_TEXTURE_2D);
}

void DrawQuadT(float x1, float y1, float tx1, float ty1, float x2, float y2, float tx2, float ty2,  float x3, float y3, float tx3, float ty3,  float x4, float y4, float tx4, float ty4)
{    glEnable (GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glEnable (GL_ALPHA_TEST);
	glAlphaFunc (GL_GREATER, 0.1f);
	glEnable (GL_BLEND);
	glBegin(GL_QUADS);
		glTexCoord2f(tx1, ty1);  glVertex2f(x1, y1);
		glTexCoord2f(tx2, ty2);  glVertex2f(x2, y2);
		glTexCoord2f(tx3, ty3);  glVertex2f(x3, y3);
		glTexCoord2f(tx4, ty4);  glVertex2f(x4, y4);
	glEnd();
	glDisable(GL_TEXTURE_2D);	glDisable(GL_BLEND);
}

void DrawQuadT(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, TEXTURE_VERTEX tv4, COLOR color, int tindex)
{
	glEnable(GL_TEXTURE_2D);
	glColor3f(color.r, color.g, color.b);
	glBindTexture(GL_TEXTURE_2D, tindex);
	glBegin(GL_QUADS);
	glTexCoord2f(tv1.x, tv1.y);    glVertex3d(v1.x, v1.y, v1.z);
	glTexCoord2f(tv2.x, tv2.y);    glVertex3d(v2.x, v2.y, v2.z);
	glTexCoord2f(tv3.x, tv3.y);    glVertex3d(v3.x, v3.y, v3.z);
	glTexCoord2f(tv4.x, tv4.y);    glVertex3d(v4.x, v4.y, v4.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void DrawQuadT(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, COLOR color, int tindex)
{
	DrawQuadT(v1, v2, v3, v4, get_TEXTURE_VERTEX(0, 0), get_TEXTURE_VERTEX(0, 1), get_TEXTURE_VERTEX(1, 1), get_TEXTURE_VERTEX(1, 0), color, tindex);
}
GLvoid LoadHouseTextures(void)
{
     AUX_RGBImageRec *texture1;
	texture1 = auxDIBImageLoad("dom2.bmp");
    glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
}

void DrawWall1()
{
	float Ax = 6/512.0, Ay = (512 - 96)/512.0,
	Bx = 6/512.0, By = (512 - 41) /512.0,
	Cx = 157/512.0, Cy = (512 - 41) /512.0,
	Dx = 157/512.0, Dy = (512 - 96) /512.0,
	Ex = 1/512.0, Ey = (512 - 40) /512.0,
	Fx = 48/512.0, Fy = (512 - 1) /512.0,
	Gx = 117/512.0, Gy = (512 - 1) /512.0,
	Hx = 164/512.0, Hy = (512 - 40) /512.0;
	float x=-1, y=0, z=1;

	glBegin(GL_QUADS);    
	    glTexCoord2f(Ax, Ay);		glVertex3f(x, y, z);  
		glTexCoord2f(Bx, By);		glVertex3f(x, y + 1, z);  
		glTexCoord2f(Cx, Cy);		glVertex3f(x + 2, y + 1, z);  
		glTexCoord2f(Dx, Dy);		glVertex3f(x + 2, y, z);  
    glEnd();
    glBegin(GL_QUADS);    
       	glTexCoord2f(Ex, Ey); 		glVertex3f(x, y + 1, z);  
		glTexCoord2f(Fx, Fy);		glVertex3f(x + 0.5f, y + 1.5f, z-1);  
		glTexCoord2f(Gx, Gy);		glVertex3f(x + 1.5f, y + 1.5f, z-1);  
		glTexCoord2f(Hx, Hy);		glVertex3f(x + 2, y + 1, z);  
    glEnd(); 
}

void DrawWall2()
{
	float Ax = 170/512.0, Ay = (512 - 96)/512.0,
	Bx = 170/512.0, By = (512 - 41) /512.0,
	Cx = 320/512.0, Cy = (512 - 41) /512.0,
	Dx = 320/512.0, Dy = (512 - 96) /512.0,
	Ex = 165/512.0, Ey = (512 - 40) /512.0,
	Fx = 211/512.0, Fy = (512 - 1) /512.0,
	Gx = 280/512.0, Gy = (512 - 1) /512.0,
	Hx = 324/512.0, Hy = (512 - 40) /512.0;
	
	float x=-1, y=0, z=1;
    glBegin(GL_QUADS);    
	    glTexCoord2f(Ax, Ay);
		glVertex3f(x, y, z-2);  
		glTexCoord2f(Bx, By);
		glVertex3f(x, y + 1, z-2);  
		glTexCoord2f(Cx, Cy);
		glVertex3f(x + 2, y + 1, z-2);  
		glTexCoord2f(Dx, Dy);
		glVertex3f(x + 2, y, z-2);  
    glEnd();

	glBegin(GL_QUADS);    
    	glTexCoord2f(Ex, Ey);
		glVertex3f(x, y + 1, z-2);  
		glTexCoord2f(Fx, Fy);
		glVertex3f(x + 0.5f, y + 1.5f, z-1);  
		glTexCoord2f(Gx, Gy);
		glVertex3f(x + 1.5f, y + 1.5f, z-1);  
		glTexCoord2f(Hx, Hy);
		glVertex3f(x + 2, y + 1, z-2);  
    glEnd(); 
}

void DrawWall3()
{
	float Ax = 6/512.0, Ay = (512 - 195)/512.0,
	Bx = 6/512.0, By = (512 - 138) /512.0,
	Cx = 163/512.0, Cy = (512 - 138) /512.0,
	Dx = 163/512.0, Dy = (512 - 195) /512.0,
	Ex = 1/512.0, Ey = (512 - 137) /512.0,
	Fx = 83/512.0, Fy = (512 - 98) /512.0,
	Gx = 162/512.0, Gy = (512 - 138) /512.0;
	
	float x=-1, y=0, z=1;
    glBegin(GL_QUADS);    
	    glTexCoord2f(Ax, Ay);
		glVertex3f(x, y, z);  
		glTexCoord2f(Bx, By);
		glVertex3f(x, y+1, z);  
		glTexCoord2f(Cx, Cy);
		glVertex3f(x, y+1, z-2);  
		glTexCoord2f(Dx, Dy);
		glVertex3f(x, y, z-2);  
    glEnd();

	glBegin(GL_TRIANGLES);    
    	glTexCoord2f(Ex, Ey);
		glVertex3f(x, y+1, z);  
		glTexCoord2f(Fx, Fy);
		glVertex3f(x + 0.5f, y + 1.5f, z-1);  
		glTexCoord2f(Gx, Gy);
		glVertex3f(x, y+1, z-2);  
    glEnd(); 

}

void DrawWall4()
{
	float Ax = 6/512.0f, Ay = (512 - 195)/512.0f,
	Bx = 6/512.0f, By = (512 - 138) /512.0f,
	Cx = 163/512.0f, Cy = (512 - 138) /512.0f,
	Dx = 163/512.0f, Dy = (512 - 195) /512.0f,
	Ex = 1/512.0f, Ey = (512 - 137) /512.0f,
	Fx = 83/512.0f, Fy = (512 - 98) /512.0f,
	Gx = 162/512.0f, Gy = (512 - 138) /512.0f;
	float x=-1, y=0, z=1;

    glBegin(GL_QUADS);    
	    glTexCoord2f(Ax, Ay);
		glVertex3f(x+2, y, z);  
		glTexCoord2f(Bx, By);
		glVertex3f(x+2, y+1, z);  
		glTexCoord2f(Cx, Cy);
		glVertex3f(x+2, y+1, z-2);  
		glTexCoord2f(Dx, Dy);
		glVertex3f(x+2, y, z-2);  
    glEnd();

	glBegin(GL_TRIANGLES);    
    	glTexCoord2f(Ex, Ey);
		glVertex3f(x+2, y+1, z);  
		glTexCoord2f(Fx, Fy);
		glVertex3f(x + 1.5f, y + 1.5f, z-1);  
		glTexCoord2f(Gx, Gy);
		glVertex3f(x+2, y+1, z-2);  
    glEnd(); 
}

void DrawFloor()
{
	float x=-1, y=0, z=1;
	glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);    
	    glTexCoord2f(0, 0);
		glVertex3f(x, y, z);  
		glTexCoord2f(0, 1);
		glVertex3f(x, y, z-2);  
		glTexCoord2f(1, 1);
		glVertex3f(x+2, y, z-2);  
		glTexCoord2f(1, 0);
		glVertex3f(x+2, y, z);  
    glEnd();
}

void DrawHome()
{

	glEnable (GL_TEXTURE_2D);
	glColor3f(1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	DrawWall1();
	DrawWall2();
	DrawWall3();
	DrawWall4();
	DrawFloor();

	glDisable(GL_TEXTURE_2D);

}

void DrawSity()
{
	glScaled(0.1,0.1,0.1);
	DrawQuadT(-100, 0, -100,   100, 0, -100,   100, 0, 100,    -100, 0, 100,   0, 0, 0, 1, 1, 1, 1, 0, 2);
	DrawQuadT(-100, 0, -100,   -100, 100, -100,   100, 100, -100,    100, 0, -100,    0, 0, 0, 1, 1, 1, 1, 0, 1);
	DrawQuadT(-100, 0, 100,   -100, 100, 100,   100, 100, 100,    100, 0, 100,    1, 0, 1, 1, 0, 1, 0, 0, 1);
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		DrawQuadT(-100, 0, -100,   -100, 100, -100,   100, 100, -100,    100, 0, -100,    1, 0, 1, 1, 0, 1, 0, 0, 1);
	DrawQuadT(-100, 0, 100,   -100, 100, 100,   100, 100, 100,    100, 0, 100,    0, 0, 0, 1, 1, 1, 1, 0, 1);
	glPopMatrix();

	for (int i=0; i<10; i++)
	for (int j=0; j<10; j++)
	{
		glPushMatrix();
		glTranslated(i*5, 0, j*5);
		DrawHome();
		glPopMatrix();
	}
}

void LoadBMP(GLuint *texture, char *filename)
{
	if (access(filename, 0) != -1)
	{
		AUX_RGBImageRec *txt;
		txt = auxDIBImageLoad(filename);
		glGenTextures(1, texture);
		glBindTexture(GL_TEXTURE_2D, *texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, txt->sizeX, txt->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, txt->data);
		delete txt;
	}
}

void LoadTGA(GLuint *texture, char *filename)	
// Loads A TGA File Into Memory
{    
	GLubyte		TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};
// Uncompressed TGA Header
	GLubyte		TGAcompare[12];					
// Used To Compare TGA Header
	GLubyte		header[6];				
// First 6 Useful Bytes From The Header
	GLuint		bytesPerPixel; 
// Holds Number Of Bytes Per Pixel Used In The TGA File
	GLuint		imageSize;	
// Used To Store The Image Size When Setting Aside Ram
GLuint		temp;						// Temporary Variable
	GLuint		type=GL_RGBA;		
 	// Set The Default GL Mode To RBGA (32 BPP)

	GLubyte	*imageData;						
	// Image Data (Up To 32 Bits)
	GLuint	bpp;							       
	// Image Color Depth In Bits Per Pixel.
	GLuint	width;							// Image Width
	GLuint	height;                                // Image height
	FILE *file = fopen(filename, "rb");				
	// Open The TGA File
	fread(TGAcompare,1,sizeof(TGAcompare),file);
	fread(header,1,sizeof(header),file);
	width  = header[1] * 256 + header[0];                          
	// Determine The TGA Width	
	height = header[3] * 256 + header[2];				
	// Determine The TGA Height	
	bpp	= header[4];				  
	// Grab The TGA's Bits Per Pixel (24 or 32)
	bytesPerPixel	= bpp/8;		
	// Divide By 8 To Get The Bytes Per Pixel
	imageSize		= width*height*bytesPerPixel;	// Calculate Memory
	imageData=(GLubyte *)malloc(imageSize);	
	// Reserve Memory To Hold The TGA Data
	fread(imageData, 1, imageSize, file);
	for(GLuint i=0; i<int(imageSize); i+=bytesPerPixel)
	// Loop Through The Image Data
	{	 // Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)
		temp=imageData[i];		
		// Temporarily Store The Value At Image Data 'i'
		imageData[i] = imageData[i + 2];
		// Set The 1st Byte To The Value Of The 3rd Byte
		imageData[i + 2] = temp;	
		// Set The 3rd Byte To The Value In 'temp' (1st Byte Value)
	}

	fclose (file);												
	// Close The File
	glGenTextures(1, texture);						
	// Generate OpenGL texture IDs
	glBindTexture(GL_TEXTURE_2D, *texture);				
	// Bind Our Texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
	if (bpp==24)										// Was The TGA 24 Bits
	{
		type=GL_RGB;											// If So Set The 'type' To GL_RGB
	}

	glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, imageData);
}

void InitMan()
{
//man.x = 0;  man.y = 0;
//man.run = false;
//man.vx = 0;  man.vy = 0;
LoadTGA(&texture[0], "man.tga");
}

void DrawFrame(int t)
{ 
float w = 5;  float h = 6; int col = (t%6);  int row = (t/6);
float tx = 1/6.f*col,  ty = 1/5.0f*(5-row);
DrawQuadT(-w, h, tx, ty+1/5.0f, 
           w, h, tx+1/6.0f, ty+1/5.0f, 
           w, -h, tx+1/6.0f, ty, 
           -w, -h, tx, ty);
//if (man.vx>=0)  DrawQuadT(man.x-w, man.y+h, tx, ty+1/5.0, 
//                      man.x+w, man.y+h, tx+1/6.0, ty+1/5.0, 
//                      man.x+w, man.y-h, tx+1/6.0, ty, 
//                      man.x-w, man.y-h, tx, ty);
//else    DrawQuadT(man.x-w, man.y+h, tx+1/6.0, ty+1/5.0, 
//                        man.x+w, man.y+h, tx, ty+1/5.0, 
//                        man.x+w, man.y-h, tx, ty, 
//                        man.x-w, man.y-h, tx+1/6.0, ty);
}

void DrawMan()
{
int t = GetTickCount()/50%30;
//if (man.run) 
//{   man.x +=man.vx;  man.y +=man.vy;
//
//   float d = sqrt((man.x-man.tox)*(man.x-man.tox) + (man.y-man.toy)*(man.y-man.toy));
//   if (d<0.1)
//    {  man.run = false;  man.vx = 0;  man.vy = 0;  }
//}
DrawFrame(t);
//glTranslated(2, 0, 0);
//DrawFrame(t/2);
}

void MouseDown(float x, float y)
{
 //man.vx = (x-man.x)/2000;
 //man.vy = (y-man.y)/2000;
 //man.tox = x;
 //man.toy = y;
 //man.run = true;
}

void DrawIronMan()
{
	DrawQuadT(-2.f, 0.f, 0.4f, 0.6f, 
		      -2.f, 5.f, 0.4f, 0.8f, 
			   2.f, 5.f, 0.6f, 0.8f, 
			   2.f, 0.f, 0.6f, 0.6f);

	DrawQuadT(-3.f, -5.f, 0.3f, 0.2f, 
		      -3.f, 0.f, 0.3f, 0.6f, 
			   3.f, 0.f, 0.7f, 0.6f, 
			   3.f, -5.f, 0.7f, 0.2f);
	glTranslated(0, 0, 2);
	DrawQuadT(-2.f, 0.f, 0.4f, 0.6f, 
		      -2.f, 5.f, 0.4f, 0.8f, 
			   2.f, 5.f, 0.6f, 0.8f, 
			   2.f, 0.f, 0.6f, 0.6f);

	DrawQuadT(-3.f, -5.f, 0.3f, 0.2f, 
		      -3.f, 0.f, 0.3f, 0.6f, 
			   3.f, 0.f, 0.7f, 0.6f, 
			   3.f, -5.f, 0.7f, 0.2f);

}

void Draw()
{

	// lection 3
   //DrawKube();
   //DrawMoving1();
   //DrawMoving2();
   //DrawMoving3();
   //DrawMoving4();
   //DrawMoving5();

//   glTranslated(0, 0, -5);
 //  DrawCamera1();

//   DrawRound(0, 0, 10);
	
	//glLineWidth(5);

	//lectoin 4
	//DrawFuncMasExample();
	//DrawFuncMasExample2();
	//DrawFuncParam(5);
	//DrawFuncParam2();

	//DrawFunc3D(1);
	//DrawFunc3D(2);
	//DrawFunc3D(3);

	//DrawBones();   //InitBones();

	// lection 5
	//DrawHome();
	//DrawSity();
//	DrawMan();

  //DrawIronMan();


	// lection 7
      //DrawLists();
	//DrawLists2();

	//glPrint(0, 0, 0, "Hello, world!");
	//glPrintV(0, 0, 0, "Hello, world!", 0, 0, 0, 1, 0, 1);

	//DrawSphere_(0, 0, 0, 2, 1, 1, 1, 0, 0, 0, false);
	//DrawIcosahedron_(0, 0, 0, 2, 1, 0, 0, 0, 0, 0, false);
	//DrawTeapot_(0, 0, 0, 2, 1, 0, 0, 0, 0, 0, false);
	
	
	//glLoadIdentity();
	//glTranslated(0, 3, 0);
	
	//CalcFPS();
	//DrawFPS();
}

void DrawKox(int n, float x1, float y1, float x2, float y2)
{
  if (n<=0) return;
   if (n == 1) DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1);
   else {
   float x3, y3, x4, y4, x5, y5;
   x3 = x1 + (x2 - x1)/3;   y3 = y1 + (y2 - y1)/3;
   DrawKox(n-1, x1, y1, x3, y3);

   x4 = x1 + (x2 - x1)/2 - (y2-y1)/4;   
   y4 = (y1 + y2)/2 + (x2-x1)/4;
   x5 = x1 + 2*(x2 - x1)/3;  
   y5 = y1 + 2*(y2 - y1)/3;
  DrawKox(n-1, x3, y3, x4, y4);
  DrawKox(n-1, x4, y4, x5, y5);
  DrawKox(n-1, x5, y5, x2, y2);  }
}

void DrawLevi(int n, float x1, float y1, float x2, float y2)
{
    if (n<=0) return;
   if (n == 1)  DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1);
   else
   {
    float x3, y3;
    x3 = (x1 + x2) / 2 - (y2 - y1)/2;
    y3 = (y1 + y2)/2 + (x2 - x1)/2;
    DrawLevi(n-1, x1, y1, x3, y3);
    DrawLevi(n-1, x3, y3, x2, y2);
    }
}

void DrawMondelbrot()
   {
	 glTranslated(10, 10, 0);
     glBegin(GL_POINTS);
    
	 int n = 200;
	  
     for (int y=-n; y<n; y++)
       for (int x=-n; x<n; x++)
        {  float re = 0, im = 0, i = 0;
           bool flag = false;
          while (i<100)
            {
              float re2 = re*re-im*im + (x)/140.0f; 
              float im2 = 2*re*im + (y)/140.0f;
              re = re2;   im = im2;
			               if (sqrt(re*re+im*im)>=2)
                 {
                  flag = true;
                  break;
                 }
            i++;
           }
     if (!flag)
     {
   glColor3f(1, 1, 1);   glVertex2f(x/20.0f-10, y/20.0f-10);
   }
  }
  glEnd();
 }

