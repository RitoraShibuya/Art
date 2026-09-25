#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 180;
const double X_SCALE = 0.001;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
}

void draw( ) {
	background( BACK_H, MAX_S, MAX_B );

	double mx = ( double )getMouseX( ) / WIDTH;
	double my = ( double )getMouseY( ) / HEIGHT;

	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			int x = ( int )( i + j * mx + i * j * X_SCALE ) % WIDTH;
			int y = ( int )( j + i * my ) % HEIGHT;
			int col_h = x % MAX_H;

			stroke( col_h, MAX_S, MAX_B );
			point( x, y );
		}
	}
}


