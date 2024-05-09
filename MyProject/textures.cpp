#include <iostream>
#include <vector>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

#include "textures.h"
#include "drawfunctions.h"


void TexturesList::LoadTexture(string name, string type)
{
	int i = textures_index.size();
	GLuint value;
	LoadBMP(&value, (char *)name.c_str());
	textures_index.push_back(value);
	int pos = name.find('/');
	if (pos>0)
		name = name.substr(pos + 1);
	textures_names.push_back(name);
}

GLuint TexturesList::GetTextureIndex(string name)
{
	if (textures_names.size()>0)
		for (unsigned i = 0; i<textures_names.size(); i++)
			if (textures_names[i].compare(name)==0)
				return textures_index[i];

	return -1;
}
