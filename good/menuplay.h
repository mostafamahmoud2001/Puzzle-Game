#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class menuplay
{
public:
	menuplay(float widht,float heigt);
	void draw(sf::RenderWindow &window);
	void moveup();
	void movedown();
	int selectnow();

private:

	int select;
	Text text[5];
	Font font;
};
