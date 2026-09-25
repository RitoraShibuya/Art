#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int MAX_DIA = 500;
const int GRAY = 255;
const int ALPHA = 50;
const int MAX_CIRCLE = 2000;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noFill( );
	stroke( GRAY, ALPHA );

	for ( int i = 0; i < MAX_CIRCLE; i++ ) {
		int x = ( int )random( WIDTH );
		int y = ( int )random( HEIGHT );
		int dia = ( int )random( MAX_DIA );

		ellipse( x, y, dia );
	}
}

void draw( ) {
	int x = ( int )random( WIDTH );
	int y = ( int )random( HEIGHT );
	int dia = ( int )random( MAX_DIA );

	ellipse( x, y, dia );
}

void mouseClicked( ) {
	setup( );
}


