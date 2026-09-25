#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUNDCOLOR = 0;
const int BACKGROUNDGRAYSCALE = 0;
const int DIA = 50;
const int RECTNUM = 3 * 4;
const int ALPHA = 1;

struct RECT
{
	int x;
	int y;
	int r;
	int g;
	int b;
	int alpha;

	void Set(int set_x,int set_y,int set_r,int set_g,int set_b, int set_alpha) {
		x = set_x;
		y = set_y;
		r = set_r;
		g = set_g;
		b = set_b;
		alpha = set_alpha;
	}

	void Update() {

		switch ((int)random(1, 5)) {
		case 1:x += DIA;
			break;
		case 2:x -= DIA;
			break;
		case 3:y += DIA;
			break;
		case 4:y -= DIA;
			break;
		}

		if (x < 0) x = 0;
		if (x > WIDTH - DIA) x = WIDTH - DIA;
		if (y < 0) y = 0;
		if (y > HEIGHT - DIA) y = HEIGHT - DIA;

		stroke(r, g, b, alpha);
		strokeWeight(5);
		rect(x, y, DIA, DIA);
	}
};

RECT rects[RECTNUM];

void setup( ) {
	size(WIDTH,HEIGHT);
	background(BACKGROUNDCOLOR);
	noFill();

	for (int i = 0; i < RECTNUM; i++)
	{
		switch ((int)i % 4)
		{
		case 0:rects[i].Set(0, 0, 255, 0, 0, ALPHA);
			break;
		case 1:rects[i].Set(WIDTH, 0, 0, 255, 0, ALPHA);
			break;
		case 2:rects[i].Set(0, HEIGHT, 0, 0, 255, ALPHA);
			break;
		case 3:rects[i].Set(WIDTH, HEIGHT, 0, 0, 0, 15);
			break;
		}
	}
	
}

void draw( ) {
	background(BACKGROUNDCOLOR, BACKGROUNDGRAYSCALE);

	for (int i = 0; i < RECTNUM; i++){
		rects[i].Update();
	}
}


