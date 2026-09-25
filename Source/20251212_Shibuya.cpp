#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 255;
const int OUT_DISPLAY = 1500;

const int EARTH_DIA_GAP = 500;
const double EARTH_SPD = 0.05;

const int MOON_GRAY = 0;
const int MOON_ALPHA = 10;
const int MOON_DIA = 50;
const double MOON_DIA_GAP = 0.2;
const double MOON_SPD = 0.0001;

const Vector2 SUN { CENTER_X, CENTER_Y };

struct Star {
	Vector2 pos { CENTER_X, CENTER_Y };
	double dia = 0;
	double ang = 0;
};

Star _earth;
Star _moon;

void updateEarth( ) {
	Vector2 mouse_vec( getMouseX( ), getMouseY( ) );
	Vector2 dist_vec = mouse_vec - _earth.pos;
	double dist = sqrt( dist_vec.x * dist_vec.x + dist_vec.y * dist_vec.y );
	_earth.dia = map( dist, 0, OUT_DISPLAY, 0, EARTH_DIA_GAP );

	Vector2 add_vec( 1, 0 );
	add_vec = add_vec.rotate( _earth.ang );
	_earth.pos = SUN + ( add_vec * _earth.dia );

	_earth.ang += EARTH_SPD;
}

void updateMoon( ) {
	Vector2 mouse_vec( getMouseX( ), getMouseY( ) );
	Vector2 dist_vec = mouse_vec - _moon.pos;
	double dist = dist_vec.getLength( );
	_moon.dia = dist * MOON_DIA_GAP;

	Vector2 add_vec = Vector2( _moon.dia, 0 ).rotate( _moon.ang );
	_moon.pos = _earth.pos + add_vec;

	double spd = dist * MOON_SPD;
	_moon.ang -= spd;

	ellipse( _moon.pos.x, _moon.pos.y, MOON_DIA );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
	fill( MOON_GRAY,MOON_ALPHA );
}

void draw( ) {

	updateEarth( );
	updateMoon( );
}