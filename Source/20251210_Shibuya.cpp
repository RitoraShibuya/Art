#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;
const int FRAME_RATE = 30;
const int POINT_GRAY = 255;
const int POINT_ALPHA = 100;
const int MAX_NUM = 10000;

const double NOISE_RANGE = 0.01;
const double ANG_SPD = 0.02;
const double DIA_GAP = 0.6;

struct Master {
	int x = CENTER_X;
	int y = CENTER_Y;
	int dia = 0;
	int old_x = CENTER_X;
	int old_y = CENTER_Y;
	double ang = 0;
};

int _frame_count = 0;

Master _master;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	setFrameRate( FRAME_RATE );
	stroke( POINT_GRAY, POINT_ALPHA );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	double base_ang = _master.ang;
	int base_dia = _master.dia;
	_master.x = CENTER_X + cos( base_ang ) * base_dia;
	_master.y = CENTER_Y + sin( base_ang ) * base_dia;
	int mx = getMouseX( );
	int my = getMouseY( );
	int dx = _master.x - mx;
	int dy = _master.y - my;
	int dist = sqrt( dx * dx + dy * dy );
	_master.dia = dist * DIA_GAP;

	for ( int i = 0; i < MAX_NUM; i++ ) {
		double ang = PI2 * i / MAX_NUM;
		double nx = _master.old_x * NOISE_RANGE;
		double ny = _master.old_y * NOISE_RANGE;
		double nf = _frame_count * NOISE_RANGE;
		double nd = noise( nx, ny, nf );
		int x = CENTER_X + cos( base_ang + ang ) * base_dia * nd;
		int y = CENTER_Y + sin( base_ang + ang ) * base_dia * nd;

		point( x, y );

		_master.old_x = x;
		_master.old_y = y;
	}

	_master.ang += ANG_SPD;
	_frame_count++;
}


