#ifndef TEXTURES
#define TEXTURES

#include <iostream>
#include <vector>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class TexturesList
{
	vector<string> textures_names;
	vector<GLuint> textures_index;
public:
	void LoadTexture(string name, string type = "bmp");
	GLuint GetTextureIndex(string name);
};

#endif // TEXTURES