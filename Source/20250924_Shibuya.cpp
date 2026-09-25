#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOL = 0;
const int VER_NUM = 6;
const int GAP = 500;
const double NOISERANGE = 0.01;

struct ColRect {
	double ang;
	int x, y;
};

ColRect vers[ VER_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	strokeWeight(10);
}

void draw( ) {
	int mx = getMouseX( );
	int my = getMouseY( );
	double baseang = atan2(CENTER_Y - my, CENTER_X - mx);
	int r = noise(mx * NOISERANGE, my * NOISERANGE, baseang * NOISERANGE) * 255;
	int g = noise(mx * NOISERANGE + 100, my * NOISERANGE, baseang * NOISERANGE) * 255;
	int b = noise(mx * NOISERANGE, my * NOISERANGE + 100, baseang * NOISERANGE) * 255;
	stroke(r, g, b);
	beginShape( );
	for (int i = 0; i < VER_NUM; i++)
	{
		double angle = baseang + PI2 * i / VER_NUM;
		int gap = (int)map(mx, 0, WIDTH, 0, GAP);
		int x = CENTER_X + sin(angle) * gap;
		int y = CENTER_Y + cos(angle) * gap;
		vertex(x, y);
	}
	endShape(CLOSE);
}


