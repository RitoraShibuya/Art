#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 255;

const int BALL_R = 200;
const int BALL_G = 255;
const int BALL_B = 255;
const int BALL_ALPHA = 100;
const int SPAWN_NUM = 75;
const int MIN_DIA = 100;
const int MAX_DIA = 400;
const int BALL_SPD = 1;

struct Ball {
	Vector2 pos;
	Vector2 vec;
	int dia = 0;
};
std::vector<Ball> _balls;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	blendMode( SUBTRACT );
	fill( BALL_R, BALL_G, BALL_G, BALL_ALPHA );
	noStroke( );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Ball b;
		b.pos = Vector2( random( WIDTH ), random( HEIGHT ) );
		b.vec = Vector2( BALL_SPD, 0 ).rotate( random( PI2 ) );
		b.dia = ( int )random( MIN_DIA, MAX_DIA );
		_balls.push_back( b );
	}
}

void draw( ) {
	background( BACKGROUND );
	for ( Ball& ball : _balls ) {
		ball.pos += ball.vec;
		if ( ball.pos.x > WIDTH || ball.pos.x < 0 ) {
			ball.vec.x *= -1;
		}
		if ( ball.pos.y > HEIGHT || ball.pos.y < 0 ) {
			ball.vec.y *= -1;
		}

		ellipse( ball.pos.x, ball.pos.y, ball.dia );
	}
}


