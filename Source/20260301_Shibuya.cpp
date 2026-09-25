#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACKGROUND = 25;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
 
const int NOISE_RANGE_ANG = 100;
const int NOISE_RANGE_COL = 200;
const double BALL_SPD = 1.1;
const double NOISE_SCALE = 0.003;
const double NOISE_SCALE_THIRD = 0.001;

struct Ball {
	Vector2 pos;
	Vector2 vec;
	double col_h = 0;
};

std::vector<Ball> _balls;

double warp( double val, double min, double max ) {
	if ( val < min ) {
		val = max;
	} else if ( val > max ) {
		val = min;
	}
	return val;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );

	for ( int i = 0; i < WIDTH; i++ ) {
		double n1 = i * NOISE_SCALE;
		for ( int j = 0; j < HEIGHT; j++ ) {
			double n2 = j * NOISE_SCALE;
			double n3 = i + j * NOISE_SCALE_THIRD;
			double spd_n = noise( n1, n2, n3 ) * BALL_SPD;
			double ang_n = noise( n1 + NOISE_RANGE_ANG, n2 + NOISE_RANGE_ANG, n3 ) * PI2;
			double col_n = noise( n1 + NOISE_RANGE_COL, n2 + NOISE_RANGE_COL, n3 ) * MAX_H;
			Ball b;
			b.pos = Vector2( i, j );
			b.vec = Vector2( spd_n, 0.0 ).rotate( ang_n );
			b.col_h = col_n;
			_balls.push_back( b );
		}
	}
}

void draw( ) {
	for ( Ball& ball : _balls  ) {
		ball.pos += ball.vec;
		ball.pos.x = warp( ball.pos.x, 0, WIDTH );
		ball.pos.y = warp( ball.pos.y, 0, HEIGHT );
		
		stroke( ball.col_h, MAX_S, MAX_B );
		point( ball.pos );
	}
}


