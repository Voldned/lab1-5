#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "types.h"

void DrawPoint(float x, float y, float z, float r, float g, float b);
void DrawPoint(float x, float y, float z, float r, float g, float b, float size);
void DrawPoint(float x, float y, float size);
void DrawPoint(VERTEX v, COLOR color, float size);

void DrawKub_(float x, float y, float z, float w, float r, float g, float b, float ax, float ay, float az, bool solid);

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1, float r2, float g2, float b2);
void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1);
void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1, float r2, float g2, float b2);
void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1);
void DrawLine(float x1, float y1, float x2, float y2);
void DrawLine(VERTEX v1, VERTEX v2, COLOR c1, COLOR c2);
void DrawLine(VERTEX v1, VERTEX v2, COLOR c);
void DrawLine(VERTEX v1, VERTEX v2, COLOR c, float size);
void DrawLine(float x1, float y1, float x2, float y2, float size);

void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3);
void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1);
void DrawTriangle(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c);
void DrawTriangle(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c1, COLOR c2, COLOR c3);

void DrawTriangleT(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c, int tindex);
void DrawTriangleT(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, int tindex);
void DrawTriangleT(VERTEX v1, VERTEX v2, VERTEX v3, COLOR c, COLOR c2, COLOR c3, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, int tindex);
void DrawTriangleT(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, int tindex);

void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3, float r4, float g4, float b4);
void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1);
void DrawQuad(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, COLOR cs);
void DrawQuad(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, COLOR c1, COLOR c2, COLOR c3, COLOR c4);
void DrawQuad(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, COLOR c, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, TEXTURE_VERTEX tv4, int tindex);
void DrawQuadNormal(VERTEX v1,VERTEX v2, VERTEX v3, VERTEX v4, COLOR c1, COLOR c2, COLOR c3, COLOR c4);
void DrawQuadNormal(VERTEX v1,VERTEX v2, VERTEX v3, VERTEX v4, COLOR c);
void DrawQuadNormalT(VERTEX v1,VERTEX v2, VERTEX v3, VERTEX v4, COLOR c, GLuint texture);

void DrawQuadT(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, float tx4, float ty4, int tindex);
void DrawQuadT(float x1, float y1, float tx1, float ty1, float x2, float y2, float tx2, float ty2, float x3, float y3, float tx3, float ty3, float x4, float y4, float tx4, float ty4);
void DrawQuadT(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, TEXTURE_VERTEX tv4, COLOR color, int tindex);
void DrawQuadT(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4, COLOR color, int tindex);


void DrawRect(float x1, float y1, float z1, float w, float h, float r1, float g1, float b1);

void DrawPolygon(float **mas, int n, float r1, float g1, float b1);

void DrawCircle(float x, float y, float z, float radius, float r1, float g1, float b1);
void DrawCircle(VERTEX p, float radius, COLOR c);

void DrawRound(float x, float y, float z, float radius, float r1, float g1, float b1);
void DrawRound(VERTEX p, float radius, COLOR c);

void InitOpenGL(int width, int height);

void Draw();
void LoadHouseTextures();
void LoadBMP(GLuint *texture, char *filename);
void LoadTGA(GLuint *texture, char *filename);

void InitMan();
void MouseDown(float x, float y);

void DrawSphere_(float x, float y, float z, float radius, float r, float g, float b,  float ax, float ay, float az, bool solid);
void DrawSphere_(VERTEX p, float radius, COLOR color,  VERTEX angle, bool solid);

void DrawIcosahedron_(float x, float y, float z, float w, float r, float g, float b, float ax, float ay, float az, bool solid);
void DrawIcosahedron_(VERTEX p, float w, COLOR color, VERTEX angle, bool solid);


void DrawKox(int n, float x1, float y1, float x2, float y2);
void DrawLevi(int n, float x1, float y1, float x2, float y2);

void DrawMondelbrot();

GLvoid BuildVERTEXFont(GLvoid);
GLvoid glPrint(float x, float y, float z, char text[256]);
GLvoid KillFont(GLvoid);
GLvoid BuildFont(GLvoid);

void CalcFPS();
void DrawFPS();

