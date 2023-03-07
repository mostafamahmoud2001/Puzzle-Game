#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class level1
{
public :
	 level1(float widht, float heigt);
	
	void mousebutton(RenderWindow &app);
	void draw(RenderWindow &app);
private:
	Texture t;
	int w = 125;
	int grid[6][6] = { 0 };
	Sprite sprite[20];
	int n = 0;
};

