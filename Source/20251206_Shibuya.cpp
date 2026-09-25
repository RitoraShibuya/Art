#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int FRAME_RATE = 30;
const int GRID_SIZE = 40;
const int GRID_NUM_W = WIDTH / GRID_SIZE;
const int GRID_NUM_H = HEIGHT / GRID_SIZE;
const int THICK = 2;

const int LOAD_GRAY = 255;
const int START_R = 255;
const int RANDOM_SECTION = 4;
const int MIN_X = 1;
const int MIN_Y = 1;
const int START_X = 5;
const int START_Y = 5;
const int MAX_X = GRID_NUM_W - 2;
const int MAX_Y = GRID_NUM_H - 2;
const int DIR_X[ RANDOM_SECTION ] = { 1, 0, -1, 0 };
const int DIR_Y[ RANDOM_SECTION ] = { 0, 1, 0, -1 };

enum class GRID_TYPE {
	WALL,
	LOAD,
	START,
};

struct LoadPoint {
	int x = START_X;
	int y = START_Y;
};


LoadPoint _point;
GRID_TYPE _map[ GRID_NUM_W ][ GRID_NUM_H ];

int clamp( int num, int min, int max ) {
	int n = num;
	if ( n < min ) {
		n = min;
	}
	if ( n > max ) {
		n = max;
	}
	return n;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
	setFrameRate( FRAME_RATE );

	for ( int i = 0; i < GRID_NUM_W; i++ ) {
		for ( int j = 0; j < GRID_NUM_H; j++ ) {
			_map[ i ][ j ] = GRID_TYPE::WALL;
		}
	}

	_map[ START_X ][ START_Y ] = GRID_TYPE::START;
	int x = _point.x * GRID_SIZE;
	int y = _point.y * GRID_SIZE;
	fill( START_R, 0, 0 );
	rect( x, y, GRID_SIZE, GRID_SIZE );
}

void draw( ) {

	fill( LOAD_GRAY );

	int rand_dir = ( int )random( RANDOM_SECTION );

	int nx = _point.x;
	int ny = _point.y;
	nx += DIR_X[ rand_dir ] * THICK;
	ny += DIR_Y[ rand_dir ] * THICK;
	nx = clamp( nx, MIN_X, MAX_X );
	ny = clamp( ny, MIN_Y, MAX_Y );

	if ( _map[ nx ][ ny ] == GRID_TYPE::WALL ) {
		for ( int i = 0; i < THICK; i++ ) {
			_point.x += DIR_X[ rand_dir ];
			_point.y += DIR_Y[ rand_dir ];
			_map[ _point.x ][ _point.y ] = GRID_TYPE::LOAD;

			int x = _point.x * GRID_SIZE;
			int y = _point.y * GRID_SIZE;
			rect( x, y, GRID_SIZE, GRID_SIZE );
		}
	} else {
		_point.x = nx;
		_point.y = ny;
	}
}