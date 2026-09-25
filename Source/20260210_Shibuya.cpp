#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int GRID_SIZE = 10;
const int GRID_RADIUS = GRID_SIZE / 2;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const double NOISE_RANGE = 0.02;

struct Wave {
	int x = 0;
	int num = 0;
};

int _frame_count = 0;
std::vector<Wave> _waves;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );

	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		Wave w;
		w.x = GRID_RADIUS + i * GRID_SIZE;
		w.num = ( int )random( GRID_NUM_HEIGHT );
		_waves.push_back( w );
	}
}

void draw( ) {
	background( BACKGROUND );

	for ( Wave& wave : _waves ) {
		for ( int i = 0; i < wave.num; i++ ) {
			int y = i * GRID_SIZE;
			int col_h = ( int )map( i, 0, GRID_NUM_HEIGHT, 0, MAX_H );

			stroke( col_h, MAX_S, MAX_B );
			point( wave.x, y );
		}

		double n1 = wave.x * NOISE_RANGE;
		double n2 = wave.num * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		wave.num = static_cast< int >( GRID_NUM_HEIGHT * noise( n1, n2, n3 ) );
	}

	_frame_count++;
}


