#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int DIA = 300;
const double NOISERANGE = 0.01;

double framecount;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	rectMode(CENTER);
	setFrameRate(30);
}

void draw() {
	background(BACKCOLOR);
	int mx = getMouseX();
	int my = getMouseY();
	stroke(255, 120, 120);
	strokeWeight(10);
	rect(mx, my, DIA, DIA);
	for (int x = mx - DIA / 2; x < mx + DIA / 2; x++)
	{
		for (int y = my - DIA / 2; y < my + DIA / 2; y++)
		{
			stroke((noise(x * NOISERANGE, y * NOISERANGE, framecount * NOISERANGE) * 255), (noise(x + 100 * NOISERANGE, y * NOISERANGE, framecount * NOISERANGE) * 255), (noise(x * NOISERANGE, y + 100 * NOISERANGE, framecount * NOISERANGE) * 255));
			point(x, y);
		}
	}
	framecount += 1;
}


