#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int SHAPE1_GRAY = 255;
const int SHAPE2_GRAY = 0;
const int SHAPE3_GRAY = 255;
const int SPAWN_NUM = 1000;
const int MAX_SHAPE1_GAP = 800;
const int MAX_SHAPE2_GAP = 600;
const int MAX_SHAPE3_GAP = 400;
const double NOISE_RANGE = 0.01;

int _frame_count = 0;

void drawShape1( ) {
	stroke( SHAPE1_GRAY );
	beginShape( );
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double ang = PI2 * i / SPAWN_NUM;
		double n1 = ang * NOISE_RANGE;
		double n2 = i * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double gap = noise( n1, n2, n3 ) * MAX_SHAPE1_GAP;
		double x = CENTER_X + cos( ang ) * gap;
		double y = CENTER_Y + sin( ang ) * gap;

		vertex( x, y );
	}
	endShape( CLOSE );
}

void drawShape2( ) {
	stroke( SHAPE2_GRAY );
	beginShape( );
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double ang = PI2 * i / SPAWN_NUM;
		double n1 = i * NOISE_RANGE;
		double n2 = ang * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double gap = noise( n1, n2, n3 ) * MAX_SHAPE2_GAP;
		double x = CENTER_X + cos( ang ) * gap;
		double y = CENTER_Y + sin( ang ) * gap;

		vertex( x, y );
	}
	endShape( CLOSE );
}

void drawShape3( ) {
	stroke( SHAPE3_GRAY );
	beginShape( );
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double ang = PI2 * i / SPAWN_NUM;
		double n1 = _frame_count * NOISE_RANGE;
		double n2 = ang * NOISE_RANGE;
		double n3 = i * NOISE_RANGE;
		double gap = noise( n1, n2, n3 ) * MAX_SHAPE3_GAP;
		double x = CENTER_X + cos( ang ) * gap;
		double y = CENTER_Y + sin( ang ) * gap;

		vertex( x, y );
	}
	endShape( CLOSE );
}


void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	drawShape1( );
	drawShape2( );
	drawShape3( );

	_frame_count++;
}


