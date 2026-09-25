#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 255;
const int MAX_GRAVITY = 5.0;
const double GRAVITY  = 0.1;

const int BALL_GRAY = 0;
const int BALL_ALPHA = 20;
const int BALL_SPD = 2;
const int BALL_DIA = 50;
const int BALL_RADIUS = BALL_DIA / 2;
const int BAUNS_RANGE = 2;
const int BAUNS_SPD = 15;
const double BAUNS_RANDOM_RANGE = 2.0;
const double BAUNS_SCALE = 0.8;

struct Ball {
	Vector2 pos;
	Vector2 vec;
};

Ball _ball;

void updateBall( ) {
	_ball.vec += Vector2( 0.0, GRAVITY );
	_ball.pos += _ball.vec;

	if ( _ball.pos.x < 0 + BALL_RADIUS ||
		 _ball.pos.x > WIDTH - BALL_RADIUS ) {
		_ball.vec.x *= -1;
	}
	if ( _ball.pos.y > HEIGHT - BALL_RADIUS ) {
		_ball.pos.y = HEIGHT - BALL_RADIUS;
		if ( _ball.vec.y < BAUNS_RANGE ) {
			_ball.vec.x += random( -BAUNS_RANDOM_RANGE, BAUNS_RANDOM_RANGE );
			_ball.vec.y = BAUNS_SPD;
		} else {
			_ball.vec.y *= -BAUNS_SCALE;
		}
	}
}

void drawBall( ) {
	ellipse( _ball.pos.x, _ball.pos.y, BALL_DIA );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	fill( BALL_GRAY, BALL_ALPHA );
	noStroke( );

	_ball.pos = Vector2( WIDTH / 2, HEIGHT / 2 );
	_ball.vec = Vector2( BALL_SPD, 0 ).rotate( random( PI ) );
}

void draw( ) {
	updateBall( );
	drawBall( );
}


