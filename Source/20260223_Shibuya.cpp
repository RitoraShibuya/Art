#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int STROKE_GRAY = 255;
const int STROKE_ALPHA = 10;
const int CIRCLE_DIA = 20;
const double X_FIRST = 0.123456;

double _x = X_FIRST;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noFill( );
	stroke( STROKE_GRAY, STROKE_ALPHA );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	for ( int i = 0; i < HEIGHT; i++ ) {
		_x = 4.0 * _x * ( 1.0 - _x );
		int pos_x = ( int )( _x * WIDTH );
		ellipse( pos_x, i, CIRCLE_DIA );
	}
}


