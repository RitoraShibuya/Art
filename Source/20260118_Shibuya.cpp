#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int SPAWN_NUM = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int RIVER_SPD = 2;
const double ANG_RANGE = PI;

struct River {
	Vector2 pos;
	int col_h = 0;
};

std::vector<River> _river;

void spawnRiver( ) {
	River p;
	int x = ( int )random( WIDTH );
	p.pos = Vector2( x, 0 );
	p.col_h = ( int )random( MAX_H );
	_river.push_back( p );
}

void updateRiver( ) {
	std::vector<River>::iterator it = _river.begin( );
	while ( it != _river.end( ) ) {
		River& river = *it;
		double ang = random( ANG_RANGE );
		Vector2 vec = Vector2( RIVER_SPD, 0 ).rotate( ang );
		river.pos += vec;

		stroke( river.col_h, MAX_S, MAX_B );
		point( river.pos.x, river.pos.y );

		if ( river.pos.y > HEIGHT ) {
			it = _river.erase( it );
			spawnRiver( );
		} else {
			it++;
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		spawnRiver( );
	}
}

void draw( ) {
	updateRiver( );
}


