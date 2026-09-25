#include "Processing.h"
#include <cmath>

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int MAX_A = 255;
const int BACK_H = 330;
const double COLOR_SCALE = 0.05;
const double FRAME_SCALE = 50.0;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
}

void draw( ) {
	background( BACK_H, MAX_S, MAX_B );
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double mul = _frame_count * FRAME_SCALE + i * j + i * j * COLOR_SCALE;
			double h = std::fmod( mul, MAX_H );
			double alpha = std::fmod( mul, MAX_A );
			stroke( h, MAX_S, MAX_B, alpha );
			point( i, j );
		}
	}
	_frame_count++;
}


