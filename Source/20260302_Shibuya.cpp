#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACKGROUND = 25;
const int RGB_MAX = 256;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	for ( int i = 0; i < WIDTH; i++ ) {
		int col_r = i + _frame_count % RGB_MAX;
		for ( int j = 0; j < HEIGHT; j++ ) {
			int col_g = j + _frame_count % RGB_MAX;
			int col_b = ( i + j ) + _frame_count % RGB_MAX;
			stroke( col_r, col_g, col_b );
			point( i, j );
		}
	}
	_frame_count++;
}


