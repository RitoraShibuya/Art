#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int BACKCOLOR = 0;
const int X_GAP = 200;
const int Y_GAP = 100;
const int R_NUM = 2;
const int Y_CENTER[2] = { 250,750 };

static double base_ang;
static int l_x[2][4];
static int l_y[2][4];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	noFill();
	stroke(255);
}

void draw( ) {
	background(BACKCOLOR,10);
	for (int i = 0; i < R_NUM; i++)
	{
		beginShape();
		for (int c = 0; c < 4; c++)
		{
			double ang = (PI2 * c / 4) + base_ang;
			int x = CENTER_X + sin(ang)* X_GAP;
			int y = Y_CENTER[i] + cos(ang)* Y_GAP;
			vertex(x, y);
			l_x[i][c] = x;
			l_y[i][c] = y;
		}
		endShape(CLOSE);
	}
	for (int i = 0; i < 4; i++)
	{
		line(l_x[0][i], 
			l_y[0][i],
			l_x[1][(i == 3 ? 0 : i + 1)],
			l_y[1][(i == 3 ? 0 : i + 1)]);
	}
	base_ang += 0.01;
}


