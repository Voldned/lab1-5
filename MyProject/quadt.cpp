#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "types.h"
#include "quadt.h"
#include "drawfunctions.h"
#include "scene.h"

QuadT::QuadT(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color, string name_texture)
	:Quad(pos1, pos2, pos3, pos4, color)
{
	this->name_texture = name_texture;
	this->tv1 = get_TEXTURE_VERTEX(0, 0);
	this->tv2 = get_TEXTURE_VERTEX(0, 1);
	this->tv3 = get_TEXTURE_VERTEX(1, 1);
	this->tv4 = get_TEXTURE_VERTEX(1, 0);
	SetName("QuadT");
}

QuadT::QuadT(VERTEX pos1, VERTEX pos2, VERTEX pos3, VERTEX pos4, COLOR color, string name_texture, TEXTURE_VERTEX tv1, TEXTURE_VERTEX tv2, TEXTURE_VERTEX tv3, TEXTURE_VERTEX tv4)
	:Quad(pos1, pos2, pos3, pos4, color)
{
	this->name_texture = name_texture;
	SetSize(size);
	this->tv1 = tv1;
	this->tv2 = tv2;
	this->tv3 = tv3;
	this->tv4 = tv4;
	SetName("QuadT");
}

void QuadT::Draw()
{
	int tindex = SCENE::GetTextureIndex(name_texture);
	if (tindex>-1)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tindex);

		glPushMatrix();
		///glTranslated(pos.x, pos.y, pos.z);
		glRotated(angle.x, 1, 0, 0);
		glRotated(angle.y, 0, 1, 0);
		glRotated(angle.z, 0, 0, 1);
		glScaled(size, size, size);
		glBegin(GL_QUADS);
			glColor3d(color.r, color.g, color.b);
			glTexCoord2f(tv1.x, tv1.y);
			glVertex3d(pos.x, pos.y, pos.z);
			glColor3d(color2.r, color2.g, color2.b);
			glTexCoord2f(tv2.x, tv2.y); 
			glVertex3d(pos2.x, pos2.y, pos2.z);
			glColor3d(color3.r, color3.g, color3.b);
			glTexCoord2f(tv3.x, tv3.y);
			glVertex3d(pos3.x, pos3.y, pos3.z);
			glColor3d(color4.r, color4.g, color4.b);
			glTexCoord2f(tv4.x, tv4.y);
			glVertex3d(pos4.x, pos4.y, pos4.z);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		//DrawQuadT(pos, Sum(pos, pos2), Sum(pos, pos3), Sum(pos, pos4), tv1, tv2, tv3, tv4, color, tindex);
	}
	else
		Quad::Draw();
		//DrawQuad(pos, Sum(pos, pos2), Sum(pos, pos3), Sum(pos, pos4), color);

}

map<string, string> QuadT::GetProperties()
{
	map<string, string> result = Quad::GetProperties();
	result.insert(std::pair<string, string>("TexCoord", TEXTUREVertexToString(tv1)));
	result.insert(std::pair<string, string>("TexCoord2", TEXTUREVertexToString(tv2)));
	result.insert(std::pair<string, string>("TexCoord3", TEXTUREVertexToString(tv3)));
	result.insert(std::pair<string, string>("TexCoord4", TEXTUREVertexToString(tv4)));
	result.insert(std::pair<string, string>("Texture", name_texture));
	return result;
}

void QuadT::UpdateProperty(string property, string value)
{
	Quad::UpdateProperty(property, value);
	if (property == "TexCoord")
		tv1 = StringToVertexTexture(value);
	if (property == "TexCoord2")
		tv2 = StringToVertexTexture(value);
	if (property == "TexCoord3")
		tv3 = StringToVertexTexture(value);
	if (property == "TexCoord4")
		tv4 = StringToVertexTexture(value);
	if (property == "Texture")
		name_texture = value;

}