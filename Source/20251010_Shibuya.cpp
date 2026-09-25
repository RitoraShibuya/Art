#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID_SIZE = 20;
const double NOISERANGE = 0.02;

int Framecount = 0;
bool RotateSwitch = false;
double ang;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOL );
	setFrameRate( 30 );
	stroke( 255 );
	noFill( );
	strokeWeight( 10 );
	colorMode( HSB, 360, 100, 100 );

}

void draw( ) {
	background( BACKCOL );

	if ( Framecount % 30 == 0 ) {
		RotateSwitch = !RotateSwitch;
	}
	if ( !RotateSwitch ) {

		ang+= 1;
	}
	for ( int x = 0; x < WIDTH; x += GRID_SIZE ) {
		for ( int y = 0; y < HEIGHT; y += GRID_SIZE ) {
			rotate( radians( ang ) );
			int r, g, b;
			r = noise( x * NOISERANGE, y * NOISERANGE, Framecount * NOISERANGE ) * 360;
			stroke( r, 100, 100 );
			rect( x, y, GRID_SIZE, GRID_SIZE );
		}
	}
	Framecount++;
}
