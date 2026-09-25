#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int BALL_GRAY = 255;
const int INNER_NUM = 8;
const int MIDDLE_NUM = 5;
const int OUTER_NUM = 10;
const int INNER_GAP = 100;
const int MIDDLE_GAP = 200;
const int OUTER_GAP = 300;
const int DIA_MIN = 50;
const int DIA_MAX = 200;
const double ANG_SPD = PI2 * 1 / 300;
const double NOISE_RANGE = 0.03;

struct Ball {
	Vector2 pos;
	int dia = 0;
	int step = 1;
};

int _frame_count = 0;
std::vector<Ball> _balls;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	fill( BALL_GRAY );
	noStroke( );

	Vector2 center( CENTER_X, CENTER_Y );
	int spawn_num = INNER_NUM + MIDDLE_NUM + OUTER_NUM;

	for ( int i = 0; i < spawn_num; i++ ) {
		Ball b;

		if ( i < INNER_NUM ) {
			double ang = PI2 * i / INNER_NUM;
			b.pos = center + Vector2( INNER_GAP, 0 ).rotate( ang );
		} else if ( i < INNER_NUM + MIDDLE_NUM ) {
			int num = i - INNER_NUM;
			double ang = PI2 * num / MIDDLE_NUM;
			b.pos = center + Vector2( MIDDLE_GAP, 0 ).rotate( ang );
			b.step = -1;
		} else {
			int num = i - INNER_NUM - MIDDLE_NUM;
			double ang = PI2 * num / OUTER_NUM;
			b.pos = center + Vector2( OUTER_GAP, 0 ).rotate( ang );
		}
		b.dia = ( int )random( DIA_MIN, DIA_MAX );

		_balls.push_back( b );
	}
}

void draw( ) {
	background( BACKGROUND );
	Vector2 center( CENTER_X, CENTER_Y );

	for ( Ball& ball : _balls ) {
		double n1 = ball.pos.x * NOISE_RANGE;
		double n2 = ball.pos.y * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double ang_spd = ball.step * noise( n1, n2, n3 ) * ANG_SPD;

		ball.pos = center + ( ball.pos - center ).rotate( ang_spd );

		ellipse( ball.pos.x, ball.pos.y, ball.dia );
	}

	_frame_count++;
}
