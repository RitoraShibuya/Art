#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACK_H = 300;
const int BACK_S = 100;
const int BACK_B = 50;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int GAP = 200;
const double ANG_SPD = 0.01;

struct Ball {
	Vector2 pos;
	int col_h = 0;
	double ang = 0;
};

std::vector<Ball> _balls;

double warp( double num, double min, double max ) {
	if ( num < min ) {
		num = max;
	} else if ( num > max ) {
		num = min;
	}
	return num;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, BACK_S, BACK_B );

	Vector2 center( WIDTH / 2, HEIGHT / 2 );
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			Ball b;
			int rad = ( i + j ) % 360;
			b.ang = PI2 * rad / 360;
			int gap = ( i + j ) % GAP;
			b.col_h = ( i + j ) % MAX_H;
			b.pos = center + Vector2( gap, 0 ).rotate( b.ang );
			_balls.push_back( b );
		}
	}
}

void draw( ) {
	for ( Ball& ball : _balls ) {
		Vector2 center( WIDTH / 2, HEIGHT / 2 );
		double len = center.getLength( ) - ball.pos.getLength( );
		double ang = warp( len, 0.0, PI2 );
		Vector2 vec = Vector2( len, 0.0 ).rotate( ang );
		ball.pos += vec;

		stroke( ball.col_h, MAX_S, MAX_B );
		point( ball.pos );
	}
}


