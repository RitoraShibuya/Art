#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_R = 235;
const int BACK_G = 180;
const int RGB_MAX = 255;
const int BACK_B = 200;
const int COL_G_SCALE = 100;
const int COL_B_SCALE = 200;
const double MUL_SCALE_RANGE = 0.005;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_G, BACK_B );
}

void draw( ) {
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double rand_scale = random( MUL_SCALE_RANGE );
			int mul = i * j + i * j * rand_scale + _frame_count;
			double col_r = mul % RGB_MAX;
			double col_g = mul + COL_G_SCALE % RGB_MAX;
			double col_b = mul + COL_B_SCALE % RGB_MAX;

			stroke( col_r, col_b, col_g );
			point( i, j );
		}
	}
	_frame_count++;
}


