#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int R_NUM = 20;
const double SPD = 2.0;
const int ANG_SPD = 1;

struct Center {
	double x, y;
};

struct R_ang {
	int ang;
};

Center c_point;
R_ang angs[ R_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noFill( );
	strokeWeight(10);
	rectMode(CENTER);

	for (int i = 0; i < R_NUM; i++)
	{
		angs[ i ].ang = i * 7;
	}
	c_point = { WIDTH / 2,HEIGHT / 2 };
}

void draw( ) {
	background(BACKCOL,20);
	int mx = getMouseX( );
	int my = getMouseY( );
	double ang = atan2(my - c_point.y, mx - c_point.y);
	c_point.x = c_point.x + cos(ang) * SPD;
	c_point.y = c_point.y + sin(ang) * SPD;

	stroke(0, 0, 255);
	for (int i = 0; i < R_NUM; i++)
	{
		int dia = (int)map(i, 0, R_NUM - 1, 10, 500);
		rotate(radians(angs[ i ].ang));
		rect(map(i, 0, R_NUM - 1, c_point.x, mx), map(i, 0, R_NUM - 1, c_point.y, my), dia, dia);
		angs[ i ].ang += ANG_SPD;
		rotate(radians(-angs[ i ].ang));
	}

}


