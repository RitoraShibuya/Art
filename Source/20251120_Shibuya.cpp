#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int ALPHA = 50;
const int ANG_RANGE = 30;
const int SPEED = 2;
const int COUNT = 5000;

struct ColSphere {
	int x = CENTER_X;
	int y = CENTER_Y;
	int ang = 0;
};

ColSphere _col_s;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( 255 );
}

void mouseClicked( ) {
	background( BACKGROUND, ALPHA );

	for ( int i = 0; i < COUNT; i++ ) {
		_col_s.ang += ( int )random( -ANG_RANGE, ANG_RANGE );
		double rad = radians( _col_s.ang );

		_col_s.x += cos( rad ) * SPEED;
		_col_s.y += sin( rad ) * SPEED;

		if ( _col_s.x >= WIDTH ) {
			_col_s.x = 0;
		}
		if ( _col_s.x < 0 ) {
			_col_s.x = WIDTH - 1;
		}
		if ( _col_s.y >= HEIGHT ) {
			_col_s.y = 0;
		}
		if ( _col_s.y < 0 ) {
			_col_s.y = HEIGHT - 1;
		}

		int p2_x = WIDTH - _col_s.x;

		point( _col_s.x, _col_s.y );
		point( p2_x, _col_s.y );
	}
}


