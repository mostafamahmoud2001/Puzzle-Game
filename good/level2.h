#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class level2
{
public:
	level2(float widht, float heigt);

	void mousebutton(RenderWindow &app);
	void draw(RenderWindow &app);
private:
	Texture t;
	int w = 166;
	int grid[5][5] = { 0 };
	Sprite sprite[12];
	int n = 0;
};

