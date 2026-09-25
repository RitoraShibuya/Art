#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int POINT_GRAY = 255;
const int POINT_ALPHA = 10;
const int MAX_GAP = 30;
const int SPAWN_NUM = 1000;
const double NOISE_RANGE = 0.01;

int _frame_count = 0;
std::vector<Vector2> _points;

double warp( double num, double min, double max ) {
	if ( num < min ) {
		num = max;
	} else if ( num > max ) {
		num = min;
	}
	return num;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( POINT_GRAY, POINT_ALPHA );
	noFill( );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		_points.push_back( Vector2( CENTER_X, CENTER_Y ) );
	}
}

void draw( ) {
	background( BACKGROUND );

	int count = 0;
	beginShape( );
	for ( Vector2& point : _points ) {
		double n1 = point.getLength2( ) * NOISE_RANGE;
		double n2 = ( double )count / SPAWN_NUM * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double noise_val = noise( n1, n2, n3 );
		double gap = noise_val * MAX_GAP;
		double ang = noise_val * PI2;
		point = point + Vector2( gap, 0.0 ).rotate( ang );
		vertex( point.x, point.y );

		point.x = warp( point.x, 0, WIDTH );
		point.y = warp( point.y, 0, HEIGHT );

		count++;
	}
	endShape( );

	_frame_count++;
}
