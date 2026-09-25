#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 50;

const int RECT_GRAY = 255;
const int STROKE_WEIGHT = 50;
const int CENTER_X_RANGE = 200;
const int CENTER_Y_RANGE = 200;
const int RECT_DIA = 300;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	setFrameRate( 6 );
	rectMode( CENTER );

	noFill( );
	stroke( RECT_GRAY );
	strokeWeight( STROKE_WEIGHT );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	double rand_x = random( -CENTER_X_RANGE, CENTER_X_RANGE );
	double rand_y = random( -CENTER_Y_RANGE, CENTER_Y_RANGE );
	double x = CENTER_X + rand_x;
	double y = CENTER_Y + rand_y;
	double ang = atan2( rand_y, rand_x );

	rotate( ang );
	rect( x, y, RECT_DIA, RECT_DIA );
}


