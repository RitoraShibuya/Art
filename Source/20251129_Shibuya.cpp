#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int LINE_NUM = 100;
const int GAP = 300;
const int GRAY = 255;
const int ALPHA = 10;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( GRAY, ALPHA );
}

void mouseClicked( ) {
	int mx = getMouseX( );
	int my = getMouseY( );

	for ( int i = 0; i < LINE_NUM; i++ ) {
		double rad = random( PI );
		int x1 = mx + cos( rad ) * GAP;
		int y1 = my + sin( rad ) * GAP;

		double rad2 = rad + PI;
		int x2 = mx + cos( rad2 ) * GAP;
		int y2 = my + sin( rad2 ) * GAP;

		line( x1, y1, x2, y2 );
	}
}