#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 5;

const int STROKE_GRAY = 255;
const int STROKE_ALPHA = 20;
const int MID_SPAWN_NUM = 5;
const int SPAWN_NUM = 3;
const int BASE_GAP = 300;
const int MID_GAP = 100;
const int GAP = 200;
const double BASE_ANG_SPD = PI2 * 1 / 200;
const double MID_ANG_SPD = PI2 * 2 / 200;
const double ANG_SPD = PI2 * 1 / 200;

struct Circle {
	Vector2 pos;
	double ang = 0;
};

Circle _base;
std::vector<Circle> _mid_circles;
std::vector<Circle> _circles;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( STROKE_GRAY,STROKE_ALPHA );

	for ( int i = 0; i < MID_SPAWN_NUM; i++ ) {
		Circle c;
		c.ang = PI2 * i / MID_SPAWN_NUM;
		_mid_circles.push_back( c );
	}
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Circle c;
		c.ang = PI2 * i / SPAWN_NUM;
		_circles.push_back( c );
	}
}

void draw( ) {
	background( BACKGROUND ,BACK_ALPHA);

	Vector2 center = Vector2( CENTER_X, CENTER_Y );
	_base.ang += BASE_ANG_SPD;
	_base.pos = center + Vector2( GAP, 0 ).rotate( _base.ang );

	for ( Circle& mid : _mid_circles ) {
		mid.ang -= MID_ANG_SPD;
		mid.pos = _base.pos + Vector2( GAP, 0 ).rotate( mid.ang );
		line( _base.pos, mid.pos );
		for ( Circle& circle : _circles ) {
			circle.ang += ANG_SPD;
			circle.pos = mid.pos + Vector2( GAP, 0 ).rotate( circle.ang );
			line( mid.pos, circle.pos );
		}
	}
}


