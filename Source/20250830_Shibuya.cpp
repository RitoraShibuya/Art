#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int GAP = 200;   // îºåaÇÃç≈ëÂíl
const double NOISE_SCALE = 0.01;
const double COL_NOISE_SCALE = 0.05;


int ang = 0;
int cx = 0;
int x_add = 2;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKGROUND);
}

void draw( ) {
	background(BACKGROUND, 2);

	int cy = HEIGHT / 2;

	for (int i = 0; i < 360; i++) {
		double rad = radians(ang + i);
		double radius = GAP;

		// äÓñ{ç¿ïWÅiï˙éÀèÛÇ…çLÇ™ÇÈÅj
		double sx = cx + cos(rad) * radius;
		double sy = cy + sin(rad) * radius;

		// ÉmÉCÉYÇ≈óhÇÁÇ∑
		double nx = sx + (noise(sx * NOISE_SCALE, sy * NOISE_SCALE) - 0.5) * 300;
		double ny = sy + (noise(sy * NOISE_SCALE, sx * NOISE_SCALE) - 0.5) * 300;

		stroke((noise(nx * COL_NOISE_SCALE, ny * COL_NOISE_SCALE, ang * COL_NOISE_SCALE))*400,
			   (noise(nx + 100 * COL_NOISE_SCALE, ny * COL_NOISE_SCALE, ang * COL_NOISE_SCALE))*400,
			   (noise(nx * COL_NOISE_SCALE, ny + 100 * COL_NOISE_SCALE, ang * COL_NOISE_SCALE))*400);
		point(nx, ny);
	}
	ang += 2; // âÒì]Ç≥ÇπÇÈ
	cx+=x_add;
	if (cx >= WIDTH)
	{
		cx = 0;
		x_add = (int)random(1, 5);
	}
}
