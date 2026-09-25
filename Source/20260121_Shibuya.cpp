#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int GRID_SIZE = 5;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const int SPAWN_NUM = GRID_NUM_WIDTH * GRID_NUM_HEIGHT;
const int INTERVAL = 360;
const int MAX_SPD = 2;
const int GRAY_RANGE = 100;
const int POINT_GRAY = 50;
const double NOISE_RANGE = 0.03;

int _frame_count = 0;
std::vector<Vector2> _dots;

int clampInv( int val, int min, int max ) {
	if ( val < min ) {
		val = max;
	} else if ( val > max ) {
		val = min;
	}
	return val;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		for ( int j = 0; j < GRID_NUM_HEIGHT; j++ ) {
			Vector2 d;
			d = Vector2( i * GRID_SIZE, j * GRID_SIZE );
			_dots.push_back( d );
		}
	}
}

void draw( ) {
	std::vector<Vector2>::iterator it = _dots.begin( );
	while ( it != _dots.end( ) ) {
		Vector2& dot = *it;
		double n1 = dot.x * NOISE_RANGE;
		double n2 = dot.y * NOISE_RANGE;
		double n3 = _frame_count % INTERVAL * NOISE_RANGE;
		double spd = noise( n1, n2, n3 ) * MAX_SPD;
		double ang = noise( n1, n2, n3 ) * PI2;
		Vector2 vec = Vector2( spd, 0.0 ).rotate( ang );
		dot += vec;

		dot.x = clampInv( dot.x, 0, WIDTH );
		dot.y = clampInv( dot.y, 0, HEIGHT );

		stroke( vec.getLength( )*GRAY_RANGE, POINT_GRAY );
		point( dot.x, dot.y );

		it++;
	}

	_frame_count++;
}


