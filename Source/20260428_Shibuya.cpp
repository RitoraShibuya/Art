#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACK_R = 255;
const int BACK_G = 55;
const int BACK_B = 105;
const int BALL_GRAY = 0;
const int BALL_A = 20;
const int SPAWN_NUM = 5;
const int DIA_MIN = 50;
const int DIA_MAX = 200;
const double SPD_MIN = 1.0;
const double SPD_MAX = 3.0;
const double GAP_AMPLITUDE = 1.0;
const double DELTA_SPD = 0.01;
const double ANG_SPD = 0.01;
const double BASE_ANG_SPD = 0.005;

struct Ball {
	Vector2 pos;
	int dia = 0;
	double spd = 0;
	double ang = 0;
	double delta = 0;
};

std::list<Ball> _balls;
double _base_ang = 0;

void spawnBall( ) {
	_balls.clear( );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double ang = PI2 * i / SPAWN_NUM;

		Ball b;
		b.pos = Vector2( CENTER_X, CENTER_Y );
		b.dia = ( int )random( DIA_MIN, DIA_MAX );
		b.spd = random( SPD_MIN, SPD_MAX );
		b.ang = ang;
		_balls.push_back( b );
	}
}


void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_B, BACK_G );

	spawnBall( );
}

void draw( ) {

	for ( Ball& ball : _balls ) {
		double ang = ball.ang + _base_ang;
		double gap = sin( ball.delta ) * GAP_AMPLITUDE;
		Vector2 vec = Vector2( ball.spd * gap, 0.0 ).rotate( ang );
		ball.pos += vec;
		stroke( BALL_GRAY, BALL_A );
		ellipse( ball.pos.x, ball.pos.y, ball.dia );
		ball.ang += ANG_SPD;
		ball.delta += DELTA_SPD;
	}
	_base_ang -= BASE_ANG_SPD;
}

void mouseClicked( ) {
	spawnBall( );
}