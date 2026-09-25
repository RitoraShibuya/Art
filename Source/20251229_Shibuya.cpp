#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 255;
const int BACK_ALPHA = 20;

const int BALL_GRAY = 200;
const int OUTLINE_GRAY = 0;
const int OUTLINE_GAP = 10;
const int MIN_DIA = 50;
const int MAX_DIA = 200;
const int MIN_SPD = 1;
const int MAX_SPD = 5;

struct Ball {
	Vector2 pos;
	Vector2 vec;
	int dia = ( int )random( MIN_DIA, MAX_DIA );
	int out_dia = dia + OUTLINE_GAP;
};

std::list<Ball> _balls;

int clamp( int n, int min, int max ) {
	if ( n < min ) {
		n = min;
	} else if ( n > max ) {
		n = max;
	}
	return n;
}

void updateBall( ) {
	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;
		ball.pos += ball.vec;
		if ( ball.pos.x > WIDTH || ball.pos.x < 0 ) {
			ball.pos.x = clamp( ball.pos.x, 0, WIDTH );
			ball.vec.x *= -1;
		}if ( ball.pos.y > HEIGHT || ball.pos.y < 0 ) {
			ball.pos.y = clamp( ball.pos.y, 0, HEIGHT );
			ball.vec.y *= -1;
		}
		it++;
	}
}

void drawOutline( ) {
	fill( OUTLINE_GRAY );

	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;
		ellipse( ball.pos.x, ball.pos.y, ball.out_dia );
		it++;
	}
}

void drawBall( ) {
	fill( BALL_GRAY );

	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;
		ellipse( ball.pos.x, ball.pos.y, ball.dia );
		it++;
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	updateBall( );
	drawOutline( );
	drawBall( );
}

void mouseClicked( ) {
	Ball b;
	b.pos = Vector2( getMouseX( ), getMouseY( ) );
	int spd = ( int )random( MIN_SPD, MAX_SPD );
	double ang = random( PI2 );
	b.vec = Vector2( spd, 0 ).rotate( ang );
	_balls.push_back( b );
}
