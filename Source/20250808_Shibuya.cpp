#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 255;
const int R_NUM = 20;
const int SIZEMIN = 20;
const int SIZEMAX =100;

struct RECT
{
	double x, y, gy;
	int _size, r, g, b;

	void Setup() 
	{
		x = (double)random(WIDTH);
		y = (double)random(HEIGHT);
		gy = HEIGHT;
		r = (int)random(256);
		g = (int)random(256);
		b = (int)random(256);
		_size = (int)random(SIZEMIN, SIZEMAX);
	}

	void Draw()
	{
		rotate(PI / 3);
		while (gy >= y)
		{
			fill(0);
			rect(x, gy, _size, _size);
			gy -= 1.0;
		}
		fill(r, g, b);
		rect(x, gy, _size, _size);
	}
};

RECT rects[R_NUM];

void setup( ) 
{
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);

	for (int i = 0; i < R_NUM; i++)
	{
		rects[i].Setup();
	}
	for (int i = 0; i < R_NUM; i++)
	{
		rects[i].Draw();
	}
}

void draw( ) 
{
	
}


