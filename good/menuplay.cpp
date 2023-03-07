#include "menuplay.h"
using namespace std;

menuplay::menuplay(float width, float heigt)
{
	font.loadFromFile("arial.ttf");
	text[0].setPosition( width / 2, heigt / 6 * 1);
	text[1].setPosition( width / 2, heigt / 6 * 2);
	text[2].setPosition( width / 2, heigt / 6 * 3);
	text[3].setPosition( width / 2, heigt / 6 * 4);
	text[4].setPosition( width / 2, heigt / 6 * 5);

	text[0].setFillColor(Color::Red);
	text[1].setFillColor(Color::White);
	text[2].setFillColor(Color::White);
	text[3].setFillColor(Color::White);
	text[4].setFillColor(Color::White);

	text[0].setString("level 1");
	text[1].setString("level 2");
	text[2].setString("level 3");
	text[3].setString("level 4");
	text[4].setString(" back ");


	text[0].setFont(font);
	text[1].setFont(font);
	text[2].setFont(font);
	text[3].setFont(font);
	text[4].setFont(font);

	select = 0 ;
}

void menuplay::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(text[i]);
	}
}

void menuplay::moveup()
{
	if (select - 1 >= 0)
	{
		text[select].setFillColor(Color::White);
		select--;
		text[select].setFillColor(Color::Red);

	}
}

void menuplay::movedown()
{
	if (select + 1 < 5)
	{
		text[select].setFillColor(Color::White);
		select++;
		text[select].setFillColor(Color::Red);

	}
}

int menuplay::selectnow()
{
	return select;
}
