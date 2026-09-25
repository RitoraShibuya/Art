#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int RGB_MAX = 255;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double col_r = i * i + j % RGB_MAX;
			double col_b = i * j + j % RGB_MAX;
			double col_g = i * _frame_count % RGB_MAX;

			stroke( col_r, col_b, col_g );
			point( i, j );
		}
	}
	_frame_count++;
}


