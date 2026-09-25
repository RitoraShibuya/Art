#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_R = 39;
const int BACK_G = 128;
const int BACK_B = 135;
const int MAX_RGB = 255;
const int COL_G_SCALE = 100;
const int COL_B_SCALE = 200;
const int GRID_SIZE = 10;
const int GRID_RADIUS = GRID_SIZE / 2;
const int MAX_DIA = GRID_SIZE * 2;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const double MUL_SCALE = 4.0;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_G, BACK_B );
}

void draw( ) {
	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		for ( int j = 0; j < GRID_NUM_HEIGHT; j++ ) {
			int x = GRID_RADIUS + i * GRID_SIZE;
			int y = GRID_RADIUS + j * GRID_SIZE;

			int mul = ( int )( i * j + i * j * MUL_SCALE ) + _frame_count;
			int dia = mul % MAX_DIA;

			int col_r = mul % MAX_RGB;
			int col_g = mul + COL_G_SCALE % MAX_RGB;
			int col_b = mul + COL_B_SCALE % MAX_RGB;

			stroke( col_r, col_g, col_b );
			ellipse( x, y, dia );
		}
	}
	_frame_count++;
}


