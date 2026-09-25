#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int MAX_H = 360;
const int COLOR_S = 100;
const int COLOR_B = 100;

const int DUST_ALPHA = 50;
const int DUST_NUM = 30;
const int DUST_SPD = 10;
const int DUST_LIFE = 180;
const int MIN_DIA = 10;
const int MAX_DIA = 200;

struct Dust {
	Vector2 pos = { 0,0 };
	Vector2 vec = { 0,0 };
	int life = DUST_LIFE;
	int dia = MAX_DIA;
	int hue = 0;
	double ang = 0;
};

std::list<Dust> _dustes;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, COLOR_S, COLOR_B );
	noStroke( );
}

void draw( ) {

	std::list<Dust>::iterator it = _dustes.begin( );
	while ( it != _dustes.end( ) ) {
		Dust& dust = *it;
		dust.pos += dust.vec;

		fill( dust.hue, COLOR_S, COLOR_B , DUST_ALPHA);
		rotate( dust.ang );
		rect( dust.pos.x, dust.pos.y, dust.dia, dust.dia );
		rotate( -dust.ang );

		if ( dust.life < 0 ) {
			it = _dustes.erase( it );
		} else {
			dust.life--;
			dust.dia = dust.dia * dust.life / DUST_LIFE;
			it++;
		}
	}

}

void mouseDragged( ) {
	for ( int i = 0; i < DUST_NUM; i++ ) {
		Dust d;
		d.pos = Vector2( getMouseX( ), getMouseY( ) );
		d.ang = PI2 * i / DUST_NUM;
		d.vec = Vector2( DUST_SPD, 0 ).rotate( d.ang );
		d.dia = (int)random( MIN_DIA, MAX_DIA );
		d.hue = ( int )random( MAX_H );
		_dustes.push_back( d );
	}
}
