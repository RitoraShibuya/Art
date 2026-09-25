#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int MAXGAP = 200;
const double NOISERANGE = 0.05;

int mx, my;
int gap;
int Framecount;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	setFrameRate(10);
	Framecount = 0;
}

void draw( ) {
	for (int i = 0; i < 360; i++)
	{
		double noisegap = noise(mx * NOISERANGE, my * NOISERANGE, i * NOISERANGE);
		int x = mx + cos(radians(i)) * gap * noisegap;
		int y = my + sin(radians(i)) * gap * noisegap;
		stroke(255);
		fill(255);
		ellipse(x, y, 5);
	}

	if (gap <= MAXGAP)
	{
		gap += 1;
	}
	else {

	}

	blendMode(MULTIPLY);
	for (int nx = 0; nx < WIDTH; nx += 5)
	{
		for (int ny = 0; ny < HEIGHT; ny += 5)
		{
			int r = noise(nx * NOISERANGE, ny * NOISERANGE, Framecount * NOISERANGE) * 255;
			int g = noise(nx * NOISERANGE + 100, ny * NOISERANGE, Framecount * NOISERANGE) * 255;
			int b = noise(nx * NOISERANGE, ny * NOISERANGE + 100, Framecount * NOISERANGE) * 255;
			fill(r, g, b);
			noStroke( );
			ellipse(nx, ny, 5);
		}
	}
	blendMode(BLEND);
	Framecount += 2;

}

void mouseClicked( ) {
	gap = 0;
	mx = getMouseX( );
	my = getMouseY( );
}

