#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int BACKCOL = 0;
const int L_NUM = 50;

int gap = 0;

struct White_L {
	int x, y;
	int oldx, oldy;
	double ang;
};

White_L w_l[ L_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	colorMode(HSB, 360, 100, 100);
	gap = 750;

	for (int i = 0; i < L_NUM; i++)
	{
		w_l[ i ].ang = PI2 * i / L_NUM + noise(w_l[ i ].x * 0.01, w_l[ i ].y * 0.01, gap * 0.02);
		w_l[ i ].x = CX + cos(w_l[ i ].ang) * gap;
		w_l[ i ].y = CY + sin(w_l[ i ].ang) * gap;
		w_l[ i ].oldx = w_l[ i ].x;
		w_l[ i ].oldy = w_l[ i ].y;
	}
}

void draw( ) {
	background(BACKCOL, 1);

	if (gap <= 0) {
		gap = 750;
		for (int j = 0; j < L_NUM; j++)
		{
			w_l[ j ].ang = PI2 * j / L_NUM + noise(w_l[ j ].x * 0.01, w_l[ j ].y * 0.01, gap * 0.02);
			w_l[ j ].oldx = CX + cos(w_l[ j ].ang) * gap;
			w_l[ j ].oldy = CY + sin(w_l[ j ].ang) * gap;
		}
	}



	for (int i = 0; i < L_NUM; i++)
	{
		w_l[ i ].ang = PI2 * i / L_NUM + noise(w_l[ i ].x * 0.01, w_l[ i ].y * 0.01, gap * 0.02);

		w_l[ i ].x = CX + cos(w_l[ i ].ang) * gap;
		w_l[ i ].y = CY + sin(w_l[ i ].ang) * gap;

		stroke(noise(gap * 0.05, w_l[ i ].x * 0.02 + 50, w_l[ i ].y * 0.02 + 50) * 360, 100, 100);

		line(w_l[ i ].x, w_l[ i ].y, w_l[ i ].oldx, w_l[ i ].oldy);
		//point(w_l[ i ].x, w_l[ i ].y);

		w_l[ i ].oldx = w_l[ i ].x;
		w_l[ i ].oldy = w_l[ i ].y;
	}

	gap -= 3;
}


