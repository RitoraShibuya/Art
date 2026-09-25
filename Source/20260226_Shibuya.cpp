#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 25;

const int RGB_MAX = 255;
const double X_RANGE = 0.01;
const double Y_RANGE = 0.001;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	double ang = PI2 * ( _frame_count % 360 ) / 360;
	for ( int i = 0; i < WIDTH; i++ ) {
		int col_r = ( int )map( i, 0, WIDTH, 0, RGB_MAX );
		for ( int j = 0; j < HEIGHT; j++ ) {
			int col_g = ( int )map( j, 0, HEIGHT, 0, RGB_MAX );
			int col_b = ( int )( ( cos( ang + i * X_RANGE + j * Y_RANGE ) * 0.5 + 0.5 ) * RGB_MAX );
			stroke( col_r, col_g, col_b );
			point( i, j );
		}
	}
	_frame_count++;
}


