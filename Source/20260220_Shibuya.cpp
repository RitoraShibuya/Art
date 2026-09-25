#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int BALL_GRAY = 255;
const int DIA_MAX = 300;
const int GOAL_RANGE = 5;
const double DIST_MAX = sqrt( WIDTH * WIDTH + HEIGHT * HEIGHT );
const double BALL_SPD = 0.01;
const double FRAMES = 1.0 / BALL_SPD;

struct Ball {
	Vector2 pos;
	Vector2 next_pos;
	int step = -1;
	double dia = 0;
	double dia_spd = 0;
};

Ball _ball;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	fill( BALL_GRAY );

	_ball.pos = Vector2( CENTER_X, CENTER_Y );
	_ball.next_pos = _ball.pos;
	_ball.dia = DIA_MAX;
	_ball.dia -= _ball.dia_spd;
}

void draw( ) {
	Vector2 dir = _ball.next_pos - _ball.pos;
	_ball.pos += dir * BALL_SPD;
	_ball.dia -= _ball.dia_spd * _ball.step;
	if ( _ball.dia > DIA_MAX ) {
		_ball.dia = DIA_MAX;
	}
	if ( _ball.dia < 0 ) {
		_ball.dia = 0;
	}

	ellipse( _ball.pos.x, _ball.pos.y, _ball.dia );
}

void mouseClicked( ) {
	_ball.next_pos = Vector2( getMouseX( ), getMouseY( ) );
	_ball.step *= -1;
	_ball.dia_spd = DIA_MAX / FRAMES;
}
