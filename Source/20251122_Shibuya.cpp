#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int GRAY = 255;
const int ALPHA = 10;
const int GAP = 1000;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( GRAY, ALPHA );
	blendMode( ADD );
}

void draw( ) {

	double rad = random( PI );
	int x = cos( rad ) * GAP;
	int y = sin( rad ) * GAP;

	double rad2 = rad + ( 0.5 * PI );
	int x2 = cos( rad2 ) * GAP;
	int y2 = sin( rad2 ) * GAP;

	line( x, y, x2, y2 );
}


