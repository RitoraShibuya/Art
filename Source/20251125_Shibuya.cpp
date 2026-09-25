#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int GRAY = 255;
const int ALPHA = 20;
const int GRID = 10;
const int GRID_W = WIDTH / GRID;
const int GRID_H = HEIGHT / GRID;
const int SPD = 2;
const double NOISE_RANGE = 0.01;

int _frame_count = 0;

struct ColPoint {
	double x = 0;
	double y = 0;
	double rad = 0;
};

ColPoint _colp[ GRID_W ][ GRID_H ];

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	for ( int i = 0; i < GRID_W; i++ ) {
		for ( int j = 0; j < GRID_H; j++ ) {
			_colp[ i ][ j ].x = i * GRID;
			_colp[ i ][ j ].y = j * GRID;
		}
	}
}

void draw( ) {
	stroke( GRAY, ALPHA );
	for ( int i = 0; i < GRID_W; i++ ) {
		for ( int j = 0; j < GRID_H; j++ ) {

			ColPoint& it = _colp[ i ][ j ];
			double x_noise = it.x * NOISE_RANGE;
			double y_noise = it.y * NOISE_RANGE;
			double f_noise = _frame_count * NOISE_RANGE;
			it.rad = noise( x_noise, y_noise, f_noise ) * PI;
			it.x += cos( it.rad ) * SPD;
			it.y += sin( it.rad ) * SPD;

			point( it.x, it.y );
		}
	}

	_frame_count++;
}


