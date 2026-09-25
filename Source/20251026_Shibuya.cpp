#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int GAP = 100;

double x;
double y;
double oldx;
double oldy;
double ang;
int ang1;
int ang2;

void setup() {
	size(WIDTH, HEIGHT);
	background(0);
	fill(255);
	stroke(255);

	x = 500;
	y = 500;
	oldx = 500;
	oldy = 500;
}

void draw() {
	background(0, 1);

	x = 500 + 100 * cos(radians(ang)) + cos(radians(ang1)) * (5 * sin(radians(ang2)) * GAP);
	y = 500 + 100 * sin(radians(ang)) + sin(radians(ang1)) * (5 * sin(radians(ang2)) * GAP);

	line(oldx, oldy, x, y);

	ang += 0.5;
	ang1++;
	ang2 += 5;
	oldx = x;
	oldy = y;
}


