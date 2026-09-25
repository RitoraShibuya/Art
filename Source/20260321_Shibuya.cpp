#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 180;
const int GRID_SIZE = 20;
const int GRID_RADIUS = GRID_SIZE / 2;
const int MAX_SIZE = GRID_SIZE * 4;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const double COLOR_SCALE = 0.05;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
	rectMode( CENTER );
}

void draw( ) {
	background( BACK_H, MAX_S, MAX_B );
	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		int x = GRID_RADIUS + i * GRID_SIZE;
		for ( int j = 0; j < GRID_NUM_HEIGHT; j++ ) {
			int y = GRID_RADIUS + j * GRID_SIZE;

			int mul = ( int )( abs( i * j + i * j + _frame_count) * COLOR_SCALE );
			int size = mul  % MAX_SIZE;
			int col_h = mul % MAX_H;

			stroke( col_h, MAX_S, MAX_B );
			rect( x, y, size, size );
		}
	}
	_frame_count++;
}


