#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int MAX_DIA = 500;
const int GRAY = 255;
const int ALPHA = 20;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	noFill( );
	stroke( GRAY, ALPHA );
}

void draw( ) {
	int x = ( int )random( WIDTH );
	int y = ( int )random( HEIGHT );
	int dia = ( int )random( MAX_DIA );

	rect( x, y, dia, dia );
}


