#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>

#include "item3d.h"
#include "types.h"
#include "drawfunctions.h"
#include "scene.h"

using namespace std;

Item3D::Item3D()
{
	tindex = -1;
	drawtype = 0;
	Item();
	name = "item3D";
};


Item3D::~Item3D()
{
	points.clear();
	lines.clear();
	quads.clear();
	triangles.clear();
}

void Item3D::Draw()
{
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	glRotated(angle.x, 1, 0, 0);
	glRotated(angle.y, 0, 1, 0);
	glRotated(angle.z, 0, 0, 1);
	glTranslated(-pos.x, -pos.y, -pos.z);

	if ((drawtype==0))
	{
		for (unsigned i = 0; i<points.size(); i++)
			DrawPoint(points[i], color, 10);
	}
	if ((drawtype==1))
	{
		for (unsigned i = 0; i<lines.size(); i++)
			DrawLine(points[lines[i].p1], points[lines[i].p2], color, 2);
	}
	if ((drawtype==2))
	{
		for (unsigned i = 0; i<triangles.size(); i++)
			DrawTriangle(points[triangles[i].p1], points[triangles[i].p2], points[triangles[i].p3], color);
		for (unsigned i = 0; i<quads.size(); i++)
			DrawQuad(points[quads[i].p1], points[quads[i].p2], points[quads[i].p3],	points[quads[i].p4], color);
	}
	if ((drawtype==3))
	{
		for (unsigned i = 0; i<triangles.size(); i++)
			DrawTriangleT(points[triangles[i].p1], points[triangles[i].p2], points[triangles[i].p3], get_COLOR(1, 1, 1),
			get_TEXTURE_VERTEX(0, 0), get_TEXTURE_VERTEX(0.5, 1), get_TEXTURE_VERTEX(1, 0), tindex);
		for (unsigned i = 0; i<quads.size(); i++)
			DrawQuadT(points[quads[i].p1], points[quads[i].p2], points[quads[i].p3], points[quads[i].p4],
					 get_COLOR(1, 1, 1), tindex);
	}
	if ((drawtype==4))
	{
		for (unsigned i = 0; i<triangles.size(); i++)
			DrawTriangle(points[triangles[i].p1], points[triangles[i].p2], points[triangles[i].p3], color);
		for (unsigned i = 0; i<quads.size(); i++)
			DrawQuadNormal(points[quads[i].p1], points[quads[i].p2], points[quads[i].p3],	points[quads[i].p4], 
			color);

	/*	for (unsigned i = 0; i<lines.size(); i++)
			DrawLine(points[lines[i].p1], points[lines[i].p2], get_COLOR(0, 0, 0), 2);*/
	}
	if ((drawtype==5))
	{
		int tindex = SCENE::GetTextureIndex("Grass32.bmp");
		for (unsigned i = 0; i<quads.size(); i++)
			DrawQuadNormalT(points[quads[i].p1], points[quads[i].p2], points[quads[i].p3],	points[quads[i].p4], 
			color, tindex);

	/*	for (unsigned i = 0; i<lines.size(); i++)
			DrawLine(points[lines[i].p1], points[lines[i].p2], get_COLOR(0, 0, 0), 2);*/
	}
	glPopMatrix();
}

map<string, string> Item3D::GetProperties()
{
	map<string, string> result = Item::GetProperties();
	result.insert(std::pair<string, string>("DrawType", IntToString(drawtype)));
	return result;
}

void Item3D::UpdateProperty(string property, string value)
{
	Item::UpdateProperty(property, value);
	if (property == "DrawType")
		drawtype = StringToInt(value);
}