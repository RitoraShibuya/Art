#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 50;

const int LINE_GRAY = 255;
const int MAX_COUNT = 1200;
const double NOISE_RANGE = 0.005;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	stroke( LINE_GRAY );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	Vector2 pos( WIDTH / 2, 0 );
	Vector2 prev_pos( 0, 0 );
	int count = 0;

	while ( count < MAX_COUNT ) {
		prev_pos = pos;
		if ( pos.y > HEIGHT ) {
			pos.y = 0;
		}

		double n1 = getMouseX( ) * NOISE_RANGE;
		double n2 = getMouseY( ) * NOISE_RANGE;
		double n3 = pos.getLength( ) * NOISE_RANGE;

		double ang = noise( n1, n2, n3 ) * PI;

		Vector2 vec = Vector2( 3, 0 ).rotate( ang );
		pos += vec;

		line( prev_pos, pos );

		count++;
	}
}


