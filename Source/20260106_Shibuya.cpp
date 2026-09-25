#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int POINT_GRAY = 255;
const int POINT_NUM = 4;
const int MIN_GAP = 0;
const int MAX_GAP = 250;
const double ANG_SPD = PI2 * 0.01;

struct Point {
	double ang = 0;
	int gap = MIN_GAP;
	bool add = true;
};

Point _point;

void updatePoint( ) {
	
	if ( _point.gap > MAX_GAP || _point.gap < MIN_GAP ) {
		_point.add = !_point.add;
	}

	if ( _point.add ) {
		_point.gap++;
	} else {
		_point.gap--;
	}

	_point.ang += ANG_SPD;
}

void drawPoint( ) {
	for ( int i = 0; i < POINT_NUM; i++ ) {
		double ang = _point.ang + PI2 * i / POINT_NUM;
		double x = CENTER_X + cos( ang ) * _point.gap;
		double y = CENTER_Y + sin( ang ) * _point.gap;
		point( x, y );
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( POINT_GRAY );
}

void draw( ) {
	updatePoint( );
	drawPoint( );
}


