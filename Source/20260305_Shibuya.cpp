#include "Processing.h"

const int WIDTH = 250;
const int HEIGHT = 250;
const int BACK_H = 300;
const int BACK_S = 100;
const int BACK_B = 100;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int MAX_GAP = 500;

int _frame_count = 0;

double warp( double num, double max ) {
	while ( num > max ) {
		num -= max;
	}
	return num;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, BACK_S, BACK_B );
}

void draw( ) {
	Vector2 center( WIDTH / 2, HEIGHT / 2 );
	Vector2 old = center;
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double ang = warp( i * i + j, PI2 );
			double gap = warp( i + j * j + _frame_count, MAX_GAP );
			Vector2 pos = center + Vector2( gap, 0.0 ).rotate( ang );

			double col_h = warp( i + j, MAX_H );

			stroke( col_h, MAX_S, MAX_B );
			line( old, pos );
			old = pos;
		}
	}
	_frame_count++;
}


