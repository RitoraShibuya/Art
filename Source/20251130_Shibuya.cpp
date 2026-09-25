#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int GRAY = 255;
const int BACK_ALPHA = 20;
const int GAP = 250;
const int TOP_Y = CENTER_Y - GAP;
const int BOTTOM_Y = CENTER_Y + GAP;
const int MAP_OUT_MIN = CENTER_X - GAP;
const int MAP_OUT_MAX = CENTER_X + GAP;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( GRAY );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	int mx = getMouseX( );
	int my = getMouseY( );

	int x = ( int )map( mx, 0, WIDTH, MAP_OUT_MIN, MAP_OUT_MAX );
	int x2 = ( int )map( x, MAP_OUT_MIN, MAP_OUT_MAX, MAP_OUT_MAX, MAP_OUT_MIN );

	beginShape( );
	vertex( CENTER_X, TOP_Y );
	vertex( x, CENTER_Y );
	vertex( CENTER_X, BOTTOM_Y );
	vertex( x2, CENTER_Y );
	endShape( CLOSE );

	line( mx, my, CENTER_X, TOP_Y );
	line( mx, my, x, CENTER_Y );
	line( mx, my, CENTER_X, BOTTOM_Y );
	line( mx, my, x2, CENTER_Y );

	int mx2 = ( int )map( mx, 0, WIDTH, WIDTH, 0 );
	int my2 = ( int )map( my, 0, HEIGHT, HEIGHT, 0 );

	line( mx2, my2, CENTER_X, TOP_Y );
	line( mx2, my2, x, CENTER_Y );
	line( mx2, my2, CENTER_X, BOTTOM_Y );
	line( mx2, my2, x2, CENTER_Y );
}
