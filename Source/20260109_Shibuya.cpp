#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int RECT_GRAY = 255;
const int RECT_ALPHA = 50;
const int RECT_SPD = 5;
const int MIN_DIA = 20;
const int MAX_DIA = 300;
const int DIA_SPD = 2;
const double ANG_SPD = PI2 * 0.005;

struct Rect {
	Vector2 pos;
	Vector2 vec;
	int dia = MIN_DIA;
	int step = 1;
	double ang = 0;
};

Rect _rect;

void drawRect( ) {
	_rect.dia += DIA_SPD * _rect.step;
	if ( _rect.dia > MAX_DIA || _rect.dia < MIN_DIA ) {
		_rect.step *= -1;
	}

	_rect.pos += _rect.vec;
	int radius = _rect.dia / 2;
	if ( _rect.pos.x > WIDTH - radius ||
		 _rect.pos.x < radius ) {
		_rect.vec.x *= -1;
	}
	if ( _rect.pos.y > HEIGHT - radius ||
		 _rect.pos.y < radius ) {
		_rect.vec.y *= -1;
	}

	_rect.ang += ANG_SPD;

	rotate( _rect.ang );
	rect( _rect.pos.x, _rect.pos.y, _rect.dia, _rect.dia );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	noFill( );
	stroke( RECT_GRAY ,RECT_ALPHA);

	_rect.pos = Vector2( CENTER_X, CENTER_Y );
	_rect.vec = Vector2( RECT_SPD, 0 ).rotate( random( PI2 ) );
}

void draw( ) {
	drawRect( );
}


