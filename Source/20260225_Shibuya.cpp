#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACKGROUND = 25;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const double NOISE_SCALE = 0.01;
const double NOISE_RANGE = 0.5;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	colorMode( HSB, MAX_H, MAX_S, MAX_B );
}

void draw( ) {

	void draw( ) {
		Vector2 mouse_pos( getMouseX( ), getMouseY( ) );
		double noise_base_time = mouse_pos.getLength( ) * NOISE_SCALE + _frame_count * NOISE_SCALE;
		double noise_base_x = i * NOISE_SCALE;
		for ( int j = 0; j < WINDOW_H; j++ ) {
			double noise_base_y = j * NOISE_SCALE;
			double noise_val = noise( noise_base_time, noise_base_x, noise_base_y );
			double color_h = noise_val * COLOR_H_MAX;
			if ( noise_val > NOISE_LIMIT ) {
				stroke( color_h, COLOR_S_MAX, COLOR_B_MAX );
				point( i, j );
			}
		}
	}
	_frame_count++;
}


