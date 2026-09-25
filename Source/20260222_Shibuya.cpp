#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int POINT_GRAY = 255;
const int ALPHA_MAX = 255;
const int GRID_SIZE = 20;
const int GRID_RADIUS = GRID_SIZE / 2;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const double NOISE_RANGE = 0.005;
const double NOISE_TIME = 0.01;

int _frame_count = 0;
std::vector<Vector2> _grids;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	noStroke( );

	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		for ( int j = 0; j < GRID_NUM_HEIGHT; j++ ) {
			int x = GRID_RADIUS + i * GRID_SIZE;
			int y = GRID_RADIUS + j * GRID_SIZE;
			_grids.emplace_back( Vector2( x, y ) );
		}
	}
}

void draw( ) {
	background( BACKGROUND );

	for ( Vector2& pos : _grids ) {
		double n1 = pos.x * NOISE_RANGE;
		double n2 = pos.y * NOISE_RANGE;
		double n3 = _frame_count * NOISE_TIME;

		int alpha = ( int )( noise( n1, n2, n3 ) * ALPHA_MAX );
		int size = ( int )map( alpha, 0, ALPHA_MAX, 0, GRID_SIZE * 2 );

		fill( POINT_GRAY, alpha );
		rect( pos.x, pos.y, size, size );
	}
	_frame_count++;
}


