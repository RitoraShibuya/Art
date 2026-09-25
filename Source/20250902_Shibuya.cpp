#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 255;
const int BACKGRAY = 10;
const int E_NUM = 30;
const double NOISERANGE = 0.01;

int Gap, Base_ang;
int Ang_switch;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
}

void draw( ) {
	background(BACKCOLOR, BACKGRAY);
	for (int i = 0; i < E_NUM; i++)
	{
		double ang = radians(360 * i / E_NUM + Base_ang);
		int x = CENTER_X + sin(ang) * Gap;
		int y = CENTER_Y + cos(ang) * Gap;
		stroke(noise(x * NOISERANGE, y * NOISERANGE, Base_ang * NOISERANGE) * 255,
			   noise(x * NOISERANGE + 100, y * NOISERANGE, Base_ang * NOISERANGE) * 255,
			   noise(x * NOISERANGE, y * NOISERANGE + 100, Base_ang * NOISERANGE) * 255);
		ellipse(x, y, 3);
	}

	if (Gap < 0)
	{
		Gap = 300;
	}
	else if (Gap > 500)
	{
		Gap = 0;
	}
	switch (Ang_switch)
	{
	case 0:
		Base_ang++;
		Gap++;
		break;
	case 1:
		Base_ang--;
		Gap++;
		break;
	case 2:
		Base_ang++;
		Gap--;
		break;
	case 3:
		Base_ang--;
		Gap--;
		break;
	}

}

void mouseClicked( ) {
	if (Ang_switch == 3)
	{
		Ang_switch = 0;
	}
	else {
		Ang_switch++;
	}
}

