#include "Processing.h"

const int WIDTH = 900;
const int HEIGHT = 900;
const int BACKGROUND = 255;
const int WALL_GRAY = 0;
const int LOAD_GRAY = 255;
const int GRID_SIZE = 30;
const int GRID_NUM_W = WIDTH / GRID_SIZE;
const int GRID_NUM_H = HEIGHT / GRID_SIZE;
const int RANDOM_SECTION = 4;
const int MAX_LOAD_COUNT = 300;

enum class GRID_TYPE {
	WALL,
	LOAD,
};

struct LoadGrid {
	int x = 1;
	int y = 1;
};

bool _not_load[ RANDOM_SECTION ] = { false,false,false,false };
LoadGrid _load;
GRID_TYPE _layout[ GRID_NUM_W ][ GRID_NUM_H ] = { GRID_TYPE::WALL };

bool isAllLoad( );
void makeNumAllTrue( );
bool makeNumNotAllTrue( );

void makeNum( ) {
	while ( true ) {
		if ( isAllLoad( ) ) {
			makeNumAllTrue( );
			continue;
		}

		if ( makeNumNotAllTrue( ) ) {
			break;
		}
	}
}

bool isAllLoad( ) {
	bool alltrue = true;
	for ( int i = 0; i < RANDOM_SECTION; i++ ) {
		if ( _not_load[ i ] == false ) {
			alltrue = false;
			break;
		}
	}
	return alltrue;
}

void makeNumAllTrue( ) {
	int rand_num = ( int )random( RANDOM_SECTION );
	switch ( rand_num ) {
	case 0:
		_load.x += 2;
		if ( _load.x >= GRID_NUM_W - 1 ) {
			_load.x = GRID_NUM_W - 1;
		}
		if ( _layout[ _load.x ][ _load.y ] == GRID_TYPE::LOAD ) {
			for ( int i = 0; i < RANDOM_SECTION; i++ ) _not_load[ i ] = false;
			return;
		}
		break;

	case 1:
		_load.x -= 2;
		if ( _load.x <= 1 ) {
			_load.x = 1;
		}
		if ( _layout[ _load.x ][ _load.y ] == GRID_TYPE::LOAD ) {
			for ( int i = 0; i < RANDOM_SECTION; i++ ) _not_load[ i ] = false;
			return;
		}
		break;

	case 2:
		_load.y += 2;
		if ( _load.y >= GRID_NUM_H - 1 ) {
			_load.y = GRID_NUM_H - 1;
		}
		if ( _layout[ _load.x ][ _load.y ] == GRID_TYPE::LOAD ) {
			for ( int i = 0; i < RANDOM_SECTION; i++ ) _not_load[ i ] = false;
			return;
		}
		break;

	case 3:
		_load.y -= 2;
		if ( _load.y <= 1 ) {
			_load.y = 1;
		}
		if ( _layout[ _load.x ][ _load.y ] == GRID_TYPE::LOAD ) {
			for ( int i = 0; i < RANDOM_SECTION; i++ ) _not_load[ i ] = false;
			return;
		}
		break;
	}
}

bool makeNumNotAllTrue( ) {
	int x = _load.x;
	int y = _load.y;
	bool moved = false;

	int rand_num = ( int )random( RANDOM_SECTION );
	switch ( rand_num ) {
	case 0:
		x += 2;
		if ( x < GRID_NUM_W && _layout[ x ][ y ] != GRID_TYPE::LOAD ) {
			_load.x += 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			_load.x += 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			moved = true;
		}
		break;

	case 1:
		x -= 2;
		if ( x > 0 && _layout[ x ][ y ] != GRID_TYPE::LOAD ) {
			_load.x -= 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			_load.x -= 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			moved = true;
		}
		break;

	case 2:
		y += 2;
		if ( y < GRID_NUM_H && _layout[ x ][ y ] != GRID_TYPE::LOAD ) {
			_load.y += 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			_load.y += 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			moved = true;
		}
		break;

	case 3:
		y -= 2;
		if ( y > 0 && _layout[ x ][ y ] != GRID_TYPE::LOAD ) {
			_load.y -= 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			_load.y -= 1;
			_layout[ _load.x ][ _load.y ] = GRID_TYPE::LOAD;
			moved = true;
		}
		break;
	}

	if ( moved ) {
		for ( int i = 0; i < RANDOM_SECTION; i++ ) {
			_not_load[ i ] = false;
		}
	} else {
		_not_load[ rand_num ] = true;
	}

	return moved;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	for ( int i = 0; i < MAX_LOAD_COUNT; i++ ) {
		makeNum( );
	}

	for ( int i = 0; i < GRID_NUM_W; i++ ) {
		for ( int j = 0; j < GRID_NUM_H; j++ ) {

			switch ( _layout[ i ][ j ] ) {
			case GRID_TYPE::WALL:
				fill( WALL_GRAY );
				break;
			case GRID_TYPE::LOAD:
				fill( LOAD_GRAY );
				break;
			}

			rect( i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE );
		}
	}
}

