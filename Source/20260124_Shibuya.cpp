#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int LINE_COLOR_R = 255;
const int LINE_COLOR_G = 0;
const int LINE_COLOR_B = 0;
const int LINE_ALPHA = 20;
const int LINE_WEIGHT = 10;
const int SPAWN_NUM = 20;
const int MIN_SPD = 5;
const int MAX_SPD = 10;

std::vector<Vector2> _river;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( LINE_COLOR_R, LINE_COLOR_G, LINE_COLOR_B, LINE_ALPHA );
	strokeWeight( LINE_WEIGHT );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		int x = WIDTH / SPAWN_NUM * i;
		Vector2 r;
		r = Vector2( x, HEIGHT );
		_river.push_back( r );
	}
}

void draw( ) {
	for ( Vector2& river : _river ) {
		double spd = random( MIN_SPD, MAX_SPD );
		Vector2 old = river;
		Vector2 vec = Vector2( -spd, 0.0 ).rotate( random( PI ) );
		if ( river.y < 0 ) {
			river.y = HEIGHT;
		}
		if ( river.x < 0 ) {
			river.x = 0;
		}
		if ( river.x > WIDTH ) {
			river.x = WIDTH;
		}
		river += vec;
		line( old.x, old.y, river.x, river.y );
	}
}


