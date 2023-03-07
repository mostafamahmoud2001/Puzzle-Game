#pragma once
#include <SFML/Graphics.hpp>
using namespace sf; 
class menu
{
public :

	menu(float width, float heigt);
	void draw(sf::RenderWindow &window);
	void moveup();
	void movedown();
	int selectnow();
	
private :
	int select;
	Font font ;
	Text text[3] ;

};

