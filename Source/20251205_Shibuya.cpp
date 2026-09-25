#include "Processing.h"

const int WIDTH = 900;
const int HEIGHT = 900;
const int BACKGROUND = 255;
const int LOAD_GRAY = 0;
const int GRID_SIZE = 30;
const int GRID_NUM_W = WIDTH / GRID_SIZE;
const int GRID_NUM_H = HEIGHT / GRID_SIZE;
const int THICK = 2;
const int LOOP_COUNT = 5000;

const int MIN_X = 1;
const int MIN_Y = 1;
const int MAX_X = GRID_NUM_W - 2;
const int MAX_Y = GRID_NUM_H - 2;
const int START_X = 5;
const int START_Y = 5;
const int RANDOM_SECTION = 4;
const int DIRECTION_X[ 4 ] = { 1, 0, -1, 0 };
const int DIRECTION_Y[ 4 ] = { 0, 1, 0, -1 };

enum class GRID_TYPE {
	WALL = 0,
	LOAD,
};

struct LoadPoint {
	int x = START_X;
	int y = START_Y;
	bool can_move[ RANDOM_SECTION ] = { true,true,true,true };
};


LoadPoint _point;
GRID_TYPE _map[ GRID_NUM_W ][ GRID_NUM_H ];

int clamp( int n, int min, int max ) {
	int num = n;

	if ( n > max ) {
		num = max;
	} else if ( n < min ) {
		num = min;
	}
	return num;
}

void step( ) {
	bool all_false = true;

	for ( int i = 0; i < RANDOM_SECTION; i++ ) {
		if ( _point.can_move[ i ] ) {
			all_false = false;
			break;
		}
	}

	if ( all_false ) {
		return;
	}

	int rand_dir;
	do {
		rand_dir = ( int )random( RANDOM_SECTION );
	} while ( !_point.can_move[ rand_dir ] );
	
	int nx = _point.x + DIRECTION_X[ rand_dir ] * THICK;
	int ny = _point.y + DIRECTION_Y[ rand_dir ] * THICK;
	int clamped_nx = clamp( nx, MIN_X, MAX_X );
	int clamped_ny = clamp( ny, MIN_Y, MAX_Y );
	if ( nx != clamped_nx || ny != clamped_ny ) {
		_point.can_move[ rand_dir ] = false;
		return;
	}

	if ( _map[ nx ][ ny ] == GRID_TYPE::LOAD ) {
		_point.can_move[ rand_dir ] = false;
	} else {

		for ( int i = 0; i < RANDOM_SECTION; i++ ) {
			_point.can_move[ i ] = true;
		}

		for ( int i = 0; i < THICK; i++ ) {
			_point.x += DIRECTION_X[ rand_dir ];
			_point.y += DIRECTION_Y[ rand_dir ];
			_map[ _point.x ][ _point.y ] = GRID_TYPE::LOAD;
		}
	}
}

void drawMap( ) {
	noStroke( );

	for ( int i = 0; i < GRID_NUM_W; i++ ) {
		for ( int j = 0; j < GRID_NUM_H; j++ ) {

			if ( _map[ i ][ j ] == GRID_TYPE::LOAD ) {
				fill( LOAD_GRAY );
			} else {
				fill( BACKGROUND );
			}

			rect( i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE );
		}
	}
}

void createMap( ) {
	_point.x = START_X;
	_point.y = START_Y;
	for ( int i = 0; i < RANDOM_SECTION; i++ ) {
		_point.can_move[ i ] = true;
	}

	for ( int i = 0; i < GRID_NUM_W; i++ ) {
		for ( int j = 0; j < GRID_NUM_H; j++ ) {
			_map[ i ][ j ] = GRID_TYPE::WALL;
		}
	}

	_map[ _point.x ][ _point.y ] = GRID_TYPE::LOAD;

	for ( int i = 0; i < LOOP_COUNT; i++ ) {
		step( );
	}

	drawMap( );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	fill( LOAD_GRAY );
	noStroke( );

	createMap( );
}

void mouseClicked( ) {
	createMap( );
}