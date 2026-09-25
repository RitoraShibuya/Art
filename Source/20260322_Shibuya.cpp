#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACK_R = 150;
const int BACK_G = 200;
const int BACK_B = 200;
const int BALL_R = 255;
const int BALL_B= 100;
const int BALL_G = 100;
const int MAX_ALPHA = 255;
const int SPAWN_NUM = 300;
const int MAX_GAP = 500;
const double MIN_SPD = 0.5;
const double MAX_SPD = 3.0;
const double ANG_RAND_RANGE = PI2 * 1 / 10;

struct Ball {
	Vector2 pos;
	int alpha = 0;
	double base_ang = 0;
};

std::list<Ball> _balls;

void spawnBall( ) {
	Ball b;
	b.pos.x = CENTER_X;
	b.pos.y = CENTER_Y;
	b.alpha = ( int )random( MAX_ALPHA );
	b.base_ang = random( PI2 );
	_balls.push_back( b );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_G, BACK_B );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		spawnBall( );
	}
}

void draw( ) {
	Vector2 center( CENTER_X, CENTER_Y );

	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;

		double spd = random( MIN_SPD, MAX_SPD );
		double ang = ball.base_ang + random( -ANG_RAND_RANGE, ANG_RAND_RANGE );
		Vector2 vec = Vector2( spd, 0.0 ).rotate( ang );
		ball.pos += vec;

		stroke( BALL_R,BALL_B,BALL_G, ball.alpha );
		point( ball.pos );

		double length = ( center - ball.pos ).getLength( );
		if ( length > MAX_GAP ) {
			spawnBall( );
			it = _balls.erase( it );
		} else {
			it++;
		}

	}
}


