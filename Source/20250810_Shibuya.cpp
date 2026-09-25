#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int BACKALPHA = 10;
const int L_NUM = 30;
const int L_ALPHA = 80;
const int SPD_MIN = 2;
const int SPD_MAX = 10;

struct STARs
{
	int x, y, old_x, old_y, r, g, b, spd, stw;

	void Setup() 
	{
		switch ((int)random(0, 2))
		{
		case 0:
			x = random(WIDTH);
			y = 0;
			break;
		case 1:
			x = 0;
			y = random(HEIGHT);
			break;
		}
		old_x = x;
		old_y = y;
		spd = (int)random(SPD_MIN, SPD_MAX);
		stw = (int)random(5);
		r = random(256);
		g = random(256);
		b = random(256);
		
	}

	void Draw()
	{
		old_x = x;
		old_y = y;
		x += spd;
		y += spd;
		stroke(r, g, b);
		strokeWeight(stw);
		line(old_x, old_y, x, y);
		if (old_x >= WIDTH && old_y >= HEIGHT)
		{
			Setup();
		}
	}
};

STARs lines[L_NUM];

void setup( ) 
{
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);

	for (int i = 0; i < L_NUM; i++)
	{
		lines[i].Setup();
	}
}

void draw( ) 
{
	background(BACKCOLOR, BACKALPHA);

	for (int i = 0; i < L_NUM; i++)
	{
		lines[i].Draw();
	}
}


