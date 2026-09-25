#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int BACKCOL = 200;
const int E_NUM = 8;
const double NOISERANGE = 0.01;

int Framecount;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke( );
	colorMode(HSB, 360, 100, 100);
	Framecount = 0;
}

void draw( ) {
	background(BACKCOL,5);

	for (int i = 0; i < 4; i++) {
		int e_num = E_NUM + ( i * 2 );
		for (int c = 0; c < e_num; c++) {
			double ang = radians(360.0 / e_num * c);
			int x = CX + cos(ang) * ( i + 1 ) * 100;
			int y = CY + sin(ang) * ( i + 1 ) * 100;

			double n = noise(x * NOISERANGE, y * NOISERANGE, Framecount * NOISERANGE);
			n = pow(n, 3.0); // コントラスト強化

			int h = (int)map(n, 0, 1, 0, 360);
			int s = 90;
			int b = (int)map(pow(n, 0.5), 0, 1, 40, 100);

			fill(h, s, b, 10);
			ellipse(x, y, 50);
		}
	}
	Framecount++;
}
