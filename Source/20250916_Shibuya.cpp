#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 255;
const int GAP = 25;
const int DIA = 50;
const double NOISERANGE = 0.01;

int framecount;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);

	framecount = 0;
}

void draw( ) {
	background(BACKCOLOR,1);
	fill(255);
	ellipse(getMouseX( ), getMouseY( ), 200);
	blendMode(MULTIPLY);
	for (int x = 0; x <= WIDTH; x += GAP)
	{
		for (int y = 0; y <= HEIGHT; y += GAP)
		{
			double r = noise(x * NOISERANGE, y * NOISERANGE, framecount * NOISERANGE) * 255;
			double g = noise(x * NOISERANGE + 100, y * NOISERANGE, framecount * NOISERANGE) * 255;
			double b = noise(x * NOISERANGE, y * NOISERANGE + 100, framecount * NOISERANGE) * 255;
			fill(r, g, b);
			ellipse(x, y, DIA);
		}
	}
	blendMode(BLEND);
	framecount++;
}


