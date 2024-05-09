#pragma once 
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

typedef struct                 // Структура для вершины
{
	float x, y;
} TEXTURE_VERTEX;

typedef struct                 // Структура для вершины
{
	float x, y, z;
} VERTEX;

typedef struct                 // Структура для линии
{
	int p1, p2;
} LINE;

typedef struct                 // Структура для треугольной грани 
{
	int p1, p2, p3;
} TRIANGLE;

typedef struct                 // Структура для четырехугольной грани
{
	int p1, p2, p3, p4;
	VERTEX n1, n2, n3, n4;
} QUAD;

typedef struct                 // Структура для цвета
{
	float r, g, b;
} COLOR;

static COLOR clWhite = {1, 1, 1};
static COLOR clBlack = {0, 0, 0};
static COLOR clRed = {1, 0, 0};
static COLOR clGreen = {0, 1, 0};
static COLOR clBlue = {0, 0, 1};

static VERTEX vrZero = {0, 0, 0};
static VERTEX vrOne = {1, 1, 1};

TEXTURE_VERTEX get_TEXTURE_VERTEX(float x, float y);

VERTEX get_VERTEX(float x, float y, float z = 0);

LINE get_LINE(int p1, int p2);

TRIANGLE get_TRIANGLE(int p1, int p2, int p3);

QUAD get_QUAD(int p1, int p2, int p3, int p4);

COLOR get_COLOR(float r, float g, float b);


VERTEX Normal(VERTEX v1, VERTEX v2, VERTEX v3);
VERTEX Sub(VERTEX v1, VERTEX v2);
VERTEX Sum(VERTEX v1, VERTEX v2);

float random(float a, float b);

std::string FloatToString(float f);
float StringToFloat(std::string s);
std::string IntToString(int i);
int StringToInt(string s);

std::string VertexToString(VERTEX v);
std::string ColorToString(COLOR c);
std::string TEXTUREVertexToString(TEXTURE_VERTEX v);
VERTEX StringToVertex(string s);
COLOR StringToColor(string s);
TEXTURE_VERTEX StringToVertexTexture(string s);