#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
//#include <msclr\marshal_cppstd.h>

#include "scene.h"
#include "types.h"
#include "item.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "trianglet.h"
#include "quad.h"
#include "quadt.h"
#include "kub.h"
#include "shere.h"
#include "grid.h"
#include "textures.h"
#include "fractal.h"
#include "fractalLS.h"
#include "puzzle.h"
#include "particles.h"
#include "drawfunctions.h"
#include "cylinder.h"
#include "cone.h"

#using <System.Xml.dll>
#using <System.dll>
#using <System.xml.dll>

using namespace System;
using namespace System::IO;
using namespace System::Xml;
using namespace System::Runtime::InteropServices;


   GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
   GLfloat mat_shininess[]={50.0};
   GLfloat light_position[]={2.0,2.0,0.0,0.0};
   GLfloat white_light[]={1.0,1.0,1.0,1.0};

SCENE::SCENE(int width, int height)
{
	this->width = width;
	this->height = height;
	Init();
}

SCENE::~SCENE()
{
	for (unsigned i = 0; i<items.size(); i++)
		delete items[i];
	items.clear();
	KillFont();
}

void SCENE::InitLight()
{
   glLightfv(GL_LIGHT0,GL_DIFFUSE,white_light);
   
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0); 
}

void SCENE::SetLight()
{
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
//	DrawSphere_(get_VERTEX(light_position[0], light_position[1], light_position[2]), 0.1f, clWhite, vrZero, true);
}

void SCENE::Init()
{

	BuildFont();
	BuildVERTEXFont();

	textures = new TexturesList();

	//textures->LoadTexture("picts/wall1.bmp");
	//textures->LoadTexture("picts/wall2.bmp");
	textures->LoadTexture("picts/Grass32.bmp");
	textures->LoadTexture("picts/W1.bmp");
	textures->LoadTexture("picts/fir_tree_2pow.bmp");

	// os
	//items.push_back(new Line(get_VERTEX(-10, 0, 0), get_VERTEX(20, 0, 0), get_COLOR(1, 1, 1), 1));
	//items.push_back(new Line(get_VERTEX(0, -10, 0), get_VERTEX(0, 20, 0), get_COLOR(1, 1, 1), 1));
	//items.push_back(new Line(get_VERTEX(0, 0, -10), get_VERTEX(0, 0, 20), get_COLOR(1, 1, 1), 1));
	
	items.push_back(new Kub(get_VERTEX(0, -2, 0), 1, clWhite, 3, 1));
	items.push_back(new Cone(get_VERTEX(0, 0, 0), 1, clWhite, 2, 1));
}

GLuint SCENE::GetTextureIndex(string name)
{
	return textures->GetTextureIndex(name);
}

void SCENE::Draw()
{
    SetLight();

	for (unsigned i = 0; i<items.size(); i++)
		if (items[i]->GetVisible())
			items[i]->Draw();

	//VERTEX angle = {GetTickCount()/60.0f, GetTickCount()/30.0f, GetTickCount()/50.0f};
	//DrawIcosahedron_(get_VERTEX(0, 5, 0), 1, clWhite, angle, true);

	glLoadIdentity();
	glTranslated(0, 3, 0);
	
	CalcFPS();
	DrawFPS();
}

map<int, string> SCENE::GetItemsNames()
{
	map<int, string> result;
	for (unsigned i = 0; i < items.size(); i++)
		result.insert(std::pair<int, string>(i, items[i]->GetName()));
	return result;
}

map<string, string> SCENE::GetPropertisByIndex(int index)
{
	map<string, string> result;
	if ((index > -1) && (index < items.size()))
		return items[index]->GetProperties();

	return result;
}

void SCENE::UpdateProperty(int index, string property, string value)
{
	if ((index>-1)&&(index<items.size()))
		items[index]->UpdateProperty(property, value);
}

void SCENE::SetVisibleItem(int index, bool value)
{
	if ((index>-1) && (index<items.size()))
		items[index]->SetVisible(value);
}

bool SCENE::ItemIsVisible(int index)
{
	if ((index>-1) && (index<items.size()))
		return items[index]->GetVisible();
	return 0;
}

vector <string> SCENE::GetTypesNames()
{
	vector <string> result;
	result.push_back("Point");
	result.push_back("Line");
	result.push_back("Triangle");
	result.push_back("TriangleT");
	result.push_back("Quad");
	result.push_back("QuadT");
	result.push_back("Shere");
	result.push_back("Kub");
	result.push_back("Cylinder");

	result.push_back("Puzzle");
	result.push_back("Particles");

	return result;
}

