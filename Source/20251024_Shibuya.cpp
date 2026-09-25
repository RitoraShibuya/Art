#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID_SIZE = 50;
const int R_SIZE = 10;

int Framecount = 0;

struct P_R {
	int x, y;
	int dia;
	int x0, x1;
	int y0, y1;
};

P_R p_l;

int threecolor(int x, int y) {
	double n_col = noise(x * 0.01, y * 0.01, Framecount * 0.01);

	p_l.x0 = p_l.x - p_l.dia / 2;
	p_l.x1 = p_l.x + p_l.dia / 2;
	p_l.y0 = p_l.y - p_l.dia / 2;
	p_l.y1 = p_l.y + p_l.dia / 2;

	if (x > p_l.x0 && x < p_l.x1 && y > p_l.y0 && y < p_l.y1) {
		return 255;
	}
	else {
		if (n_col > 0.6) {
			return 255;
		}
		else if (n_col > 0.4) {
			return 122;
		}
		else {
			return 0;
		}
	}
	
}

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke( );
	rectMode(CENTER);

	p_l.x = getMouseX( );
	p_l.y = getMouseY( );
	p_l.dia = 200;
}

void draw( ) {
	background(BACKCOL,10);

	p_l.x = getMouseX( );
	p_l.y = getMouseY( );

	for (int x = 0 + GRID_SIZE / 2; x < WIDTH; x += GRID_SIZE)
	{
		for (int y = 0 + GRID_SIZE / 2; y < HEIGHT; y += GRID_SIZE)
		{
			
			fill(threecolor(x, y));
			rect(x, y, R_SIZE, R_SIZE);
		}
	}
	Framecount++;
}


