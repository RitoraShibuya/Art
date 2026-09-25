#include "Processing.h"

const int WIDTH = 1000;

const int HEIGHT = 1000;

const double CENTER_X = (double)WIDTH / 2;

const double CENTER_Y = (double)HEIGHT / 2;

const int BACKGROUND_COLOR = 255;

const int BACKGROUND_GRAYSCALE = 0;

const int MAXELLIPSENUM = 5;

const int DIAMETER = 100;

const int SIZEMIN = 10;

const int SIZEMAX = 50;

const int ANGHIGH = 360;

const int COLORMAX = 255;

double _ang = 0;

double r_x;

double r_y;

double r, g, b;

double color;

void setup( ) {

	size(WIDTH, HEIGHT);

	background(BACKGROUND_COLOR);

	r_x = CENTER_X;

	r_y = CENTER_Y;

	noStroke();
}

void draw( ) {

	int e_size = random(SIZEMIN,SIZEMAX);

	background(BACKGROUND_COLOR,BACKGROUND_GRAYSCALE);

	if (r_x < 0)
	{
		r_x = 1000;

		r = color = random(COLORMAX);

		g = color = random(COLORMAX);

		b = color = random(COLORMAX);

	}
	if (r_x > WIDTH)
	{
		r_x = 0;

		r = color = random(COLORMAX);

		g = color = random(COLORMAX);

		b = color = random(COLORMAX);

	}

	if (r_y < 0)
	{
		r_y = 1000;

		_ang = random(ANGHIGH);

		r = color = random(COLORMAX);

		g = color = random(COLORMAX);

		b = color = random(COLORMAX);
	}
	if (r_y > WIDTH)
	{
		r_y = 0;

		_ang = random(ANGHIGH);

		r = color = random(COLORMAX);

		g = color = random(COLORMAX);

		b = color = random(COLORMAX);
	}

	r_x += cos(radians(_ang)) * e_size;

	r_y += sin(radians(_ang)) * e_size;

	fill(r,g,b);

	rect(r_x, r_y, r_x, r_y);

	_ang++;

}

