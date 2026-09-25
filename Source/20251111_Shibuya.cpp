#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int ALPHA = 10;
const int GRID = 10;
const int HALF_GRID = GRID / 2;
const int X_COUNT = WIDTH / GRID;
const int Y_COUNT = HEIGHT / GRID;
const int COUNT = X_COUNT * Y_COUNT;
const double NOISE_RANGE = 0.01;
const double ANG_SPD = 0.01;

double _base_ang = 0;

struct ColorSphere {
	int x = 0;
	int y = 0;
	double ang = 0;
};

ColorSphere _ellipses[ X_COUNT ][ Y_COUNT ];

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
	for ( int i = 0; i < X_COUNT; i++ ) {
		for ( int j = 0; j < Y_COUNT; j++ ) {
			_ellipses[ i ][ j ].x = HALF_GRID + i * GRID;
			_ellipses[ i ][ j ].y = HALF_GRID + j * GRID;
		}
	}
}

void draw( ) {
	background( BACKGROUND, ALPHA );
	for ( int i = 0; i < X_COUNT; i++ ) {
		for ( int j = 0; j < Y_COUNT; j++ ) {
			auto it = _ellipses[ i ][ j ];
			it.ang = noise( it.x * NOISE_RANGE, it.y * NOISE_RANGE ) + _base_ang;
			it.x += cos( it.ang ) * GRID;
			it.y += sin( it.ang ) * GRID;
			fill( 255 );
			ellipse( it.x, it.y, HALF_GRID );
		}
	}
	_base_ang += ANG_SPD;
}


