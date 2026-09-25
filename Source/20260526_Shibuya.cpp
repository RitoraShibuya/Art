#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_G = 0;
const int BACK_A_RANGE = 10;
const int SPAWN_NUM_START = 1000;
const int MAX_RGB = 255;
const int FRAME_COUNT_RANGE = 500;
const int COL_B_RANGE = 100;
const int MAX_ALPHA = 30;
const double NOISE_SCALE = 0.00001;
const double BALL_SPD = 1.5;

std::list<Vector2> _balls;

void spawnBalls( int num ) {
	for ( int i = 0; i < num; i++ ) {
		int rand_x = ( int )random( WIDTH );
		int rand_y = ( int )random( HEIGHT );
		Vector2 pos( rand_x, rand_y );
		_balls.push_back( pos );
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_G );

	spawnBalls( SPAWN_NUM_START );
}

void draw( ) {
	std::list<Vector2>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Vector2& ball = *it;
		double n1 = ball.x * ball.x * NOISE_SCALE;
		double n2 = ball.y * ball.x * NOISE_SCALE;
		double n3 = ball.y * ( getFrameCount( ) % FRAME_COUNT_RANGE ) * NOISE_SCALE;
		double make_noise = noise( n1, n2, n3 );

		double spd = make_noise * BALL_SPD;
		double ang = make_noise * PI2;
		Vector2 vec = Vector2( spd, 0.0 ).rotate( ang );
		ball += vec;

		double col_r = make_noise * MAX_RGB;
		double col_g = 1 - make_noise * MAX_RGB;
		double col_b = ( int )( COL_B_RANGE + make_noise * MAX_RGB ) % MAX_RGB;
		double col_a = make_noise * MAX_ALPHA;
		stroke( col_r, col_g, col_b, col_a );
		point( ball );

		if ( ball.x > WIDTH || ball.x < 0 ||
			 ball.y > HEIGHT || ball.y < 0 ) {
			spawnBalls( 1 );
			it = _balls.erase( it );
		} else {
			it++;
		}
	}
}


