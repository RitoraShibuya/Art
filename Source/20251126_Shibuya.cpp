#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int GRAY = 255;
const int PETAL_NUM = 7;
const int MAX_DIA = 300;
const int SPEED = 5;

struct Petal {
	int x = 0;
	int y = 0;
	int dia = MAX_DIA;
	double ang = 0;
};

std::list<Petal> _flower;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	fill( GRAY );
}

void draw( ) {

	std::list<Petal>::iterator it = _flower.begin( );
	while ( it != _flower.end( ) ) {
		it->x += cos( it->ang ) * SPEED;
		it->y += sin( it->ang ) * SPEED;
		it->dia -= SPEED;

		ellipse( it->x, it->y, it->dia );

		if ( it->dia <= 0 ) {
			it = _flower.erase( it );
		} else {
			it++;
		}

	}

}

void mouseClicked( ) {

	for ( int i = 0; i < PETAL_NUM; i++ ) {
		Petal p;
		p.x = getMouseX( );
		p.y = getMouseY( );
		p.ang = TWO_PI * i / PETAL_NUM;
		_flower.push_back( p );
	}
}

