#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int POINT_COUNT = 270;
const int GAP = 500;
const int SPEED = 2;
const int RGB_MAX = 255;
const double NOISE_RANGE = 0.01;

int _framecount = 0;

struct ColPoint {
	double x = 0;
	double y = 0;
	int ang = 0;
};

ColPoint _center;
ColPoint _points[ POINT_COUNT ];

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	_center.y = CENTER_Y;
}

void draw( ) {
	int r = noise( _center.x * NOISE_RANGE ) * RGB_MAX;
	int g = noise( _center.y * NOISE_RANGE ) * RGB_MAX;
	int b = noise( _framecount * NOISE_RANGE ) * RGB_MAX;
	stroke( r, g, b );

	for ( int i = 0; i < POINT_COUNT; i++ ) {
		_points[ i ].ang = i + _center.ang;

		double x_noise = _points[ i ].x * NOISE_RANGE;
		double y_noise = _points[ i ].y * NOISE_RANGE;
		double ang_noise = _points[ i ].ang * NOISE_RANGE;
		double gap = noise( x_noise, y_noise, ang_noise ) * GAP;
		double rad = radians( _points[ i ].ang );

		_points[ i ].x = _center.x + cos( rad ) * gap;
		_points[ i ].y = _center.y + sin( rad ) * gap;
		point( _points[ i ].x, _points[ i ].y );
	}
	_center.ang += SPEED;
	_center.x -= SPEED;
	if ( _center.x < 0 ) {
		_center.x = WIDTH;
	}
	_framecount++;
}


