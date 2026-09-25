#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 330;
const int LOOP_RANGE = 500;
const double NOISE_SCALE = 0.001;
const double GAP_RANGE = 0.01;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
}

void draw( ) {
	background( BACK_H, MAX_S, MAX_B );

	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double n1 = ( i * i + j ) % LOOP_RANGE * NOISE_SCALE;
			double n2 = (int)( j * j + i * j * GAP_RANGE ) % LOOP_RANGE * NOISE_SCALE;
			double n3 = ( i * j * _frame_count ) % LOOP_RANGE * NOISE_SCALE;
			int col_h = ( int )( noise( n1, n2, n3 ) * MAX_H );

			stroke( col_h, MAX_S, MAX_B );
			point( i, j );
		}
	}
	_frame_count++;
}


