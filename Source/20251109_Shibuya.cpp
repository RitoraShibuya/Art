#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int ELLIPSE_NUM = 10;
const int GRID_SIZE = 10;
const int HALF_GRID_SIZE = GRID_SIZE / 2;
const int DOUBLE_GRID_SIZE = GRID_SIZE * 2;
const int COLOR_H_MAX = 360;
const int COLOR_S = 360;
const int COLOR_B = 360;
const double NOISE_RANGE = 0.03;

int _framecount = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, COLOR_H_MAX, COLOR_S, COLOR_B );
}

void draw( ) {
	background( BACKGROUND );

	for ( int i = HALF_GRID_SIZE; i < WIDTH; i += GRID_SIZE ) {
		for ( int j = HALF_GRID_SIZE; j < HEIGHT; j += GRID_SIZE ) {
			double f_noise = noise( i * NOISE_RANGE, j * NOISE_RANGE, _framecount * NOISE_RANGE );
			int size = f_noise * DOUBLE_GRID_SIZE;
			fill( f_noise * COLOR_H_MAX, COLOR_S, COLOR_B );
			ellipse( i, j, size );
		}
	}

	_framecount++;
}


