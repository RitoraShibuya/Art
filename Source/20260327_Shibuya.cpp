#include "Processing.h"
#include <cmath>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 280;
const int FRAME_RATE = 15;
const int GRID_SIZE = 10;
const int GRID_RADIUS = GRID_SIZE / 2;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const int MIN_SPD = 1;
const int MAX_SPD = 3;
const double MUL_SCALE = 0.001;

struct Ball {
	Vector2 pos;
	Vector2 vec;
	int col_h = 0;
};

std::vector<Ball> _balls;

Vector2 warp( Vector2 val ) {
	if ( val.x > WIDTH ) {
		val.x = 0;
	} else if ( val.x < 0 ) {
		val.x = WIDTH;
	}
	if ( val.y > HEIGHT ) {
		val.y = 0;
	} else if ( val.y < 0 ) {
		val.y = HEIGHT;
	}
	return val;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
	setFrameRate( FRAME_RATE );

	for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
		int x = GRID_RADIUS + i * GRID_SIZE;
		for ( int j = 0; j < GRID_NUM_HEIGHT; j++ ) {
			int y = GRID_RADIUS + j * GRID_SIZE;
			int mul = (int)(x * y + x * y * MUL_SCALE);
			int spd = ( int )mul % MAX_SPD + MIN_SPD;
			double ang = std::fmod( mul, PI2 );
			Ball b;
			b.pos = Vector2( x, y );
			b.vec = Vector2( spd, 0 ).rotate( ang );
			b.col_h = mul % MAX_H;
			_balls.push_back( b );
		}
	}
}

void draw( ) {
	for ( Ball& ball : _balls ) {
		ball.pos += ball.vec;
		ball.pos = warp( ball.pos );
		ball.col_h = ball.col_h + getFrameRate() % MAX_H;
		stroke( ball.col_h, MAX_S, MAX_B );
		ellipse( ball.pos.x,ball.pos.y,GRID_SIZE );
	}
}


