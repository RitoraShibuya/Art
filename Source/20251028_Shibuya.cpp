#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 500;
const int CX = WIDTH / 2;
const int BACKCOL = 0;
const int S_NUM = 100;
const double SPD = 0.1;

struct Star {
	int x, y;
	double ang;
	int gap;
	int dia;
};

Star stars[ S_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke( );
	for (int i = 0; i < 100; i++)
	{
		stars[ i ].ang = random(360);
		stars[ i ].gap = (int)random(HEIGHT);
		stars[ i ].dia = (int)random(1, 3);
		stars[ i ].x = CX + cos(radians(stars[ i ].ang)) * stars[ i ].gap;
		stars[ i ].y = HEIGHT + sin(radians(stars[ i ].ang)) * stars[ i ].gap;
	}
}

void draw( ) {
	background(25,25,40);

	fill(255);
	for (int i = 0; i < 100; i++)
	{
		stars[ i ].x = CX + cos(radians(stars[ i ].ang)) * stars[ i ].gap;
		stars[ i ].y = HEIGHT + sin(radians(stars[ i ].ang)) * stars[ i ].gap;

		ellipse(stars[ i ].x, stars[ i ].y, stars[ i ].dia);

		stars[ i ].ang += SPD;
	}
}


