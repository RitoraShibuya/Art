#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int DRAW_NUM = 5000;
const int BALL_GRAY = 255;
const int BALL_ALPHA = 1;
const int BALL_DIA = 50;
const int GAP = 500;
const int NOISE_GAP = 100;
const double ANG_SPD = PI2 * 1 / 200;
const double NOISE_RANGE = 0.005;

struct Ball {
	Vector2 pos;
	double ang = 0;
};

Ball _ball;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	fill( BALL_GRAY, BALL_ALPHA );

	for ( int i = 0; i < DRAW_NUM; i++ ) {
		double n1 = _ball.pos.x * NOISE_RANGE;
		double n2 = _ball.pos.y * NOISE_RANGE;
		double n3 = i * NOISE_RANGE;
		double ang_spd = noise( n1 + NOISE_GAP, n2 + NOISE_GAP, n3 ) * ANG_SPD;
		double gap = noise( n1, n2, n3 ) * GAP;
		_ball.ang += ang_spd;
		_ball.pos.x = CENTER_X + cos( _ball.ang ) * gap;
		_ball.pos.y = CENTER_Y + sin( _ball.ang ) * gap;

		ellipse( _ball.pos.x, _ball.pos.y, BALL_DIA );
	}
}
