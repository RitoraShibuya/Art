#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_GRAY = 0;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BALL_ALPHA = 5;
const double NOISE_SCALE = 0.00003;
const double BALL_SPD = 1.5;

std::vector<Vector2> _balls;

void warp( double& val, int min, int max ) {
	if ( val > max ) {
		double gap = val - max;
		val = min + gap;
	} else if ( val < min ) {
		val = max + val;
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	setFrameRate( 10 );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_GRAY );

	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			_balls.push_back( Vector2( ( double )i, ( double )j ) );
		}
	}
}

void draw( ) {
	double mx = getMouseX( );
	double my = getMouseY( );
	for ( Vector2& ball : _balls ) {
		double n1 = ball.x * my * NOISE_SCALE;
		double n2 = ball.y * mx * NOISE_SCALE;
		double n3 = ball.x * ball.y * NOISE_SCALE;
		double make_noise = noise( n1, n2, n3 );

		double spd = make_noise * BALL_SPD;
		double ang = make_noise * PI2;
		Vector2 vec = Vector2( spd, 0.0 ).rotate( ang );
		ball += vec;

		warp( ball.x, 0, WIDTH );
		warp( ball.y, 0, HEIGHT );

		double col_h = make_noise * MAX_H;
		stroke( col_h, MAX_S, MAX_B, BALL_ALPHA );
		point( ball );
	}
}


