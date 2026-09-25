#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int BACKCOL = 0;

int _x, _y;
int _x2, _y2;
int _x3, _y3;
int _x4, _y4;
double ang1;
double ang2;
double ang3;
double ang4;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke();
}

void draw() {
	background(BACKCOL,5);
	fill(255);
	ellipse(CX, CY, 200);
	_x = CX + cos(radians(ang1)) * 150;
	_y = CY + sin(radians(ang1)) * 150;
	fill(150);
	ellipse(_x,_y, 30);
	ang1 += 0.5;
	fill(255,0,0);
	_x2 = _x + cos(radians(ang2)) * 200;
	_y2 = _y + sin(radians(ang2)) * 200;
	ellipse(_x2, _y2, 50);
	ang2 -= 0.3;
	fill(0, 255, 255);
	_x3 = _x2 + cos(radians(ang3)) * 100;
	_y3 = _y2 + sin(radians(ang3)) * 100;
	ellipse(_x3, _y3, 10);
	ang3 += 1.0;
	fill(255, 255, 0);
	_x4 = _x2 + cos(radians(ang4)) * 100;
	_y4 = _y2 + sin(radians(ang4)) * 100;
	ellipse(_x4, _y4, 10);
	ang4 -= 1.0;
}


