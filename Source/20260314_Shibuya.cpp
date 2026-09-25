#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_H = 300;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int GRID_SIZE = 20;
const int GRID_RADIUS = GRID_SIZE / 2;
const int GRID_NUM_W = WIDTH / GRID_SIZE;
const int GRID_NUM_H = HEIGHT / GRID_SIZE;
const int MAX_DIA = GRID_SIZE * 3;
const double COL_GAP_RANGE = 0.01;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
	noStroke( );
}

void draw( ) {
	for ( int i = 0; i < GRID_NUM_W; i++ ) {
		for ( int j = 0; j < GRID_NUM_H; j++ ) {
			int dia = ( i * i + j + _frame_count ) % MAX_DIA;
			int col_h = ( int )( j * j + i * j * _frame_count * COL_GAP_RANGE ) % MAX_H;
			int x = GRID_RADIUS + i * GRID_SIZE;
			int y = GRID_RADIUS + j * GRID_SIZE;

			fill( col_h, MAX_S, MAX_B );
			ellipse( x, y, dia );
		}
	}
	_frame_count++;
}


