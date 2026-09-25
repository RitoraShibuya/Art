#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int SPHERE_COLOR = 255;
const int SPHERE_ALPHA = 5;
const int START_NUM = 100;
const int DIAMETER = 5;
const int SPEED = 5;
const int MAX_RADIANS = 360;
const int HALF_RADIANS = 180;
const int TURN_RANGE = 20;
const int MAX_RANGE = 350;
const int MAX_DIAMETER = MAX_RANGE * 2;

struct ColSphere {
	double x = CENTER_X;
	double y = CENTER_Y;
	int ang = 0;
	int spd = SPEED;
};

std::list<ColSphere> _points;

void setup( ) {
	size( WIDTH, HEIGHT );

	blendMode( ADD );
	background( BACKGROUND );
	fill( SPHERE_COLOR, SPHERE_ALPHA );
	noStroke( );

	for ( int i = 0; i < START_NUM; i++ ) {
		ColSphere P;
		P.ang = ( int )random( MAX_RADIANS );
		_points.push_back( P );
	}
}

void draw( ) {
	for ( auto& p : _points ) {

		double dx = CENTER_X - p.x;
		double dy = CENTER_Y - p.y;
		double dirt = sqrt( dx * dx + dy * dy );
		if ( dirt >= MAX_RANGE ) {
			int tang = HALF_RADIANS + ( int )random( -TURN_RANGE, TURN_RANGE );
			p.ang = ( p.ang + tang ) % MAX_RADIANS;
		}

		double rad = radians( p.ang );
		p.x += cos( rad ) * p.spd;
		p.y += sin( rad ) * p.spd;

		ellipse( p.x, p.y, DIAMETER );
	}
}

