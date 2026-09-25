#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int BALL_GRAY = 255;
const int BALL_ALPHA = 50;
const int BALL_DIA = 100;
const int BALL_RADIUS = BALL_DIA / 2;
const double BALL_SPD = 0.1;
const double MAX_SPD = 20.0;
const double ANG_SPD = PI2 * 0.01;

const int BLOCK_GRAY = 0;
const int BLOCK_ALPHA = 20;
const int BLOCK_WIDTH = 200;
const int BLOCK_HEIGHT = 100;
const int BLOCK_WIDTH_RADIUS = BLOCK_WIDTH / 2;
const int BLOCK_HEIGHT_RADIUS = BLOCK_HEIGHT / 2;
const double BLOCK_SPD = 0.05;

struct Ball {
	Vector2 pos;
	int step = 1;
	double spd = 0;
	double ang = 0;
};

Ball _ball;
Vector2 _block;

void setPos( ) {
	double dx = _ball.pos.x - _block.x;
	double dy = _ball.pos.y - _block.y;
	double olx = ( BLOCK_WIDTH_RADIUS + BALL_RADIUS ) - std::abs( dx );
	double oly = ( BLOCK_HEIGHT_RADIUS + BALL_RADIUS ) - std::abs( dy );
	if ( olx < oly ) {
		if ( dx > 0.0 ) {
			_ball.pos.x += olx;
		} else {
			_ball.pos.x -= olx;
		}
	} else {
		if ( dy > 0.0 ) {
			_ball.pos.y += oly;
		} else {
			_ball.pos.y -= oly;
		}
	}
}

bool checkHit( ) {
	bool hit = false;

	int ball_lx = _ball.pos.x - BALL_RADIUS;
	int ball_rx = _ball.pos.x + BALL_RADIUS;
	int block_lx = _block.x - BLOCK_WIDTH_RADIUS;
	int block_rx = _block.x + BLOCK_WIDTH_RADIUS;
	if ( ball_lx < block_rx && ball_rx > block_lx ) {
		int ball_ly = _ball.pos.y - BALL_RADIUS;
		int ball_ry = _ball.pos.y + BALL_RADIUS;
		int block_ly = _block.y - BLOCK_HEIGHT_RADIUS;
		int block_ry = _block.y + BLOCK_HEIGHT_RADIUS;
		if ( ball_ly < block_ry && ball_ry > block_ly ) {
			setPos( );
			hit = true;
		}
	}


	return hit;
}

void initBall( ) {
	_ball.pos = Vector2( CENTER_X, CENTER_Y );
}

void drawBall( ) {
	fill( BALL_GRAY, BALL_ALPHA );
	ellipse( _ball.pos.x, _ball.pos.y, BALL_DIA );

	_ball.ang += ANG_SPD;
	Vector2 vec = Vector2( _ball.spd, 0.0 ).rotate( _ball.ang );
	_ball.spd += BALL_SPD * _ball.step;
	_ball.pos += vec;
	if ( _ball.spd > MAX_SPD ) {
		_ball.spd = MAX_SPD;
		_ball.step = -1;
	} else if ( _ball.spd < 0 ) {
		_ball.spd = 0;
		_ball.step = 1;
	}
	if ( _ball.pos.x > WIDTH || _ball.pos.x < 0 ) {
		_ball.pos.x = WIDTH - _ball.pos.x;
	}
	if ( _ball.pos.y > HEIGHT || _ball.pos.y < 0 ) {
		_ball.pos.y = HEIGHT - _ball.pos.y;
	}

}

void drawBlock( ) {
	Vector2 pos = Vector2( getMouseX( ), getMouseY( ) );
	Vector2 dist = pos - _block;
	_block += dist * BLOCK_SPD;

	if ( checkHit( ) ) {
		fill( BLOCK_GRAY ,BLOCK_ALPHA);
		rect( _block.x, _block.y, BLOCK_WIDTH, BLOCK_HEIGHT );
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
	rectMode( CENTER );

	initBall( );
}

void draw( ) {
	drawBlock( );
	drawBall( );
}


