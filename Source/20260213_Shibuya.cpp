#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int WALL_NUM = 1000;
const int SPAWN_NUM = 30;
const int BALL_GRAY = 255;
const int DIA_MIN = 50;
const int DIA_MAX = 150;
const int WALL_RADIUS = 100;
const int BASE_GAP = 200;
const int GAP = 300;
const double BALL_SPD = 1;
const double NOISE_RANGE = 0.005;

struct Ball {
	Vector2 pos;
	Vector2 vec;
	int dia = 0;
};

int _frame_count = 0;
std::vector<Ball> _balls;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( BALL_GRAY );
	noFill( );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Ball b;
		b.pos = Vector2( CENTER_X, CENTER_Y );
		b.vec = Vector2( BALL_SPD, 0.0 ).rotate( random( PI2 ) );
		b.dia = ( int )random( DIA_MIN, DIA_MAX );
		_balls.push_back( b );
	}
}

void draw( ) {
	background( BACKGROUND );

	std::vector<Vector2> walls;
	Vector2 center( CENTER_X, CENTER_Y );

	for ( int i = 0; i < WALL_NUM; i++ ) {
		double ang = PI2 * i / WALL_NUM;
		double n1 = i * NOISE_RANGE;
		double n2 = ang * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double gap = BASE_GAP + noise( n1, n2, n3 ) * GAP;
		Vector2 w = center + Vector2( gap, 0.0 ).rotate( ang );
		walls.push_back( w );
	}

	for ( Ball& ball : _balls ) {
		bool hit = false;
		double range = ( ball.pos - center ).getLength( );

		for ( Vector2& wall : walls ) {
			double dist = ( ball.pos - wall ).getLength( );
			if ( dist < ball.dia / 2 + WALL_RADIUS ) {
				hit = true;
				break;
			}
		}
		if ( hit || range > GAP ) {
			ball.vec *= -1;
		}
		ball.pos += ball.vec;

		ellipse( ball.pos.x, ball.pos.y, ball.dia );
	}

	_frame_count++;
}


