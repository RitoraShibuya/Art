#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 5;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;

const int ADD_GAP_RANGE = 5;
const int PARTICUL_SPD = 5;
const int NOISE_GAP = 100;
const double NOISE_RANGE = 0.05;

struct Particul {
	Vector2 pos;
	int col_h = 0;
};

int _frame_count = 0;
std::vector<Particul> _particuls;

Vector2 warpPos( Vector2 pos ) {
	if ( pos.x > WIDTH ) {
		pos.x = 0;
	}
	if ( pos.x < 0 ) {
		pos.x = WIDTH;
	}
	if ( pos.y > HEIGHT ) {
		pos.y = 0;
	}
	if ( pos.y < 0 ) {
		pos.y = HEIGHT;
	}
	return pos;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );

	double x = 0;
	double y = 0;
	Particul p;
	while ( x < WIDTH ) {
		y = 0;
		while ( y < HEIGHT ) {
			y += random( ADD_GAP_RANGE );
			p.pos = Vector2( x, y );
			p.col_h = ( int )random( MAX_H );
			_particuls.push_back( p );
		}
		x += random( ADD_GAP_RANGE );
	}
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );
	for ( Particul& particul : _particuls ) {
		double n1 = particul.pos.x * NOISE_RANGE;
		double n2 = particul.pos.y * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double spd = noise( n1, n2, n3 ) * PARTICUL_SPD;
		double ang = noise( n1 + NOISE_GAP, n2 + NOISE_GAP, n3 ) * PI2;
		Vector2 vec = Vector2( spd, 0.0 ).rotate( ang );
		particul.pos += vec;
		particul.pos = warpPos( particul.pos );

		stroke( particul.col_h, MAX_S, MAX_B );
		point( particul.pos );
	}

	_frame_count++;
}


