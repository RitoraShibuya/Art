#include "Processing.h"
#include <cmath>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 150;
const int GRID_SIZE = 10;
const int GRID_RADIUS = GRID_SIZE / 2;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const double MAX_SIZE = GRID_SIZE * 10;
const double SIZE_SCALE = 0.001;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
	rectMode( CENTER );
}

void draw( ) {
	background( BACK_H, MAX_S, MAX_B );
	int mx = getMouseX( );
	int my = getMouseY( );
	int m_mul = abs( mx * my );

	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		int x = GRID_RADIUS + i * GRID_SIZE;
		for ( int j = 0; j < GRID_NUM_HEIGHT; j++ ) {
			double mul = i * j;
			int y = GRID_RADIUS + j * GRID_SIZE;
			double size = std::fmod( ( m_mul + mul ) + _frame_count * mul * SIZE_SCALE, MAX_SIZE );
			rect( x, y, size, size );
		}
	}
	_frame_count++;
}


