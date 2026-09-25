#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int BACKGROUND = 0;

const int GRID_COUNT = 100;
const int GRID_SIZE = 10;
const int GRID_RADIUS = GRID_SIZE / 2;
const int LINE_LENGTH = 1000;
const double SPREAD = PI / 4.0;
const double MAX_DIST = sqrt( WIDTH * WIDTH + HEIGHT * HEIGHT );

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	background( BACKGROUND );
	Vector2 center( CENTER_X, HEIGHT );

	double base_ang = map( getMouseX( ), 0, WIDTH, -PI, 0 );
	double ang1 = base_ang - SPREAD;
	double ang2 = base_ang + SPREAD;
	Vector2 pos1 = center + Vector2( LINE_LENGTH, 0 ).rotate( ang1 );
	Vector2 pos2 = center + Vector2( LINE_LENGTH, 0 ).rotate( ang2 );

	for ( int i = 0; i < GRID_COUNT; i++ ) {
		for ( int j = 0; j < GRID_COUNT; j++ ) {
			Vector2 pos( GRID_RADIUS + i * GRID_SIZE, GRID_RADIUS + j * GRID_SIZE );
			Vector2 to_point = pos - center;
			double ang = atan2( to_point.y, to_point.x );
			double dist = to_point.getLength( );
			int alpha = ( int )map( dist, 0, MAX_DIST, 255, 0 );

			if ( ang > ang1 && ang < ang2 ) {
				stroke( 255, 0, 0, alpha );
			} else if ( ang <= ang1 ) {
				stroke( 0, 255, 0, alpha );
			} else {
				stroke( 0, 0, 255, alpha );
			}
			point( pos );
		}
	}
}
