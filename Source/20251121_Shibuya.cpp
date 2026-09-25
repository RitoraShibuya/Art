#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int MAX_DIA = 500;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int ALPHA = 10;
const double NOISE_RANGE = 0.01;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
}

void draw( ) {

	int x = ( int )random( WIDTH );
	int y = ( int )random( HEIGHT );
	int dia = ( int )random( MAX_DIA );
	double x_noise = x * NOISE_RANGE;
	double y_noise = y * NOISE_RANGE;
	double d_noise = dia * NOISE_RANGE;
	int h = noise( x_noise, y_noise, d_noise ) * MAX_H;
	fill( h, MAX_S, MAX_B, ALPHA );

	ellipse( x, y, dia );
}



