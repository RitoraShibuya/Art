#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_R = 255;
const int BACK_G = 0;
const int BACK_B = 0;
const int MIN_GAP = 200;
const int MAX_GAP = 1000;
const int GAP_SPD = 5;
const double COL_GAP_RANGE = 0.08;

int _frame_count = 0;
int _max_gap = MIN_GAP;

int clamp( int val, int min, int max ) {
	if ( val > max ) {
		val = max;
	} else if ( val < min ) {
		val = min;
	}
	return val;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_B, BACK_G );
}

void draw( ) {
	int mx = getMouseX( );
	int my = getMouseY( );

	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double col_r = ( i * i + j ) % _max_gap;
			double col_g = ( int )( j * j + i * j * COL_GAP_RANGE ) % _max_gap;
			double col_b = ( j * i * _frame_count ) % _max_gap;

			stroke( col_r, col_g, col_b );
			point( i, j );
		}
	}

	_frame_count++;
	_max_gap--;
	_max_gap = clamp( _max_gap, MIN_GAP, MAX_GAP );
}

void mouseDragged( ) {
	_max_gap += GAP_SPD;
}
