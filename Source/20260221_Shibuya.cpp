#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;

const int SPANW_NUM = 100;
const int VERTEX_NUM = 4;
const int GAP = 300;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	strokeWeight( 25 );

	for ( int i = 0; i < SPANW_NUM; i++ ) {
		double col_r = random( 255 );
		double col_g = random( 255 );
		double col_b = random( 255 );
		stroke( col_r, col_g, col_b, 10 );
		beginShape( );
		double base_ang = random( PI2 );
		for ( int j = 0; j < VERTEX_NUM; j++ ) {
			double ang = base_ang + PI * j / VERTEX_NUM;
			double x = CENTER_X + cos( ang ) * GAP;
			double y = CENTER_Y + sin( ang ) * GAP;
			vertex( x, y );
		}
		endShape( CLOSE );
	}
}

void draw( ) {

}


