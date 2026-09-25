#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_R = 55;
const int BACK_G = 255;
const int BACK_B = 255;
const int RGB_MAX = 255;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_B, BACK_G );
}

void draw( ) {
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double col_r = ( i * i + j * j ) % RGB_MAX;
			double col_g = ( j * j + i * i ) % RGB_MAX;
			double col_b = ( i * j + _frame_count * i ) % RGB_MAX;
			double alpha = ( i * j + _frame_count * j ) % RGB_MAX;
			stroke( col_r, col_g, col_b, alpha );
			point( i, j );
		}
	}
	_frame_count++;
}


