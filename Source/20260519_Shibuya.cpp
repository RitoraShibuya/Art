#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 200;
const int BACK_S = 100;
const int BACK_B = 20;
const int SPAWN_NUM = 4000;
const int COL_RANGE = 250;
const double OUT_RANGE = 50.0;
const double BALL_SPD = 0.5;
const double NOISE_SCALE = 0.000005;

std::vector<Vector2> _balls;

Vector2 warp( Vector2 val ) {
	if ( val.x > WIDTH ) {
		val.x = random( OUT_RANGE );
	} else if ( val.x < 0 ) {
		val.x = WIDTH - random( OUT_RANGE );
	}
	if ( val.y > HEIGHT ) {
		val.y = random( OUT_RANGE );
	} else if ( val.y < 0 ) {
		val.y = HEIGHT - random( OUT_RANGE );
	}
	return val;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, BACK_S, BACK_B );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double x = random( 0.0, ( double )WIDTH );
		double y = random( 0.0, ( double )HEIGHT );
		Vector2 pos { x,y };
		_balls.push_back( pos );
	}
}

void draw( ) {
	for ( Vector2& ball : _balls ) {
		ball = warp( ball );
		double n1 = ( ball.x * ball.x ) * NOISE_SCALE;
		double n2 = ( ball.y * ball.x ) * NOISE_SCALE;
		double n3 = ( ball.y * ball.y - ball.x ) * NOISE_SCALE;
		double make_noise = noise( n1, n2, n3 );
		double ang = make_noise * PI2;
		double len = make_noise * BALL_SPD;
		Vector2 vec = Vector2( len, 0.0 ).rotate( ang );
		ball += vec;

		int col_h = ( int )( make_noise * MAX_H ) % COL_RANGE;
		stroke( col_h, MAX_S, MAX_B );
		point( ball );
	}
}


