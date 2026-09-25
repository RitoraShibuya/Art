#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int CIRCLE_GRAY = 255;
const int GAP = 300;
const int VERTEX_MIN = 3;
const int VERTEX_MAX = 100;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( CIRCLE_GRAY );
}

void draw( ) {
	background( BACKGROUND );

	int mx = getMouseX( );
	int my = getMouseY( );

	int vnum = ( int )map( mx + my, 0, WIDTH + HEIGHT, VERTEX_MIN,VERTEX_MAX );
	beginShape( );
	for ( int i = 0; i < vnum; i++ ) {
		double ang = PI2 * i / vnum;
		int x = CENTER_X + cos( ang ) * GAP;
		int y = CENTER_Y + sin( ang ) * GAP;
		vertex( x, y );
		line( CENTER_X, CENTER_Y, x, y );
	}
	endShape( CLOSE );
}


