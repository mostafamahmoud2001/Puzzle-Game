#include "menu.h"
using namespace std;

menu::menu(float width, float tool)
{
	font.loadFromFile("arial.ttf");

	text [0].setFillColor(sf::Color::Red   ) ;
	text [1].setFillColor(sf::Color::White ) ;
	text [2].setFillColor(sf::Color::White ) ;

	text[0].setPosition( sf :: Vector2f( width - 100 , tool / 4 * 1) );
	text[1].setPosition( sf :: Vector2f( width - 100 , tool / 4 * 2) );
	text[2].setPosition( sf :: Vector2f( width - 100 , tool / 4 * 3) );
	
	text[0].setFont(font);
	text[1].setFont(font);
	text[2].setFont(font);

	text[0].setString("Play");
	text[1].setString("Setting");
	text[2].setString("Exit");

	select = 0;

}

void menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(text[i]);
	}
}

void menu::moveup()
{
	if (select - 1 >= 0)
	{
		text[select].setFillColor(Color::White);
		select--;
		text[select].setFillColor(Color::Red);

	}
}

void menu::movedown()
{
	if (select + 1 < 3)
	{
		text[select].setFillColor(Color::White);
		select++;
		text[select].setFillColor(Color::Red);

	}
}

int menu::selectnow()
{
	return select;
}
	