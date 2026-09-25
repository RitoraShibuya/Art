#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int BACKALPHA = 20;
const int L_NUM = 6;
const int L_ADDSION = 200;

int _faramerate;

struct STAR
{
	int x, y, x2, y2, mx, my, r, g, b;
	double ang;

	void Setup(int i)
	{
		ang = TWO_PI * i / L_NUM;
		mx = getMouseX();
		my = getMouseY();
		x = mx;
		y = my;
		
	}

	void Draw()
	{
		if (_faramerate % 10 == 0) 
		{
			mx = getMouseX();
			my = getMouseY();
			x2 = mx + sin(ang) * L_ADDSION;
			y2 = my + cos(ang) * L_ADDSION;
			line(x, y, x2, y2);
			x = x2;
			y = y2;
			ang += TWO_PI * 2.0 / L_NUM;
			x2 = mx + sin(ang) * L_ADDSION;
			y2 = my + cos(ang) * L_ADDSION;
			line(x, y, x2, y2);
			x = x2;
			y = y2;
			
		}
	}
};

STAR lines[L_NUM];

void setup( ) 
{
	setFrameRate(10);
	size(WIDTH, HEIGHT);
	stroke(255, 255, 0);
	strokeWeight(5);
	for (int i = 0; i < L_NUM; i++)
	{
		lines[i].Setup(i);
	}
}

void draw( ) 
{
	background(BACKCOLOR, BACKALPHA);
	for (int i = 0; i < L_NUM; i++)
	{
		lines[i].Draw();
	}
	_faramerate++;
}


