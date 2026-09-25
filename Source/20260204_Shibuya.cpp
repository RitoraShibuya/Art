#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACKGROUND = 0;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int LEZER_ALPHA = 20;
const int SPD = 50;
const int STROKE_WEIGHT = 10;
const double NOISE_RANGE = 0.03;

struct Lezer {
	Vector2 pos;
	Vector2 vec;
};

Lezer _lezer;

void initLezer( ) {
	_lezer.pos = Vector2( WIDTH / 2, HEIGHT / 2 );
	_lezer.vec = Vector2( SPD, 0 ).rotate( random( PI2 ) );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	blendMode( ADD );
	strokeWeight( STROKE_WEIGHT );

	initLezer( );
}

void draw( ) {
	if ( _lezer.pos.x > WIDTH || _lezer.pos.x < 0 ) {
		_lezer.vec.x *= -1;
	}
	if ( _lezer.pos.y > HEIGHT || _lezer.pos.y < 0 ) {
		_lezer.vec.y *= -1;
	}
	Vector2 prev = _lezer.pos;
	_lezer.pos += _lezer.vec;

	double n1 = _lezer.pos.x * NOISE_RANGE;
	double n2 = _lezer.pos.y * NOISE_RANGE;
	double n3 = _lezer.pos.getLength( ) * NOISE_RANGE;
	double col_h = noise( n1, n1, n3 ) * MAX_H;

	stroke( col_h, MAX_S, MAX_B, LEZER_ALPHA );
	line( prev, _lezer.pos );
}

void mouseClicked( ) {
	initLezer( );
}