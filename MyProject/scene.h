#pragma once

#include "item.h"
#include <vector>
#include <map>
#include "textures.h"

static TexturesList * textures;

using namespace std;
class SCENE
{
	std::vector<Item *> items;
	int width, height;
public:
	SCENE(int width, int height);
	~SCENE();
	void InitLight();
	void SetLight();
	void Init();

	void Draw();	
	void DrawPine1(VERTEX v, float size);
	void DrawPine2(VERTEX v, float size);

	static GLuint GetTextureIndex(string name);
	map<int, string> GetItemsNames();
	map<string, string> GetPropertisByIndex(int index);
	vector <string> GetTypesNames();
	void UpdateProperty(int index, string property, string value);
	void SetVisibleItem(int index, bool value);
	bool ItemIsVisible(int index);
	
	void AddItem(string name);
	void Clear();
	void DeleteItem(int index);
	void CloneItem(int index);

	void Load(string name);
	void Save(string name);
	void MouseDown(int x, int y, int mb);
	void MouseUp(int x, int y);
	void MouseMove(int x, int y);
};
