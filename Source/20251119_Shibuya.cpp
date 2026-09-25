#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int ALPHA = 20;

const int MAX_DIA = 800;
const int MIN_DIA = 50;
const int DIA_SPD = 5;

const double SPD_DOWN = 0.01;

struct ColRect {
	int dia = MAX_DIA;
	int gray = 0;
	int ang = 0;
	double x = CENTER_X;
	double y = CENTER_Y;
	bool add_gray = true;
	bool add_dia = false;
};

ColRect _cen_r;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
}

void draw( ) {

	double mx = getMouseX( );
	double my = getMouseY( );
	double gap_x = mx - _cen_r.x;
	double gap_y = my - _cen_r.y;

	_cen_r.x += gap_x * SPD_DOWN;
	_cen_r.y += gap_y * SPD_DOWN;
	_cen_r.ang++;

	if ( _cen_r.add_gray ) {
		_cen_r.gray++;
	} else {
		_cen_r.gray--;
	}
	if ( _cen_r.gray >= 255 || _cen_r.gray <= 0 ) {
		_cen_r.add_gray = !_cen_r.gray;
	}

	if ( _cen_r.add_dia ) {
		_cen_r.dia += DIA_SPD;
	} else {
		_cen_r.dia -= DIA_SPD;
	}
	if ( _cen_r.dia >= MAX_DIA || _cen_r.dia <= MIN_DIA ) {
		_cen_r.add_dia = !_cen_r.add_dia;
	}

	fill( _cen_r.gray, ALPHA );

	double rad = radians( _cen_r.ang );
	rotate( rad );
	rect( _cen_r.x, _cen_r.y, _cen_r.dia, _cen_r.dia );
	rotate( -rad );

}


