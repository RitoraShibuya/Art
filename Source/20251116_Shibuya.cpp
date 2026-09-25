#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int S_NUM = 20;
const int SPEED = 2;
const int MIN_DIA = 10;
const int MAX_DIA = 100;
const int MAX_RADIANS = 360;
const int HALF_RADIANS = MAX_RADIANS / 2;
const int RADIANS_RANDOM = 20;
const int GRAY = 255;
const int ALPHA = 2;

int turn( int ang );

struct ColSphere {
	double x = CENTER_X;
	double y = CENTER_Y;
	double ang = 0;
	int dia = MIN_DIA;
	int half = dia / 2;
};

ColSphere _spheres[ S_NUM ];

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	blendMode( ADD );

	for ( int i = 0; i < S_NUM; i++ ) {
		ColSphere& s = _spheres[ i ];
		s.x = random( 0, WIDTH );
		s.y = random( 0, HEIGHT );
		s.ang = random( 0, MAX_RADIANS );
		s.dia = ( int )random( MIN_DIA, MAX_DIA );
		s.half = s.dia / 2;
	}
}

void draw( ) {
	noStroke( );
	fill( GRAY, ALPHA );

	for ( int i = 0; i < S_NUM; i++ ) {
		ColSphere& s = _spheres[ i ];

		for ( int j = 0; j < S_NUM; j++ ) {
			if ( i == j ) continue;

			auto& other = _spheres[ j ];
			double dx = s.x - other.x;
			double dy = s.y - other.y;
			double dist = sqrt( dx * dx + dy * dy );
			double range = s.half + other.half;

			if ( dist < range ) {
				s.ang = turn( s.ang );

				double gap = ( range - dist );
				double nx = dx / dist;
				double ny = dy / dist;

				s.x += nx * gap;
				s.y += ny * gap;
			}
		}

		s.x += cos( radians( s.ang ) ) * SPEED;
		s.y += sin( radians( s.ang ) ) * SPEED;

		if ( s.x > WIDTH - s.half ) {
			s.x = WIDTH - s.half;
			s.ang = turn( s.ang );
		}
		if ( s.x < s.half ) {
			s.x = s.half;
			s.ang = turn( s.ang );
		}
		if ( s.y > HEIGHT - s.half ) {
			s.y = HEIGHT - s.half;
			s.ang = turn( s.ang );
		}
		if ( s.y < s.half ) {
			s.y = s.half;
			s.ang = turn( s.ang );
		}

		ellipse( s.x, s.y, s.dia );
	}
}

int turn( int ang ) {
	int diff = ( int )random( -RADIANS_RANDOM, RADIANS_RANDOM );
	return ( ang + HALF_RADIANS + diff ) % MAX_RADIANS;
}
