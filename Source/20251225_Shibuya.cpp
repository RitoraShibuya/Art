#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 1;

const int POINT_GRAY = 255;
const int POINT_ALPHA = 50;
const int POINT_NUM = 2000;
const int FLOWER_NUM = 2;
const double ANG_SPD = PI2 * 1 / 360;
const double NOISE_RANGE = 0.01;

struct Flower {
	Vector2 pos;
	int base_dia = 0;
	double base_ang = 0;
};

Flower _flow;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( POINT_GRAY, POINT_ALPHA );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	for ( int i = 0; i < POINT_NUM; i++ ) {
		double ang = _flow.base_ang + ( PI2 * FLOWER_NUM * i / POINT_NUM );
		double n1 = _flow.pos.x * NOISE_RANGE;
		double n2 = _flow.pos.y * NOISE_RANGE;
		double n3 = i * NOISE_RANGE;
		double dia = noise( n1, n2, n3 ) * _flow.base_dia;
		double x = _flow.pos.x + cos( ang ) * dia;
		double y = _flow.pos.y + sin( ang ) * dia;

		point( x, y );
	}


	_flow.base_dia++;
	_flow.base_ang += ANG_SPD;
}

void mouseClicked( ) {
	_flow.pos = Vector2( getMouseX( ), getMouseY( ) );
	_flow.base_dia = 0;
	_flow.base_ang = random( PI2 );
}
