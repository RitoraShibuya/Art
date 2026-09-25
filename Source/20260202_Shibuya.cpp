#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;

const int MIN_DIA = 50;
const int MAX_DIA = 300;
const int MIN_GRAY = 0;
const int MAX_GRAY = 255;

struct Window {
	Vector2 pos;
	int dia = 0;
};

int _background = 0;
bool _overlapping = false;
std::vector<Window> _windows;


void spawnWindow( ) {
	Window w;
	w.pos = Vector2( ( int )random( WIDTH ), ( int )random( HEIGHT ) );
	w.dia = ( int )random( MIN_DIA, MAX_DIA );
	_windows.push_back( w );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( _background );
	noStroke( );

	spawnWindow( );
}

void draw( ) {
	Vector2 m_pos = Vector2( getMouseX( ), getMouseY( ) );
	bool hit = false;

	for ( const Window& window : _windows ) {
		double dist = ( m_pos - window.pos ).getLength( );
		double radius = window.dia / 2;
		if ( dist < radius ) {
			hit = true;
		}
	}

	if ( !hit && _overlapping ) {
		spawnWindow( );
	}
	_overlapping = hit;

	if ( _overlapping ) {
		_background = MAX_GRAY;
	} else {
		_background = MIN_GRAY;
	}

	background( _background );
	fill( _background ^ MAX_GRAY );

	for ( const Window& window : _windows ) {
		ellipse( window.pos.x, window.pos.y, window.dia );
	}
}




