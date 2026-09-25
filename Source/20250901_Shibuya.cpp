#include "Processing.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int C_GAP = 400;
const int GAP = 300;           // ”¼Œa‚ð‘å‚«‚­
const double NOISERANGE = 1;

static int baseang;
static double e_ang;

void setup() {
	size(WIDTH, HEIGHT);
	background(0);
	stroke(200,200,255);
}

void draw() {
	background(0, 2);
	int center_x = CENTER_X - (GAP / 2) + cos(radians(e_ang)) * C_GAP;
	int center_y = CENTER_Y - (GAP / 2) + sin(radians(e_ang)) * C_GAP;
	for (int i = 0; i < 270; i += 2)
	{
		double ang = radians(i + baseang);
		double bx = cos(ang);
		double by = sin(ang);

		int nx = center_x + (noise(bx * NOISERANGE, by * NOISERANGE,e_ang * 0.01)) * GAP;
		int ny = center_y + (noise(bx * NOISERANGE + 100, by * NOISERANGE, e_ang * 0.01)) * GAP;

		point(nx, ny);
	}
	baseang += 5;
	e_ang += 1;
}
