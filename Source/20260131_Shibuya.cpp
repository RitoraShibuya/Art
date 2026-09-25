#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BASE_SPAWN_NUM = 3;
const int SPAWN_NUM = 5;
const int BASE_GAP = 350;
const int GAP = 100;
const int DIA = 50;
const double ANG_SPD = PI2 * 1 / 100;
const double NOISE_RANGE = 0.05;

double _base_ang = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	noFill( );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );
	double n1 = _base_ang * NOISE_RANGE;
	Vector2 center( CENTER_X, CENTER_Y );
	for ( int i = 0; i < BASE_SPAWN_NUM; i++ ) {
		double ang = PI2 * i / BASE_SPAWN_NUM + _base_ang;
		Vector2 base = center + Vector2( BASE_GAP, 0 ).rotate( ang );
		double n2 = ang * NOISE_RANGE;

		for ( int j = 0; j < SPAWN_NUM; j++ ) {
			double ang2 = PI2 * j / SPAWN_NUM;
			Vector2 pos = base + Vector2( GAP, 0 ).rotate( ang2 );
			double n3 = ang2 * NOISE_RANGE;
			double col_h = noise( n1, n2, n3 ) * MAX_H;
			stroke( col_h, MAX_S, MAX_B );
			rect( pos.x, pos.y, DIA, DIA );
		}
	}
	_base_ang += ANG_SPD;
}


