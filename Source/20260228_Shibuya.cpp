#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 50;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int SPAWN_NUM = 1000;
const int GAP_MAX = 500;
const int NOISE_RANGE_GAP = 100;
const int NOISE_RANGE_COL = 200;
const double NOISE_SCALE = 0.005;
const double ANG_SPD_MAX = PI2 * 1 / 200;

struct Ball {
	Vector2 pos;
	double gap = 0;
	double ang = 0;
};

std::vector<Ball> _balls;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	Vector2 center( CENTER_X, CENTER_Y );
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Ball b;
		b.gap = random( GAP_MAX );
		b.ang = random( PI2 );
		b.pos = center + Vector2( b.gap, 0.0 ).rotate( b.ang );
		_balls.push_back( b );
	}
}

void draw( ) {
	Vector2 center( CENTER_X, CENTER_Y );

	for ( Ball& ball : _balls ) {
		double n1 = ball.pos.x * NOISE_SCALE;
		double n2 = ball.pos.y * NOISE_SCALE;
		double n3 = ball.ang + ball.gap * NOISE_SCALE;

		double ang_spd = noise( n1, n2, n3 ) * ANG_SPD_MAX;
		ball.ang += ang_spd;
		ball.gap = noise( n1 + NOISE_RANGE_GAP, n2 + NOISE_RANGE_GAP, n3 ) * GAP_MAX;
		ball.pos = center + Vector2( ball.gap, 0.0 ).rotate( ball.ang );

		double col_h = noise( n1 + NOISE_RANGE_COL, n2 + NOISE_RANGE_COL, n3 ) * MAX_H;
		stroke( col_h, MAX_S, MAX_B );
		point( ball.pos );
	}
}