#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACKGROUND = 25;

const int RGB_MAX = 255;
const int NOISE_RANGE = 100;
const double NOISE_SCALE = 0.005;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	double x_range = getMouseX( ) * NOISE_SCALE;
	double y_range = getMouseY( ) * NOISE_SCALE;

	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double n1 = i * NOISE_SCALE;
			double n2 = j * NOISE_SCALE;
			double n3 = _frame_count * NOISE_SCALE;

			double col_r = noise( n1, n2, n3 ) * RGB_MAX;
			double col_g = noise( n1 + x_range, n2, n3 ) * RGB_MAX;
			double col_b = noise( n1, n2 + y_range, n3 ) * RGB_MAX;

			stroke( col_r, col_g, col_b );
			point( i, j );
		}
	}
	_frame_count++;
}


