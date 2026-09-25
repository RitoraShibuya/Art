#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID = 6;
const int H_GRID = GRID / 2;

int Framecount = 0;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	//stroke(255);
	noStroke( );
	fill(255);
}

void draw( ) {

	background(BACKCOL);

	double f_noise = Framecount * 0.01;

	for (int x = H_GRID; x < WIDTH; x += GRID)
	{
		for (int y = H_GRID; y < HEIGHT; y += GRID)
		{
			double addnoise = noise(x * 0.01, y * 0.01, f_noise) - 0.5;
			ellipse(x + addnoise, y + addnoise, H_GRID);
		}
	}
	Framecount++;
}


