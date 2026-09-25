#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int GRAY = 255;
const int ALPHA = 20;
const int CAGE_GAP = 300;
const int CAGE_DIA = CAGE_GAP * 2;
const double CAGE_SPD = 0.02;

struct Cage {
	int x = CENTER_X;
	int y = CENTER_Y;
};

Cage _cage;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( GRAY , ALPHA);
}

void draw( ) {

	int mx = getMouseX( );
	int my = getMouseY( );
	int dx = mx - _cage.x;
	int dy = my - _cage.y;

	_cage.x += dx * CAGE_SPD;
	_cage.y += dy * CAGE_SPD;

	ellipse( _cage.x, _cage.y, CAGE_DIA );

}


