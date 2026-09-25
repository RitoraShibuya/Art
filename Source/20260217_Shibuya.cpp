#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 1;

const int STROKE_GRAY = 255;
const int STROKE_ALPHA = 10;
const int STROKE_WEIGHT = 3;
const double ANG_RANGE = PI2 * 1 / 200;

struct Giar {
	Vector2 pos;
	double ang_spd = 0;
};

std::vector<Giar> _giars;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	stroke( STROKE_GRAY, STROKE_ALPHA );
	strokeWeight( STROKE_WEIGHT );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	Vector2 center( CENTER_X, CENTER_Y );
	Vector2 old = center;
	for ( Giar& giar : _giars ) {
		giar.pos = giar.pos.rotate( giar.ang_spd );
		Vector2 pos = center + giar.pos;

		line( old, pos );

		old = pos;
	}
}

void mouseClicked( ) {
	Vector2 center( CENTER_X, CENTER_Y );
	Giar g;
	g.pos = Vector2( getMouseX( ), getMouseY( ) ) - center;
	g.ang_spd = random( -ANG_RANGE, ANG_RANGE );
	_giars.push_back( g );
}

