#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int GRID_SIZE = 20;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const int MAX_DIA = GRID_SIZE * 6;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	noFill( );
}

void draw( ) {
	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		for ( int j = 0; j < GRID_NUM_HEIGHT; j++ ) {
			int x = i * GRID_SIZE;
			int y = j * GRID_SIZE;
			int dia = ( i * j - j + _frame_count ) % MAX_DIA;

			int col_h = ( j * j + _frame_count ) % MAX_H;

			stroke( col_h, MAX_S, MAX_B );
			ellipse( x, y, dia );
		}
	}
	_frame_count++;
}