void SCENE::AddItem(string name)
{
	if (name=="Point")
		items.push_back(new Point(get_VERTEX(0, 0, 0), get_COLOR(1, 1, 1), 10));
	else
	if (name == "Line")
		items.push_back(new Line(get_VERTEX(0, 0, 0), get_VERTEX(1, 0, 0), get_COLOR(1, 1, 1), 2));
	else
	if (name == "Triangle")
		items.push_back(new Triangle(get_VERTEX(0, 0, 0), get_VERTEX(0, 1, 0), get_VERTEX(1, 0, 0), get_COLOR(1, 1, 1)));
	else
	if (name == "TriangleT")
		items.push_back(new TriangleT(get_VERTEX(0, 0, 0), get_VERTEX(0, 1, 0), get_VERTEX(1, 0, 0), get_COLOR(1, 1, 1), "wall1.bmp", get_TEXTURE_VERTEX(0, 0), get_TEXTURE_VERTEX(1, 0), get_TEXTURE_VERTEX(0, 1)));
	else
	if (name == "Quad")
		items.push_back(new Quad(get_VERTEX(0, 0, 0), get_VERTEX(0, 1, 0), get_VERTEX(1, 1, 0), get_VERTEX(1, 0, 0), get_COLOR(1, 1, 1)));
	else
	if (name == "QuadT")
		items.push_back(new QuadT(get_VERTEX(0, 0, 0), get_VERTEX(0, 1, 0), get_VERTEX(1, 1, 0), get_VERTEX(1, 0, 0), get_COLOR(1, 1, 1), "wall1.bmp", get_TEXTURE_VERTEX(0, 0), get_TEXTURE_VERTEX(0, 1), get_TEXTURE_VERTEX(1, 1), get_TEXTURE_VERTEX(1, 0)));
	else
	if (name=="Puzzle")
		items.push_back(new Puzzle(get_VERTEX(-1, -1, 0), 2, 2, 3, 3, "W1.bmp"));
	else
	if (name=="Particles")
		items.push_back(new Particles(get_VERTEX(0, 0, 0), clWhite, 10, get_VERTEX(0, 1, 0)));
	if (name == "Shere")
		items.push_back(new Shere(get_VERTEX(0, 0, 0), 10,clWhite, 1, 1));
	if (name == "Kub")
		items.push_back(new Kub(get_VERTEX(0, 0, 0), 10, clWhite, 1, 1));
	if (name == "Cylinder")
		items.push_back(new Cylinder(get_VERTEX(0, 0, 0), 1, clWhite, 1, 1));
}

void SCENE::Clear()
{
	for (unsigned i = 0; i < items.size(); i++)
		delete items[i];
	items.clear();
}

void SCENE::DeleteItem(int index)
{
	if ((index>-1) && (index<items.size()))
	{
		delete items[index];
		items.erase(items.begin()+index);
	}
}
void SCENE::CloneItem(int index)
{
	if ((index>-1) && (index<items.size()))
	{
		
		map<string, string> props = items[index]->GetProperties();

		AddItem(items[index]->GetName());
		int n = items.size()-1;
		for (auto it = props.begin(); it != props.end(); ++it)
				{
					UpdateProperty(n, it->first, it->second);
				}

	}
}

string SystemToStl(String ^s)
{
	using namespace Runtime::InteropServices;
	const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	return string(ptr);
}

void SCENE::Load(string name)
{
	XmlDocument^ myXML;
	myXML = gcnew XmlDocument;

	String^ name_ = gcnew String(name.c_str());
	myXML->Load(name_);
	XmlNodeList^ listXML;
	XmlNode^ tagXML;
	XmlNode^ node;
	listXML = myXML->GetElementsByTagName("scene");
	if (listXML)
	{
		Clear();
		tagXML = listXML[0];
		if (tagXML)
		{
			if (tagXML->HasChildNodes)
			{
				 XmlNodeList^ ChildNodes = tagXML->ChildNodes; 
					for ( int i = 0; i < ChildNodes->Count; i++ )
					{
						node = ChildNodes[i];
						XmlNode^ itemname = node->Attributes->GetNamedItem("Name");
						if(itemname!=nullptr)
						{
							AddItem(SystemToStl(itemname->Value));
							if (node->HasChildNodes)
							{
								XmlNodeList^ ChildNodes2 = node->ChildNodes; 
								for ( int i2 = 0; i2 < ChildNodes2->Count; i2++ )
									{
										XmlNode^ node2 = ChildNodes2[i2];
										UpdateProperty(i, SystemToStl(node2->Name), SystemToStl(node2->InnerText));
									}

							}
						}
					}
			}
		}
	}
}

void SCENE::Save(string name)
{
	XmlDocument^ myXML;
	myXML = gcnew XmlDocument;

	XmlElement^ scene = myXML->CreateElement( "scene" );
    
	myXML->AppendChild(scene);

	for (unsigned i = 0; i < items.size(); i++)
	{
		XmlElement^ item = myXML->CreateElement( "item" );
		XmlNode^ attr = myXML->CreateNode( System::Xml::XmlNodeType::Attribute, "Name", "");
		attr->Value = gcnew String(items[i]->GetName().c_str());
		item->Attributes->SetNamedItem(attr);
		map<string, string> props = items[i]->GetProperties();

		for (auto it = props.begin(); it != props.end(); ++it)
				{
					XmlElement^ itemprop = myXML->CreateElement( gcnew String(it->first.c_str()) );
					itemprop->InnerText = gcnew String(it->second.c_str());
					item->AppendChild(itemprop);
				}

		scene->AppendChild(item);
	}
	String^ name_ = gcnew String(name.c_str());
	myXML->Save(name_);

}

void SCENE::MouseDown(int x, int y, int mb)
{
	for (unsigned i = 0; i < items.size(); i++)
		if (items[i]->GetName() == "Puzzle") 
			items[i]->MouseDown(1.f*x/width, 1.f*y/height);
}

void SCENE::MouseUp(int x, int y)
{
	for (unsigned i = 0; i < items.size(); i++)
		if (items[i]->GetName() == "Puzzle") 
			items[i]->MouseUp(1.f*x/width, 1.f*y/height);
}

void SCENE::MouseMove(int x, int y)
{
	for (unsigned i = 0; i < items.size(); i++)
		if (items[i]->GetName() == "Puzzle") 
			items[i]->MouseMove(1.f*x/width, 1.f*y/height);
}