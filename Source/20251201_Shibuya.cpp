#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int GRAY = 255;
const int FRAMERATE = 30;
const int BACK_ALPHA = 5;
const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 20;
const int GAP = 20;
const int STEP_DIST = 30;
const double SPD = 0.005;

struct Step {
	double x = 0;
	double y = 0;
	double ang = 0;
	bool right = true;
};

int _frame_count = 0;
Step _center;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	setFrameRate(FRAMERATE );
	fill( GRAY );
}

void draw( ) {

	background( BACKGROUND, BACK_ALPHA );

	int mx = getMouseX( );
	int my = getMouseY( );

	double dx = mx - _center.x;
	double dy = my - _center.y;

	_center.x += dx * SPD;
	_center.y += dy * SPD;

	_center.ang = atan2( dy, dx );

	double normal_x = -sin( _center.ang );
	double normal_y = cos( _center.ang );

	if ( _frame_count % STEP_DIST == 0 ) {

		double side = 1.0;
		if ( _center.right ) {

			side = -1.0;
		}
		_center.right = !_center.right;

		double px = _center.x + normal_x * GAP * side;
		double py = _center.y + normal_y * GAP * side;

		rotate( _center.ang );
		rect( px, py, RECT_WIDTH, RECT_HEIGHT );
		rotate( -_center.ang );
	}

	_frame_count++;
}
