#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 5;
const int P_GRAY = 255;
const int P_ALPHA = 20;
const int MAX_COUNT = 10000;
const int FRAME_SPD = 5;

struct Point {
	double x = -0.1;
	double y = 0.1;
};

int _frame_count = 0;

Point _old_point;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( P_GRAY, P_ALPHA );
}

void draw( ) {

	background( BACKGROUND, BACK_ALPHA );

	double mx = getMouseX( );
	double my = getMouseY( );
	double fcount = _frame_count * FRAME_SPD % WIDTH;

	double param_a = map( my, 0, HEIGHT, -1.5, -1 );
	double param_b = map( mx, 0, WIDTH, 0.5, 1.5 );
	double param_c = map( my, 0, HEIGHT, 1.5, 0 );
	double param_d = map( fcount, 0, WIDTH, 1.0, 0.5 );

	for ( int i = 0; i < MAX_COUNT; i++ ) {
		double nx = sin( param_a * _old_point.y ) + param_c * cos( param_a * _old_point.x );
		double ny = sin( param_b * _old_point.x ) + param_d * cos( param_b * _old_point.y );

		_old_point.x = nx;
		_old_point.y = ny;

		int px = ( int )map( nx, -2, 2, 0, WIDTH );
		int py = ( int )map( ny, -2, 2, 0, HEIGHT );

		point( px, py );
	}

	_frame_count++;
}


