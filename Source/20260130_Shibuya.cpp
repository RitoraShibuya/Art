#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 2;

const int SHAPE_GRAY = 255;
const int SHAPE_ALPHA = 10;
const int SHAPE_WEIGHT = 5;
const int VER_NUM = 5;
const int INTERVAL = 100;
const int GAP = 100;
const double ANG_SPD = PI2 / 100;

int _frame_count = 0;
double _base_ang = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( SHAPE_GRAY, SHAPE_ALPHA );
	strokeWeight( SHAPE_WEIGHT );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	if ( _frame_count % INTERVAL == 0 ) {
		_base_ang += ANG_SPD;
	}


	beginShape( );
	for ( int i = 0; i < VER_NUM; i++ ) {
		double ang = _base_ang + PI2 * i / VER_NUM;
		double x = CENTER_X + cos( ang ) * GAP;
		double y = CENTER_Y + sin( ang ) * GAP;
		vertex( x, y );
	}
	endShape( CLOSE );

	_frame_count++;
}


