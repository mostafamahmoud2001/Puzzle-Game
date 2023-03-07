#include "level1.h"
using namespace std;	
 level1::level1(float widht, float heigt)
{
	
	t.loadFromFile("15.png");

	

	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			n++;
			sprite[n].setTexture(t);
			sprite[n].setTextureRect(IntRect(i*w, j*w, w, w));
			grid[i + 1][j + 1] = n;
		}
}

void level1::mousebutton(RenderWindow &app)
{
	Vector2i pos = Mouse::getPosition(app);
	int x = pos.x / w + 1;
	int y = pos.y / w + 1;

	int dx = 0;
	int dy = 0;

	if (grid[x + 1][y] == 16) { dx = 1; dy = 0; };
	if (grid[x][y + 1] == 16) { dx = 0; dy = 1; };
	if (grid[x][y - 1] == 16) { dx = 0; dy = -1; };
	if (grid[x - 1][y] == 16) { dx = -1; dy = 0; };

	int n = grid[x][y];
	grid[x][y] = 16;
	grid[x + dx][y + dy] = n;
}

void level1::draw(RenderWindow & app)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			int n = grid[i + 1][j + 1];
			sprite[n].setPosition(i*w, j*w);
			app.draw(sprite[n]);
		}
}
