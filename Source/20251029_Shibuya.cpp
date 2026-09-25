#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;

int ang = 0;
int cx = 500, cy = 500;
int dx = 0, dy = 0;

struct Col_E {
	int x, y;
};

Col_E c_e = { 500, 500 };

void setup( ) {
	size(WIDTH, HEIGHT);
	background(0);
	noStroke( );
	fill(255);
}

void draw( ) {

	if (ang % 180 == 0) {
		int mx = getMouseX( );
		int my = getMouseY( );

		cx = mx;
		cy = my;

		dx = abs(mx - c_e.x);
		dy = abs(my - c_e.y);
	}

	double t = cos(radians(ang));
	c_e.x = cx + dx * t;
	c_e.y = cy + dy * t;

	ellipse(c_e.x, c_e.y, 20);
	ang++;
}
