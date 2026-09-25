#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 5;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;

const int CIRCLE_GRAY = 255;
const int CIRCLE_WEIGHT = 10;
const int CIRCLE_DIA = 1000;
const int LINE_GRAY = 255;
const int LINE_ALPHA = 10;
const int LINE_WEIGHT = 5;

int clamp( int n, int min, int max ) {
	if ( n < min ) {
		n = min;
	} else if ( n > max ) {
		n = max;
	}
	return n;
}

void drawCircle( ) {
	noFill( );
	strokeWeight( CIRCLE_WEIGHT );
	stroke( CIRCLE_GRAY );
	ellipse( CENTER_X, CENTER_Y, CIRCLE_DIA );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	drawCircle( );
}

void mouseDragged( ) {
	Vector2 center { CENTER_X,CENTER_Y };
	Vector2 m_pos { ( double )getMouseX( ),( double )getMouseY( ) };
	strokeWeight( LINE_WEIGHT );
	stroke( LINE_GRAY, LINE_ALPHA );
	line( center.x, center.y, m_pos.x, m_pos.y );
};


