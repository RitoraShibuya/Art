#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int LINE_GRAY = 255;
const int SPAWN_NUM = 3000;
const double NOISE_RANGE = 0.01;

int _frame_count = 0;
Vector2 _old( 0.0, 0.0 );

Vector2 warpPos( Vector2 vec, Vector2 min, Vector2 max ) {
	if ( vec.x > max.x ) {
		vec.x = min.x;
	} else if ( vec.x < min.x ) {
		vec.x = max.x;
	}
	if ( vec.y > max.y ) {
		vec.y = min.y;
	} else if ( vec.y < min.y ) {
		vec.y = max.y;
	}
	return vec;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( LINE_GRAY );
	setFrameRate( 30 );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double n1 = _old.x * NOISE_RANGE;
		double n2 = _old.y * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double gap = noise( n1, n2, n3 );
		double ang = noise( n1, n2, n3 ) * PI2;
		Vector2 vec = Vector2( gap, 0.0 ).rotate( ang );
		Vector2 pos = _old + vec;
		pos = warpPos( pos, Vector2( 0.0, 0.0 ), Vector2( WIDTH, HEIGHT ) );

		point( pos.x, pos.y );

		_old = pos;
	}
	_frame_count++;
}


