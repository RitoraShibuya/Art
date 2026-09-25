#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 1;
const int GRAY = 255;
const int DIA_WIDTH = 50;
const int DIA_HEIGHT = DIA_WIDTH / 2;
const int SPEED = 3;
const int MOVE_DIR_COUNT = 2;     
const double ROT_SPEED_BASE = 0.03; 

struct Step {
	int x = CENTER_X;
	int y = CENTER_Y;
	double ang = 0;
};

Step _stairs;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	fill( GRAY );
}

void draw( ) {

	background( BACKGROUND , BACK_ALPHA);
	int rand_x = ( int )random( MOVE_DIR_COUNT );
	int rand_y = ( int )random( MOVE_DIR_COUNT );
	if ( rand_x == 0 ) {
		_stairs.x += SPEED;
	} else {
		_stairs.x += -SPEED;
	}
	if ( rand_y == 0 ) {
		_stairs.y += SPEED;
	} else {
		_stairs.y += -SPEED;
	}
	
	if ( _stairs.x > WIDTH ) {
		_stairs.x -= WIDTH;
	}
	if ( _stairs.x < 0 ) {
		_stairs.x += WIDTH;
	}
	if ( _stairs.y > HEIGHT ) {
		_stairs.y -= HEIGHT;
	}
	if ( _stairs.y < 0 ) {
		_stairs.y += HEIGHT;
	}

	_stairs.ang += ROT_SPEED_BASE * PI;

	rotate( _stairs.ang );
	rect( _stairs.x, _stairs.y, DIA_WIDTH, DIA_HEIGHT );
	rotate( -_stairs.ang );
}


