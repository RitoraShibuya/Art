#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int SHAPE_COLOR_R = 255;
const int SHAPE_COLOR_G = 0;
const int SHAPE_COLOR_B = 0;
const int SHAPE_ALPHA = 5;
const int SHAPE_WEIGHT = 15;
const int SHAPE_NUM = 1500;
const int MIN_VERTEX_NUM = 3;
const int MAX_VERTEX_NUM = 10;
const int MIN_WIDTH_CENTER = 250;
const int MAX_WIDTH_CENTER = 750;
const int MIN_HEIGHT_CENTER = 250;
const int MAX_HEIGHT_CENTER = 750;
const int GAP = 300;
const double ANG_MAG = 2.5;

void drawShape( ) {
	int cx = ( int )random( MIN_WIDTH_CENTER, MAX_WIDTH_CENTER );
	int cy = ( int )random( MIN_HEIGHT_CENTER, MAX_HEIGHT_CENTER );
	int ver_num = ( int )random( MIN_VERTEX_NUM, MAX_VERTEX_NUM );
	double ang_range = ( PI / ver_num ) * ANG_MAG;
	double base_ang = 0;
	beginShape( );
	for ( int i = 0; i < ver_num; i++ ) {
		double ang = base_ang + random( ang_range );
		double x = cx + cos( ang ) * GAP;
		double y = cy + sin( ang ) * GAP;
		vertex( x, y );

		base_ang = ang;
	}
	endShape( CLOSE );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( SHAPE_COLOR_R, SHAPE_COLOR_G, SHAPE_COLOR_B, SHAPE_ALPHA );
	strokeWeight( SHAPE_WEIGHT );

	for ( int i = 0; i < SHAPE_NUM; i++ ) {
		drawShape( );
	}
}
