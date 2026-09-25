#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int MAX_DIA = 1000;
const int MIN_DIA_SPD = 1;
const int MAX_DIA_SPD = 5;
const int SPAWN_INTERVAL = 30;
const int STROKE_WEIGHT = 10;
const double ANG_SPD = PI2 * 1 / 500;

struct Plane {
	int dia = MAX_DIA;
	int dia_spd = MIN_DIA_SPD;
	int step = 1;
	int gray = 0;
	double ang = 0;
};

int _frame_count = 0;
std::list<Plane> _planes;

void spawnPlane( ) {
	Plane p;
	p.dia_spd = ( int )random( MIN_DIA_SPD, MAX_DIA_SPD );
	p.step = ( int )random( 2 ) * 2 - 1;
	p.gray = ( int )random( 2 ) * 255;
	_planes.push_back( p );
}

void drawPlane( ) {
	Vector2 center( WIDTH / 2, HEIGHT / 2 );
	std::list<Plane>::iterator it = _planes.begin( );
	while ( it != _planes.end( ) ) {
		Plane& plane = *it;
		plane.dia -= plane.dia_spd;
		plane.ang += plane.step * ANG_SPD;

		stroke( plane.gray );
		rotate( plane.ang );
		rect( CENTER_X, CENTER_Y, plane.dia, plane.dia );
		rotate( -plane.ang );

		if ( plane.dia <= 0 ) {
			it = _planes.erase( it );
		} else {
			it++;
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noFill( );
	strokeWeight( STROKE_WEIGHT );
	rectMode( CENTER );
}

void draw( ) {
	if ( _frame_count % SPAWN_INTERVAL == 0 ) {
		spawnPlane( );
	}
	drawPlane( );

	_frame_count++;
}


