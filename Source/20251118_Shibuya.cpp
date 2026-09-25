#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int GAP = 1000;
const int ALPHA = 10;
const int DEGREE = 360;
const int RGB_RANGE = 400;

const double NOISE_RANGE = 0.01;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	blendMode( ADD );
}

void draw( ) {

	int ang = _frame_count % DEGREE;
	int x1 = CENTER_X + cos( radians( ang ) ) * GAP;
	int y1 = CENTER_Y + sin( radians( ang ) ) * GAP;

	int tang = ( ang + DEGREE / 2 ) % DEGREE;
	int x2 = CENTER_X + cos( radians( tang ) ) * GAP;
	int y2 = CENTER_Y + sin( radians( tang ) ) * GAP;

	double r = ( x1 + y1 ) * NOISE_RANGE * RGB_RANGE;
	double g = ( x2 + y2 ) * NOISE_RANGE * RGB_RANGE;
	double b = _frame_count * NOISE_RANGE * RGB_RANGE;
	stroke( r, g, b, ALPHA );

	line( x1, y1, x2, y2 );

	_frame_count++;
}


