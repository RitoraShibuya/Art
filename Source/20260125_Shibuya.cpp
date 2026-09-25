#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int CIRCLE_ALPHA = 30;
const int MAX_DIA = 1500;
const int DIA_SPD = 4;
const int SPAWN_INTERVAL = 30;

struct Circle {
	int dia = MAX_DIA;
	int col_h = 0;
};

int _frame_count = 0;
std::list<Circle> _circles;

void spawnCircle( ) {
	Circle c;
	c.col_h = ( int )random( MAX_H );
	_circles.push_back( c );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	noFill( );

	spawnCircle( );
}

void draw( ) {
	std::list<Circle>::iterator it = _circles.begin( );
	while ( it != _circles.end( ) ) {
		Circle& circle = *it;
		stroke( circle.col_h, MAX_S, MAX_B, CIRCLE_ALPHA );
		ellipse( CENTER_X, CENTER_Y, circle.dia );
		circle.dia -= DIA_SPD;
		if ( circle.dia <= 0 ) {
			it = _circles.erase( it );
		} else {
			it++;
		}
	}

	if ( _frame_count % SPAWN_INTERVAL == 0 ) {
		spawnCircle( );
	}
	_frame_count++;
}


