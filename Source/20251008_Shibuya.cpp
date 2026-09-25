#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 255;
const int ALPHA = 10;
const int L_W = 10;
const double NOISERANGE = 0.01;

int Framecount;

enum Mode {
	Wid,
	Hei,
};

Mode mode;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	colorMode(HSB, 360);
	noFill( );
	strokeWeight(L_W);

	Framecount = 0;
}

void draw( ) {
	background(BACKCOL, 1);
	if (Framecount % 30 == 0) {
		int r;
		switch (mode) {
		case Wid:
			for (int x = 0; x < WIDTH; x++)
			{
				r = noise(x * NOISERANGE, HEIGHT * NOISERANGE, Framecount * NOISERANGE) * 360;
				stroke(r, ALPHA);
				line(x, 0, x, HEIGHT);
			}
			mode = Hei;
			break;
		case Hei:
			for (int y = 0; y < HEIGHT; y++)
			{
				r = noise(WIDTH * NOISERANGE, y * NOISERANGE, Framecount * NOISERANGE) * 360;
				stroke(r, ALPHA);
				line(0, y, WIDTH, y);
			}
			mode = Wid;
			break;
		}
	}
	Framecount++;
}


