#include "level2.h"

level2::level2(float widht, float heigt)
{
	t.loadFromFile("im.png");




	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			n++;
			sprite[n].setTexture(t);
			sprite[n].setTextureRect(IntRect(i*w, j*w, w, w));
			grid[i + 1][j + 1] = n;
		}
}

void level2::mousebutton(RenderWindow & app)
{
	Vector2i pos = Mouse::getPosition(app);
	int x = pos.x / w + 1;
	int y = pos.y / w + 1;

	int dx = 0;
	int dy = 0;

	if (grid[x + 1][y] == 9) { dx = 1; dy = 0; };
	if (grid[x][y + 1] == 9) { dx = 0; dy = 1; };
	if (grid[x][y - 1] == 9) { dx = 0; dy = -1; };
	if (grid[x - 1][y] == 9) { dx = -1; dy = 0; };

	int n = grid[x][y];
	grid[x][y] = 9;
	grid[x + dx][y + dy] = n;
}

void level2::draw(RenderWindow & app)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int n = grid[i + 1][j + 1];
			sprite[n].setPosition(i*w, j*w);
			app.draw(sprite[n]);
		}
}
