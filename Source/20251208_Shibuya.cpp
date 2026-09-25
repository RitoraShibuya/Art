#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;

const int POINT_R = 0;
const int POINT_G = 255;
const int POINT_B = 0;
const int MAX_NUM = 360;
const int POINT_GAP = 300;
const int MAX_DIA = 300;
const int MIN_DIA = 0;
const int DIA_SPD = 1;

const double NOISE_RANGE = 0.01;

const double CENTER_SPD = 0.01;

struct Center {
	int x = CENTER_X;
	int y = CENTER_Y;
	int dia = 0;
	int dia_spd = DIA_SPD;
};

int _frame_count = 0;

Center _center;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {

	int mx = getMouseX( );
	int my = getMouseY( );

	double dx = mx - _center.x;
	double dy = my - _center.y;
	if ( _center.dia > MAX_DIA || _center.dia < MIN_DIA ) {
		_center.dia_spd = -DIA_SPD;
	}
	double nf = _frame_count * NOISE_RANGE;

	_center.x += dx * CENTER_SPD;
	_center.y += dy * CENTER_SPD;
	_center.dia += _center.dia_spd;

	stroke( POINT_R,POINT_G,POINT_B );
	for ( int i = 0; i < MAX_NUM; i++ ) {
		double ang = PI2 * i / MAX_NUM;
		double p_noise = noise( ang, nf );
		int x = _center.x + cos( ang ) * p_noise * _center.dia;
		int y = _center.y + sin( ang ) * p_noise * _center.dia;


		point( x, y );
	}

	_frame_count++;
}


