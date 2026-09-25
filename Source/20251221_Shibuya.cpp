#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int BACKGROUND = 0;

const int COLOR_R = 255;
const int MAX_G = 255;
const int MAX_B = 255;
const int GAP = 10;
const int NUM_X = WIDTH / GAP;
const int NUM_Y = HEIGHT / GAP;
const double NOISE_RANGE = 0.03;
const int MAX_INTERVAL = 360;
const int MIN_INTERVAL = 30;
const int MIN_RANGE = 2;
const int MAX_RANGE = 20;
const int DURATION_ADD_SPD = 1;
const int DURATION_SUB_SPD = -3;
const int RANGE_ADD_SPD = 2;
const int RANGE_SUB_SPD = -1;
const int RANGE_CHECK_FRAME = 10;

int _frame_count = 0;

struct Param {
	int dur = MAX_INTERVAL;
	int range = MIN_RANGE;
};

Param _param;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {

	for ( int i = 0; i < NUM_X; i++ ) {
		for ( int j = 0; j < NUM_Y; j++ ) {
			Vector2 pos( GAP / 2 + i * GAP, GAP / 2 + j * GAP );
			double nx = pos.x * NOISE_RANGE;
			double ny = pos.y * NOISE_RANGE;
			double nf = ( _frame_count % _param.dur ) * NOISE_RANGE;
			double n_range_ratio = noise( nx, ny, nf );
			Vector2 add_n = Vector2( ( n_range_ratio - 0.5 ) * _param.range * GAP, 0 );
			pos += add_n;

			int g = ( int )map( n_range_ratio, 0, 1, MAX_G, 0 );
			int b = ( int )map( n_range_ratio, 0, 1, MAX_B, 0 );
			fill( COLOR_R, g, b );

			ellipse( pos.x, pos.y, GAP );
		}
	}

	if ( _param.dur < MAX_INTERVAL ) {
		_param.dur += DURATION_ADD_SPD;
	}

	if ( _frame_count % RANGE_CHECK_FRAME == 0 && 
		 _param.range > MIN_RANGE ) {
		_param.range += RANGE_SUB_SPD;
	}

	_frame_count++;

}

void mouseDragged( ) {
	if ( _param.dur > MIN_INTERVAL ) {
		_param.dur += DURATION_SUB_SPD;
	}
}

void mouseClicked( ) {
	if ( _param.range < MAX_RANGE ) {
		_param.range += RANGE_ADD_SPD;
	}
}