#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 180;
const int BACK_S = 0;
const int BACK_B = 20;

int _frame_count = 0;

double warp( double val, double max ) {
	if ( val > max ) {
		val -= max;
	} else if ( val < 0 ) {
		val += max;
	}
	return val;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, BACK_S, BACK_B );
}

void draw( ) {
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double x = i * ( j + _frame_count );
			double y = j + ( x * _frame_count );
			x = warp( x, WIDTH );
			y = warp( y, HEIGHT );

			int col_h = ( int )warp( x, MAX_H );

			stroke( col_h, MAX_S, MAX_B );
			point( x, y );
		}
	}
	_frame_count++;
}


