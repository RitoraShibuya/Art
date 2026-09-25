#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACKCOL = 0;
const int DIA = 100;
const int SPD = DIA / 2;

int Framecount = 0;

struct Peinter {
	int x, y;
};

Peinter p_e;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	colorMode(HSB, 360, 100, 100,100);
	noStroke( );
	blendMode(ADD);
}

void draw( ) {
	p_e.y += SPD;
	if (p_e.y >= HEIGHT + DIA / 2)
	{
		if (p_e.x >= WIDTH + DIA / 2) {
			p_e.x = 0;
		}
		else {
			p_e.x += DIA / 2;
		}
		p_e.y = 0;
	}
	int h = noise(p_e.x * 0.05, p_e.y * 0.05, Framecount * 0.05)*360;
	fill(h,100,100,25);
	ellipse(p_e.x, p_e.y,DIA);
	
	Framecount++;
}

void mouseClicked( ) {
	background(BACKCOL , 75);
}

