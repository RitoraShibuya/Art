#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int E_SIZE = 50;
const int E_NUM = 10;
const int ADDSION = 100;
const int E_ALPHA = 50;


struct ELLIPSE
{
	double x;
	double y;
	double center_x;
	double center_y;
	double ang;
	int colorcode = 0;

	void Setup(int i)
	{
		if (i % 2 == 0)
		{
			x = 0;
		}
		else
		{
			x = WIDTH;
		}

		colorcode = (i + 1) % 3;
		center_y = HEIGHT * (i + 1) / (E_NUM + 1);
		ang = 0;
	}

	void Draw(int i)
	{
		
		if (i % 2 == 0)
		{
			y = center_y + cos(radians(ang)) * ADDSION;
			x += 5;
			if (x > WIDTH + E_SIZE)
			{
				x = 0;
				ang = 0;
				colorcode++;
			}
		}
		else 
		{
			y = center_y + sin(radians(ang)) * ADDSION;
			x -= 5;
			if (x < 0 - E_SIZE)
			{
				x = WIDTH;
				ang = 0;
				colorcode++;
			}
		}

		if (colorcode == 3)
		{
			colorcode = 0;
		}

		switch (colorcode)
		{
		case 0:fill(255, 0, 0, E_ALPHA);
			break;
		case 1:fill(0, 255, 0, E_ALPHA);
			break;
		case 2:fill(0, 0, 255, E_ALPHA);
			break;
		}

		ellipse(x, y, E_SIZE);

		

		ang += 5;
	}
};

ELLIPSE waves[E_NUM];

void setup( ) 
{
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	stroke(0,50);

	for (int i = 0; i < E_NUM; i++)
	{
		waves[i].Setup(i);
	}
}

void draw( ) 
{
	//background(BACKCOLOR,50);

	for (int i = 0; i < E_NUM; i++)
	{
		waves[i].Draw(i);
	}
}


