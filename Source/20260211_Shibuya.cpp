#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;

const int LINE_ALPHA = 10;
const int COLOR_NUM = 3;
const int SPAWN_NUM = 50;
const int LINE_WEIGHT = 3;
const int MAX_DIA = 1500;
const int VER_NUM_MIN = 3;
const int VER_NUM_MAX = 6;
const double DIA_SPD_MIN = 1;
const double DIA_SPD_MAX = 3;
const double ANG_SPD_RANGE = PI * 0.01;

struct Shape {
	int col_id = 0;
	int ver_num = 0;
	int step = 1;
	double dia = 0;
	double dia_spd = 0;
	double base_ang = 0;
	double ang_spd = 0;
};

std::vector<Shape> _shapes;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	strokeWeight( LINE_WEIGHT );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Shape s;
		s.col_id = ( int )random( COLOR_NUM );
		s.ver_num = ( int )random( VER_NUM_MIN, VER_NUM_MAX );
		s.dia_spd = random( DIA_SPD_MIN, DIA_SPD_MAX );
		s.ang_spd = random( -ANG_SPD_RANGE, ANG_SPD_RANGE );
		_shapes.push_back( s );
	}
}

void draw( ) {
	for ( Shape& shape : _shapes ) {
		if ( shape.dia > MAX_DIA || shape.dia < 0 ) {
			shape.step *= -1;
			shape.col_id = ( int )random( COLOR_NUM );
		}

		switch ( shape.col_id ) {
		default :
			stroke( 0, 0, 0, LINE_ALPHA );
			break;
		case 0:
			stroke( 0, 0, 100, LINE_ALPHA );
			break;
		case 1:
			stroke( 0, 100, 100, LINE_ALPHA );
			break;
		}

		beginShape( );
		for ( int i = 0; i < shape.ver_num; i++ ) {
			double ang = shape.base_ang + PI2 * i / shape.ver_num;
			double x = CENTER_X + cos( ang ) * shape.dia;
			double y = CENTER_Y + sin( ang ) * shape.dia;
			vertex( x, y );
		}
		endShape( CLOSE );

		shape.dia += shape.dia_spd * shape.step;
		shape.base_ang += shape.ang_spd;
	}
}


