#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_GRAY = 50;

const int START_SPAWN = 30;
const int POINT_GRAY = 255;
const int MIN_SPD = 1;
const int MAX_SPD = 3;

struct Snow {
	Vector2 pos;
	Vector2 vec;
	double ang = 0;
	int life = 360;
};

std::list<Snow> _snows;

void spawnSnow( ) {
	Snow s;
	s.pos = Vector2( random( WIDTH ), random( HEIGHT ) );
	s.ang = random( PI2 );
	s.vec = Vector2( random( MIN_SPD, MAX_SPD ), 0 ).rotate( s.ang );
	_snows.push_back( s );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	for ( int i = 0; i < START_SPAWN; i++ ) {
		spawnSnow( );
	}
}

void draw( ) {
	background( BACKGROUND, BACK_GRAY );

	std::list<Snow>::iterator it = _snows.begin( );
	while ( it != _snows.end( ) ) {
		Snow& snow = *it;
		snow.pos += snow.vec;
		if ( snow.pos.x < 0 ) {
			snow.pos.x = 0;
			snow.vec.x *= -1;
		} else if ( snow.pos.x > WIDTH ) {
			snow.pos.x = WIDTH;
			snow.vec.x *= -1;
		}

		if ( snow.pos.y < 0 ) {
			snow.pos.y = 0;
			snow.vec.y *= -1;
		} else if ( snow.pos.y > HEIGHT ) {
			snow.pos.y = HEIGHT;
			snow.vec.y *= -1;
		}

		stroke( POINT_GRAY );
		point( snow.pos.x, snow.pos.y );
		if ( snow.life < 0 ) {
			it = _snows.erase( it );
		} else {
			snow.life--;
			it++;
		}
	}
}

void mouseDragged( ) {
	spawnSnow( );
}
