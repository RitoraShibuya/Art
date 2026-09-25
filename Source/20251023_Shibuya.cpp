#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int BACKCOL = 0;
const int GAP = 200;

struct E_1 {
	int x, y;
	double ang;
};

E_1 e_1, e_2;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	blendMode(ADD);

	e_1.ang = 0;
	e_1.x = CX + cos(radians(e_1.ang)) * GAP;
	e_1.y = CY + sin(radians(e_1.ang)) * GAP;

	e_2.ang = 180;
	e_2.x = e_1.x + cos(radians(e_2.ang)) * GAP;
	e_2.y = e_1.y + sin(radians(e_2.ang)) * GAP;
}

void draw( ) {
	stroke(255, 50);

	beginShape( );
	for (int i = 0; i < 5; i++) {
		double ang = ( i / 5.0 ) * PI2 + radians(e_2.ang);
		int x = e_2.x + cos(ang) * 10;
		int y = e_2.y + sin(ang) * 10;
		vertex(x, y);
	}
	endShape(CLOSE);


	e_1.x = CX + cos(radians(e_1.ang)) * 150;
	e_1.y = CY + sin(radians(e_1.ang)) * 150;

	e_2.x = e_1.x + sin(5 * radians(e_2.ang)) * cos(radians(e_2.ang)) * GAP;
	e_2.y = e_1.y + sin(5 * radians(e_2.ang)) * sin(radians(e_2.ang)) * GAP;

	e_1.ang++;
	e_2.ang += noise(e_2.x * 0.03, e_2.y * 0.03, e_1.ang * 0.03) * 3;
}


