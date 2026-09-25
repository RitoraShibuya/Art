#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int CIRCLE_GRAY = 255;
const int CIRCLE_ALPHA = 10;
const double MIN_SPD = 1;
const double MAX_SPD = 3;
const double MIN_DIA_SPD = 1;
const double MAX_DIA_SPD = 5;
const double MIN_DIA_RANGE = 50;
const double MAX_DIA_RANGE = 200;
const double MIN_ANG_SPD = PI2 * 0.001;
const double MAX_ANG_SPD = PI2 * 0.005;

struct Circle {
	Vector2 pos;
	Vector2 vec;
	int dia = 0;
	int dia_spd = 0;
	int min_dia = MIN_DIA_RANGE;
	int max_dia = MAX_DIA_RANGE;
	double ang_spd = 0;
	bool is_max_dia = false;
};

Circle _circle;

void resetStates( ) {
	_circle.ang_spd = random( MIN_ANG_SPD, MAX_ANG_SPD );

	if ( _circle.is_max_dia ) {
		_circle.min_dia = _circle.dia - random( MIN_DIA_RANGE, MAX_DIA_RANGE );
		_circle.dia_spd = -random( MIN_DIA_SPD, MAX_DIA_SPD );
	} else {
		_circle.max_dia = _circle.dia + random( MIN_DIA_RANGE, MAX_DIA_RANGE );
		_circle.dia_spd = random( MIN_DIA_SPD, MAX_DIA_SPD );
	}
}

void resetAll( ) {
	_circle.dia = 0;
	_circle.min_dia = MIN_DIA_RANGE;
	_circle.max_dia = MAX_DIA_RANGE;
	_circle.is_max_dia = false;
	resetStates( );
	_circle.pos = Vector2( WIDTH / 2, HEIGHT / 2 );
	_circle.vec = Vector2( random( MIN_SPD, MAX_SPD ), 0 ).rotate( random( PI2 ) );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noFill( );
	stroke( CIRCLE_GRAY, CIRCLE_ALPHA );

	resetAll( );
}

void draw( ) {
	_circle.vec = _circle.vec.rotate( _circle.ang_spd );
	_circle.pos += _circle.vec;
	_circle.dia += _circle.dia_spd;

	if ( _circle.dia > _circle.max_dia ) {
		_circle.is_max_dia = true;
		resetStates( );
	}

	if ( _circle.dia < _circle.min_dia ) {
		_circle.is_max_dia = false;
		resetStates( );
	}

	ellipse( _circle.pos.x, _circle.pos.y, _circle.dia );
}

void mouseClicked( ) {
	resetAll( );
}