#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int MAX_H = 360;
const int COLOR_S = 100;
const int COLOR_B = 100;
const int WAVE_ALPHA = 50;
const int WAVE_HEIGHT = 10;
const int WAVE_MIN_WIDTH = 50;
const int WAVE_MAX_WIDTH = 300;

struct Wave {
	Vector2 pos;
	int width = 0;
};

std::list<Wave> _waves;

void createWave( ) {
	Vector2 pos;
	Vector2 end_pos( WIDTH, HEIGHT );
	while ( pos.y < end_pos.y ) {
		Wave w;
		w.pos = pos;
		w.width = ( int )random( WAVE_MIN_WIDTH, WAVE_MAX_WIDTH );
		_waves.push_back( w );
		pos.x += w.width;
		if ( pos.x > WIDTH ) {
			pos.x = 0;
			pos.y += WAVE_HEIGHT;
		}
	}
}

void drawWave( ) {
	std::list<Wave>::iterator it = _waves.begin( );
	while ( it != _waves.end( ) ) {
		Wave& wave = *it;
		fill( random( MAX_H ), COLOR_S, COLOR_B, WAVE_ALPHA );
		rect( wave.pos.x, wave.pos.y, wave.width, WAVE_HEIGHT );

		it++;
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, COLOR_S, COLOR_B );
	noStroke( );

	createWave( );

	drawWave( );
}


void mouseClicked( ) {
	createWave( );

	drawWave( );
}
