#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int POINT_NUM = 2000;
const int POINT_GRAY = 255;
const int POINT_ALPHA = 10;
const double POINT_SPD = 0.01;
const int MAX_GAP = 300;
const double NOISE_RANGE = 0.005;

Vector2 _center;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( POINT_GRAY, POINT_ALPHA );
}

void draw( ) {
	Vector2 m_pos( getMouseX( ), getMouseY( ) );
	Vector2 vec = m_pos - _center;
	_center += vec * POINT_SPD;

	for ( int i = 0; i < POINT_NUM; i++ ) {
		double n1 = _center.x * NOISE_RANGE;
		double n2 = _center.y * NOISE_RANGE;
		double n3 = i * NOISE_RANGE;
		int gap = MAX_GAP * noise( n1, n2, n3 );

		double ang = PI2 * i / POINT_NUM;
		Vector2 pos = _center + Vector2( gap, 0 ).rotate( ang );
		point( pos.x, pos.y );
	}
}


