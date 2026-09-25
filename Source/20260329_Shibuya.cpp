#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 180;
const int BACK_A = 10;
const int FACE_DIA = 300;
const int EAR_DIA = 180;
const int EAR_DIST = 150;
const double MUL_SCALE = 0.01;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B, BACK_A );
	noStroke( );
}

void draw( ) {
	background( BACK_H, MAX_S, MAX_B, BACK_A );
	int x = getMouseX( );
	int y = getMouseY( );

	int col_h = ( int )( x + y * MUL_SCALE ) + _frame_count % MAX_H;

	fill( col_h, MAX_S, MAX_B );
	ellipse( x, y, FACE_DIA );
	ellipse( x + EAR_DIST, y - EAR_DIST, EAR_DIA );
	ellipse( x - EAR_DIST, y - EAR_DIST, EAR_DIA );

	_frame_count++;
}


