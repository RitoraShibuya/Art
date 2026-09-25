#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const double CENTER_WIDTH = WIDTH / 2;
const double CENTER_HEIGHT = HEIGHT / 2;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_G = 255;
const int SHAPE_ALPHA = 5;
const int DIA_MIN = 5;
const int DIA_MAX = 100;
const double VEC_SPD = 1.5;
const double ANG_SPD = 0.008;

struct Shape {
	Vector2 pos = { 0.0,0.0 };
	int dia = 0;
	int col_h = 0;
	double ang = 0.0;
};


std::list<Shape> _shapes;

bool CheckOutRange( Vector2 pos ) {
	if ( pos.x > WIDTH || pos.x < 0 ||
		 pos.y > HEIGHT || pos.y < 0 ) {
		return true;
	}
	return false;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_S, MAX_S, MAX_B );
	background( BACK_G );
	noStroke( );
}

void draw( ) {
	static Vector2 pos = { CENTER_WIDTH,CENTER_HEIGHT };
	int rand_dia = random( DIA_MIN, DIA_MAX );
	int rand_h = random( MAX_H );
	double rand_ang = random( PI2 );
	_shapes.push_back( Shape { pos, rand_dia, rand_h,rand_ang } );
	int col_b = (int)((0.5 + 0.5 * sin( getFrameCount( ) * 0.05 )) * MAX_B);

	std::list<Shape>::iterator it = _shapes.begin( );
	while ( it != _shapes.end( ) ) {
		Shape& shape = *it;
		Vector2 vec { VEC_SPD, 0.0 };
		shape.ang += ANG_SPD;
		vec = vec.rotate( ANG_SPD + shape.ang );
		shape.pos += vec;

		fill( shape.col_h, MAX_S, col_b, SHAPE_ALPHA );
		ellipse( shape.pos.x, shape.pos.y, shape.dia );

		if ( CheckOutRange( shape.pos ) ) {
			it = _shapes.erase( it );
		} else {
			it++;
		}
	}
}


