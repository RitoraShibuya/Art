#include "Processing.h"

const int WIDTH = 1000;
const int CENTER_X = WIDTH / 2;
const int HEIGHT = 1000;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int BACKALPHA = 50;
const int E_SIZE = 50;
const int E_NUM = 10;
const int E_WIDTH = 250;
const int E_HEIGHT = 100;
const int E_COLOR = 255;
const int E_ALPHAMIN = 10;
const int E_ALPHAMAX = 100;
const int E_VAL = 250;

struct ELLIPSE
{

	int x;
	int y;
	double ang;
	double e_height;
	double variable;
	double var_switch;
	
	int alpha = 100;

	void Setup(int n) {

		e_height = E_HEIGHT;
		ang = PI * n / E_NUM * 2;
		x = CENTER_X;
		y = CENTER_Y;

	}

	void Revolution() {

		e_height = cos(ang) + 1 * E_HEIGHT;

		alpha = (int)map(sin(ang), -1, 1, E_ALPHAMIN, E_ALPHAMAX);

		x = CENTER_X + cos(ang) * (E_WIDTH + variable);
		y = CENTER_Y + sin(ang) * (e_height - variable);

		fill(E_COLOR, alpha);
		noStroke();
		ellipse(x, y, E_SIZE);

		ang += 0.05;
		if (variable < E_VAL && var_switch)
		{
			variable++;
		}
		else
		{
			var_switch = false;
			variable--;
			if (variable < 0)
			{
				var_switch = true;
			}
		}
	}

};

ELLIPSE ellipses[E_NUM];

void setup( ) {

	size(WIDTH,HEIGHT);
	background(BACKCOLOR);
	//setFrameRate(10);

	for (int i = 0; i < E_NUM; i++)
	{
		ellipses[i].Setup(i);
	}

}

void draw( ) {

	background(BACKCOLOR, BACKALPHA);
	
	for (int i = 0; i < E_NUM; i++)
	{
		ellipses[i].Revolution();
	}
	
}


