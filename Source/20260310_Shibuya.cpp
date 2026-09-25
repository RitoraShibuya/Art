#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_R = 50;
const int BACK_G = 255;
const int BACK_B = 50;
const int RGB_MAX = 255;
const double COLOR_SCALE = 0.001;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_G, BACK_B );
}

void draw( ) {
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			int col_r = i * i + j % RGB_MAX;
			int col_g = _frame_count - j * i + i % RGB_MAX;
			int col_b = ( int )( j * j + i * i * COLOR_SCALE ) % RGB_MAX;

			stroke( col_r, col_g, col_b );
			point( i, j );
		}
	}
	_frame_count++;
}


