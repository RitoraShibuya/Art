#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int R_NUM = 10;
const int MAXSPD = 10;
const int MAXDIA = 500;

struct SpinTower {
	int x, y;
	int angspd;
	double ang;
	int r, g, b;
};

SpinTower rects[ R_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noFill( );
	strokeWeight(100);
	rectMode(CENTER);
	for (int i = 0; i < R_NUM; i++)
	{
		int num = i % 3;
		rects[ i ] = { WIDTH / 2,HEIGHT / 2,(int)random(1,MAXSPD),0,num == 0 ? 255 : 0,num == 1 ? 255 : 0,num == 2 ? 255 : 0 };
	}
}

void draw( ) {
	background(BACKCOL,20);
	int mx = getMouseX( );
	int my = getMouseY( );
	for (int i = 0; i < R_NUM; i++)
	{
		int dx = rects[ i ].x - mx;
		int dy = rects[ i ].y - my;
		double gap = sqrt(dx * dx + dy * dy);
		rects[ i ].x = gap * ( ( i + 1.0 ) / R_NUM );
		rects[ i ].y =  gap * ( ( i + 1.0 ) / R_NUM );
		int dia = MAXDIA * ( ( i + 1.0 ) / R_NUM );
		rotate(rects[ i ].ang);
		stroke(rects[ i ].r, rects[ i ].g, rects[ i ].b);
		rect(rects[ i ].x, rects[ i ].y, dia, dia);

		rotate(-rects[i].ang);
		rects[ i ].ang += radians(rects[ i ].angspd);
	}
}


