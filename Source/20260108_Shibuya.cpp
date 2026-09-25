#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int BALL_NUM = 5;
const int BALL_DIA = 10;
const int BALL_RADIUS = BALL_DIA / 2;
const int BALL_SPD = 5;

const int POINT_GRAY = 255;
const int POINT_NUM = 1000;
const int MAX_GAP = 750;
const double NOISE_RANGE = 0.01;

struct Ball {
	Vector2 pos;
	Vector2 vec;
};

int _frame_count = 0;
std::list<Ball> _balls;

void checkHit(Vector2 pos ) {
	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;
		double dist = ( ball.pos - pos ).getLength( );
		if ( dist < BALL_RADIUS ) {
			ball.vec *= -1;
			ball.pos += ball.vec;
		}
		it++;
	}
}

void spawnBall( ) {
	Ball b;
	b.pos = Vector2( CENTER_X, CENTER_Y );
	b.vec = Vector2( BALL_SPD, 0 ).rotate( random( PI2 ) );
	_balls.push_back( b );
}

void drawPoint( ) {
	for ( int i = 0; i < POINT_NUM; i++ ) {
		double ang = PI2 * i * 2 / POINT_NUM;
		double n1 = ang * NOISE_RANGE;
		double n2 = i * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double gap = noise( n1, n2, n3 ) * MAX_GAP;
		double x = CENTER_X + cos( ang ) * gap;
		double y = CENTER_Y + sin( ang ) * gap;

		checkHit( Vector2( x, y ) );

		point( x, y );
	}
}

void drawBall() {
	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;
		ball.pos += ball.vec;
		ellipse( ball.pos.x, ball.pos.y, BALL_DIA, BALL_DIA );
		it++;
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( POINT_GRAY );
	noFill( );

	for ( int i = 0; i < BALL_NUM; i++ ) {
	spawnBall( );
	}
}

void draw( ) {
	background( BACKGROUND );

	drawPoint( );
	drawBall();

	_frame_count++;
}

void mouseClicked( ) {
	spawnBall( );
}
