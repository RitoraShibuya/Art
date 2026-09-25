#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 200;
const int MAX_GAP = 10;
const int ANG_NOISE_RANGE = 100;
const int COL_NOISE_RANGE = 300;
const double NOISE_SCALE = 0.01;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
}

void draw( ) {
	background( BACK_H, MAX_S, MAX_B );
	double n1 = _frame_count * NOISE_SCALE;
	for ( int i = 0; i < WIDTH; i++ ) {
		double n2 = i * NOISE_SCALE;
		for ( int j = 0; j < HEIGHT; j++ ) {
			double n3 = j * NOISE_SCALE;
			double gap = noise( n1, n2, n3 ) * MAX_GAP;
			double ang = noise( n1, n2 + ANG_NOISE_RANGE, n3 + ANG_NOISE_RANGE ) * PI2;
			double x = i + cos( ang ) * gap;
			double y = j + sin( ang ) * gap;

			double col_h = noise( n1, n2 + COL_NOISE_RANGE, n3 + COL_NOISE_RANGE ) * MAX_H;

			stroke( col_h, MAX_S, MAX_B );
			point( x, y );
		}
	}
	_frame_count++;
}


