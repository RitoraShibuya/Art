#include "Processing.h"
#include <cmath>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const double MAX_RGB = 255.0;
const double COLOR_SCALE = 0.009 * MAX_RGB;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
}

void draw( ) {
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double mul = i * j;
			double col_r = std::fmod( ( mul + i ) * COLOR_SCALE, MAX_RGB );
			double col_g = std::fmod( ( mul + j ) * COLOR_SCALE, MAX_RGB );
			double col_b = std::fmod( ( mul * mul + _frame_count) * COLOR_SCALE , MAX_RGB );

			stroke( col_r, col_g, col_b );
			point( i, j );
		}
	}
	_frame_count++;
}


