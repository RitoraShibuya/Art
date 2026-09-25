#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID = 10;
const int H_GRID = GRID / 2;
const int D_GRID = GRID * 2;

int Framecount = 0;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	rectMode(CENTER);
	noStroke( );

}

void draw( ) {
	for (int x = H_GRID; x < WIDTH; x += GRID)
	{
		for (int y = H_GRID; y < HEIGHT; y += GRID)
		{
			double ang = radians(noise(x * 0.01, y * 0.01, Framecount * 0.01) * 360);
			fill(noise(x * 0.01, y * 0.01, ang) * 360,
				 noise(x * 0.01 + 200, y * 0.01, ang) * 360,
				 noise(x * 0.01, y * 0.01 + 200, ang) * 360);
			rotate(ang);
			rect(x, y, D_GRID, D_GRID);
			rotate(-ang);
		}
	}
	Framecount++;
}


