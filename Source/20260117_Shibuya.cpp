#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int MIN_SPAWN = 10;
const int MAX_SPAWN = 100;
const double MIN_SPD = 1.0;
const double MAX_SPD = 5.0;
const double ANG_RANGE = 0.1;
const double GRAVITY = 0.1;
const double MAX_GRAVITY = 3.0;

struct Particul {
	Vector2 pos;
	Vector2 vec;
	int col_h = MAX_H;
};

std::list<Particul> _particuls;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	colorMode( HSB, MAX_H, MAX_S, MAX_B );
}

void draw( ) {
	background( BACKGROUND ,BACK_ALPHA);

	std::list<Particul>::iterator it = _particuls.begin( );
	while ( it != _particuls.end( ) ) {
		Particul& particul = *it;

		if ( particul.vec.y < MAX_GRAVITY ) {
			particul.vec += Vector2( 0.0, GRAVITY );
		}
		particul.pos += particul.vec;

		stroke( particul.col_h, MAX_S, MAX_B );
		point( particul.pos.x, particul.pos.y );

		if ( particul.pos.x > WIDTH || particul.pos.x < 0 ||
			 particul.pos.y > HEIGHT ) {
			it = _particuls.erase( it );
		} else {
			it++;
		}
	}
}

void mouseClicked( ) {
	Vector2 pos = Vector2( getMouseX( ), getMouseY( ) );
	double spd = random( MIN_SPD, MAX_SPD );
	int col_h = (int)random( MAX_H );
	int num = ( int )random( MIN_SPAWN, MAX_SPAWN );
	for ( int i = 0; i < num; i++ ) {
		Particul p;
		p.pos = pos;
		double ang = PI2 * ( ( double )i / num ) + random( -ANG_RANGE, ANG_RANGE );
		p.vec = Vector2( spd, 0.0 ).rotate( ang );
		p.col_h = col_h;
		_particuls.push_back( p );
	}
}

