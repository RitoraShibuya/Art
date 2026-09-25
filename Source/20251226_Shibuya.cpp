#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int SHAPE_NUM = 30;
const int VERTEX_NUM = 5;
const int GAP = 100;

void drawShape( int cx, int cy, int gap ) {
	beginShape( );
	for ( int i = 0; i < VERTEX_NUM; i++ ) {
		double ang = PI2 * i / VERTEX_NUM;
		double x = cx + cos( ang ) * gap;
		double y = cy + sin( ang ) * gap;
		vertex( x, y );
	}
	endShape( CLOSE );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( 255 );

	int base_gap = GAP;

	for ( int i = 0; i < SHAPE_NUM; i++ ) {
		for ( int j = 0; j < VERTEX_NUM; j++ ) {
			double ang = PI2 * j / VERTEX_NUM;
			double x = CENTER_X + cos( ang ) * base_gap;
			double y = CENTER_Y + sin( ang ) * base_gap;
			drawShape( x, y, base_gap );
		}
		base_gap += GAP;
	}
}


