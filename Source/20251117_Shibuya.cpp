#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 255;
const int START_X = 0;
const int LAST_X = WIDTH;
const int GRAY = 50;
const int ALPHA = 5;
const int WEIGHT = 5;
const int LINE_NUM = 1000;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( GRAY, ALPHA );
	strokeWeight( WEIGHT );

	for ( int i = 0; i < LINE_NUM; i++ ) {
		int y1 = ( int )random( HEIGHT );
		int y2 = ( int )random( HEIGHT );

		line( START_X, y1, LAST_X, y2 );
	}
}


