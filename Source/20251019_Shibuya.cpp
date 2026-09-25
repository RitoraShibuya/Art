#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID = 1;
const int R_NUM = WIDTH / GRID;
const int SPD = 1;

int Framecount = 0;

struct RandRect {
	double x, y;
	bool under;
};

RandRect rects[ R_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke( );
	for (int i = 0; i < R_NUM; i++)
	{
		rects[ i ].x = i * GRID;
		rects[ i ].y = 0;
	}
}

void draw( ) {
	background(BACKCOL, 1);
	colorMode(HSB, 360, 100, 100);
	for (int i = 0; i < R_NUM; i++)
	{
		double x = rects[ i ].x;
		double y = rects[ i ].y;
		fill(noise(x * 0.01 + 500, y * 0.01 + 500, Framecount * 0.01) * 360, 100, 100);
		rect(x, y, GRID, GRID);
		if (y > HEIGHT) {
			rects[ i ].y = 0;
		}
		else {
			rects[ i ].y += noise(x * 0.05, y * 0.05, Framecount * 0.01) * SPD;
		}
	}

	colorMode(RGB, 256);

	Framecount++;
}


