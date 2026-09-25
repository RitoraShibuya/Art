#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int COL_ALPHA = 3;
const int GRID_SIZE = 10;
const int GAP_SCALE = 130;
const int GRID_NUM_X = WIDTH / GRID_SIZE;
const int GRID_NUM_Y = WIDTH / GRID_SIZE;
const int COUNT_SCALE = 750;
const double ANG_SCALE = 0.001;
const double NOISE_SCALE = 0.00007;

int _grid_colors[ GRID_NUM_X ][ GRID_NUM_Y ];

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	noStroke( );
}

void draw( ) {
	double mx = getMouseX( );
	double my = getMouseY( );
	double make_sin = sin(getFrameCount() * ANG_SCALE);
	int count_sin = (int)(make_sin * COUNT_SCALE);

	for ( int i = 0; i < GRID_NUM_X; i++ ) {
		int x = i * GRID_SIZE;
		for ( int j = 0; j < GRID_NUM_Y; j++ ) {
			int y = j * GRID_SIZE;

			double n1 = ( i + mx ) * j * NOISE_SCALE;
			double n2 = ( j + my ) * i * NOISE_SCALE;
			double n3 = ( i + j ) * count_sin * NOISE_SCALE;
			double make_noise = noise( n1, n2,n3 );
			double gap = make_noise * GAP_SCALE;
			int col_h = (int)(make_noise * MAX_H + gap) % MAX_H;
			int col_b = ( int )( make_noise * MAX_B + gap) % MAX_B;

			fill( col_h, MAX_S, col_b ,COL_ALPHA);
			rect( x, y, GRID_SIZE, GRID_SIZE );
		}
	}
}


