#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int SPD = 2;

int Framecount = 0;

struct Col_R1 {
	double x, y;
};

struct Col_R2 {
	double x, y;
};

Col_R1 rect1[ WIDTH ];
Col_R2 rect2[ WIDTH ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke( );
	blendMode(ADD);
	for (int i = 0; i < WIDTH; i++)
	{
		rect1[ i ].x = 0;
		rect2[ i ].x = WIDTH;
		rect1[ i ].y = i;
		rect2[ i ].y = i;
	}
}

void draw( ) {
	//background(BACKCOL, 5);
	for (int i = 0; i < WIDTH; i++)
	{
		double x1 = rect1[ i ].x;
		double y1 = rect1[ i ].y;
		double x2 = rect2[ i ].x;
		double y2 = rect2[ i ].y;

		if (rect1[ i ].x >= WIDTH) rect1[ i ].x = 0;
		if (rect2[ i ].x <= 0) rect2[ i ].x = WIDTH;


		rect1[ i ].x += noise(x1 * 0.01, y1 * 0.01, Framecount * 0.01) * SPD;
		rect2[ i ].x -= noise(x2 * 0.01, y2 * 0.01, Framecount * 0.01) * SPD;
		rect1[ i ].y = i;
		rect2[ i ].y = i;

		fill(noise(x1 * 0.05, y1 * 0.05, Framecount * 0.01) * 255,
			 noise(x1 + 300 * 0.05, y1 * 0.05, Framecount * 0.01) * 255,
			 noise(x1 * 0.05, y1 + 300 * 0.05, Framecount * 0.01) * 255, 50);
		rect(x1, y1, 1, 1);

		fill(noise(x2 * 0.05, y2 * 0.05, Framecount * 0.01) * 255,
			 noise(x2 + 300 * 0.05, y2 * 0.05, Framecount * 0.01) * 255,
			 noise(x2 * 0.05, y2 + 300 * 0.05, Framecount * 0.01) * 255, 50);
		rect(x2, y2, 1, 1);
	}
	Framecount++;
}


