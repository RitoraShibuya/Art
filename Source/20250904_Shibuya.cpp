#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int NEARCOLOR = 0;
const int GAP = 10;
const double NOISERANGE = 0.001;

int framecount;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	framecount = 0;
}

void draw( ) {
	for (int x = 0; x < WIDTH; x += GAP)
	{
		for (int y = 0; y < HEIGHT; y += GAP)
		{
			double r = noise(x * NOISERANGE, y * NOISERANGE, framecount * NOISERANGE) * 2550;
			double g = noise(x * NOISERANGE + 100, y * NOISERANGE, framecount * NOISERANGE) * 2550;
			double b = noise(x * NOISERANGE, y * NOISERANGE + 100, framecount * NOISERANGE) * 2550;
			stroke(r, g, b);
			point(x, y);
		}
	}
	framecount++;
}


