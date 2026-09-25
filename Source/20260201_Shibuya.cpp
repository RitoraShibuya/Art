#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int GRID = 20;

const int SPD = 3;
const int ANG_DIST = 100;
const double NOISE_RANGE = 0.05;

struct Particul {
	Vector2 pos;
	double col_h = 0;
};

std::vector<Particul> _particuls;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );

	for ( int i = 0; i < WIDTH / GRID; i++ ) {
		for ( int j = 0; j < HEIGHT / GRID; j++ ) {
			Particul p;
			p.pos = Vector2( i * GRID, j * GRID );
			p.col_h = random( MAX_H );
			_particuls.push_back( p );
		}
	}
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );
	double n1 = getMouseX( ) * NOISE_RANGE;
	double n2 = getMouseY( ) * NOISE_RANGE;
	for ( Particul& particul : _particuls ) {
		if ( particul.pos.x > WIDTH || particul.pos.x < 0 ) {
			particul.pos.x = WIDTH - particul.pos.x;
		}
		if ( particul.pos.y > HEIGHT || particul.pos.y < 0 ) {
			particul.pos.y = HEIGHT - particul.pos.y;
		}
		double n3 = particul.pos.getLength( ) * NOISE_RANGE;
		double spd = noise( n1, n2, n3 ) * SPD;
		double ang = noise( n1 + ANG_DIST, n2 + ANG_DIST, n3 ) * PI2;
		Vector2 vec = Vector2( spd, 0.0 ).rotate( ang );
		particul.pos += vec;

		stroke( particul.col_h, MAX_S, MAX_B );
		point( particul.pos.x, particul.pos.y );
	}
}


