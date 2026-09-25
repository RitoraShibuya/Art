#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int COLOR = 255;
const int ALPHA = 100;
const int POINTS_NUM = 200;
const int GAP = 200;
const int RANGE = 3;
const int X_GAP = WIDTH / POINTS_NUM;
const int Y_GAP = HEIGHT / POINTS_NUM;
const int DIAMETER = 50;

const double ANGLE_SPEED = 0.01;

struct Points {
	double x = 0;
	double y = 0;
	double ang = 0;
};

Points _points[ POINTS_NUM ];

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( COLOR );
	fill( COLOR, ALPHA );

	for ( int i = 0; i < POINTS_NUM; i++ ) {
		_points[ i ].ang = PI2 * RANGE * i / POINTS_NUM;
	}
}

void draw( ) {
	background( BACKGROUND );

	for ( int i = 0; i < POINTS_NUM; i++ ) {
		_points[ i ].x = i * X_GAP + sin( _points[ i ].ang ) * GAP;
		_points[ i ].y = HEIGHT - ( i * Y_GAP ) + sin( _points[ i ].ang ) * GAP;

		ellipse( _points[ i ].x, _points[ i ].y, DIAMETER );

		_points[ i ].ang += ANGLE_SPEED;
	}
}
