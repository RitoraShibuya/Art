#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int MAX_ALPHA = 255;
const int BACK_H = 180;
const int BACK_S = 50;
const int BACK_B = 20;
const int MAX_SPAWN = 2000;
const int SPAWN_NUM = 50;
const int MIN_SPD = 1;
const int MAX_SPD = 10;
const int MIN_DIA = 2;
const int MAX_DIA = 10;
const int COLLISION_MARGIN = 2;

struct Ball {
	Vector2 pos;
	Vector2 vec;
	double dia = 0;
	double col_h = 0;
	double alpha = 0;
	bool is_alive = true;
};

int _spawn_count = 0;
std::list<Ball> _balls;

void spawnBall( ) {
	if ( _spawn_count > MAX_SPAWN ) {
		return;
	}
	Ball b;
	double sx = random( WIDTH );
	double sy = random( HEIGHT );
	b.pos = Vector2( sx, sy );
	double spd = random( MIN_SPD, MAX_SPD );
	double ang = random( PI2 );
	b.vec = Vector2( spd, 0.0 ).rotate( ang );
	b.dia = random( MIN_DIA, MAX_DIA );
	b.col_h = random( MAX_H );
	b.alpha = random( MAX_ALPHA );
	_balls.push_back( b );
	_spawn_count++;
}

void checkHit( Ball& ball ) {
	for ( Ball& other_ball : _balls ) {
		if ( &other_ball == &ball ) {
			continue;
		}
		double radius = ball.dia * 0.5;
		double other_radius = other_ball.dia * 0.5;
		double dist = ( ball.pos - other_ball.pos ).getLength( );
		if ( dist < radius + other_radius + COLLISION_MARGIN ) {
			if ( !other_ball.is_alive ) {
				ball.is_alive = false;
				spawnBall( );
				spawnBall( );
			} else {
				ball.vec *= -1;
			}
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, BACK_S, BACK_B );
	noFill( );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		spawnBall( );
	}
}

void draw( ) {
	background( BACK_H, BACK_S, BACK_B );

	for ( Ball& ball : _balls ) {
		stroke( ball.col_h, MAX_S, MAX_B, ball.alpha );
		ellipse( ball.pos.x, ball.pos.y, ball.dia );

		if ( !ball.is_alive ) {
			continue;
		}

		ball.pos += ball.vec;

		if ( ball.pos.x > WIDTH || ball.pos.x < 0 ||
			 ball.pos.y > HEIGHT || ball.pos.y < 0 ) {
			ball.is_alive = false;
			spawnBall( );
			spawnBall( );
		}

		checkHit( ball );
	}
}