#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int SPAWN_NUM = 100;
const int STROKE_GRAY = 255;
const double GAP_RANGE = sqrt( WIDTH * WIDTH + HEIGHT * HEIGHT );
const double ANG_SPD = PI2 * 1 / 1000;

std::vector<Vector2> _pos;
Vector2 _old;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( STROKE_GRAY );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double ang = random( PI2 );
		int gap = ( int )random( GAP_RANGE );
		Vector2 pos = Vector2( gap, 0 ).rotate( ang );
		_pos.push_back( pos );
	}
}

void draw( ) {
	background( BACKGROUND );
	for ( Vector2& pos : _pos ) {
		pos = pos.rotate( ANG_SPD );
		if ( pos.x > 0 && pos.x < WIDTH &&
			 pos.y > 0 && pos.y < HEIGHT ) {
			line( _old, pos );
			_old = pos;
		}
	}
}


