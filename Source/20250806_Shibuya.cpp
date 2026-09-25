#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 255;
const int E_NUM = 20;
const int E_SIZE = 50;

void setup( ) 
{
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	noStroke();
}

void mouseDragged( ) 
{
	int x = getMouseX();
	int y = getMouseY();
	int r = ((int)random(1, 3) == 1 ? 255 : 0);
	int g = ((int)random(1, 3) == 1 ? 255 : 0);
	int b = ((int)random(1, 3) == 1 ? 255 : 0);

	fill(r, g, b, 150);

	for (int i = 0; i < E_NUM; i++)
	{
		ellipse(x, y, E_SIZE);
		x += (int)random(-25, 25);
		y += (int)random(-25, 25);
	}
}


