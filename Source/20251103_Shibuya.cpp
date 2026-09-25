#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID = 4;
const int H_GRID = GRID / 2;

int Framecount = 0;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noFill( );
	colorMode(HSB, 360, 100, 100);
}

void draw( ) {
	background(BACKCOL,1);
	double mx = getMouseX( );
	double my = getMouseY( );
	double m_noise = mx + my * 0.01;
	double f_noise = Framecount * 0.03;
	for (int x = H_GRID; x < WIDTH; x += GRID)
	{
		for (int y = H_GRID; y < HEIGHT; y += GRID)
		{
			double h = map(noise(x * 0.01, y * 0.03, m_noise + f_noise),0,1,360,0);
			stroke(h, 100, 100);
			point(x, y);
		}
	}
	Framecount++;
}


