#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 125;

const int RANDOM_SECTION = 2;
const int COLOR_BLACK = 0;
const int COLOR_WHITE = 255;
const int TACTILE_ALPHA = 5;
const int TACTILE_LIFE = 180;
const int TACTILE_COUNT = 60;
const double TACTILE_SPD = 1.0;
const double ANG_RANGE = 1.5;
const int MIN_DIA = 30;
const int MAX_DIA = 100;
const int EFFECT_COUNT = 6;
const double EFFECT_RANGE = 50.0;

enum class COLOR {
	BLACK,
	WHITE,
};

struct Tactile {
	Vector2 pos = { 0,0 };
	Vector2 vec = { 0,0 };
	int dia = MIN_DIA;
	int life = TACTILE_LIFE;
	COLOR col = COLOR::WHITE;
};

std::list<Tactile> _tactiles;

void createTactile( int num, const Vector2& center ) {
	for ( int i = 0; i < TACTILE_COUNT; i++ ) {
		Tactile t;
		t.pos = center;
		double ang = PI2 * i / TACTILE_COUNT;
		double rand_ang = random( -ANG_RANGE, ANG_RANGE ) * PI2;
		ang += rand_ang;
		t.vec = Vector2( TACTILE_SPD, 0.0 ).rotate( ang );
		t.dia = random( MIN_DIA, MAX_DIA );
		if ( num % RANDOM_SECTION == 0 ) {
			t.col = COLOR::BLACK;
		}
		_tactiles.push_back( t );
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
}

void draw( ) {

	std::list<Tactile>::iterator it = _tactiles.begin( );
	while ( it != _tactiles.end( ) ) {
		Tactile& tactile = *it;
		switch ( tactile.col ) {
		case COLOR::BLACK:
			fill( COLOR_BLACK, TACTILE_ALPHA );
			break;
		case COLOR::WHITE:
			fill( COLOR_WHITE, TACTILE_ALPHA );
			break;
		}
		ellipse( tactile.pos.x, tactile.pos.y, tactile.dia, tactile.dia );
		tactile.pos += tactile.vec;
		tactile.life--;

		if ( tactile.life < 0 ) {
			it = _tactiles.erase( it );
		} else {
			it++;
		}
	}

}

void mouseClicked( ) {
	Vector2 cen_pos( getMouseX( ), getMouseY( ) );
	for ( int i = 0; i < EFFECT_COUNT; i++ ) {
		Vector2 rand_pos( random( -EFFECT_RANGE, EFFECT_RANGE ),
						  random( -EFFECT_RANGE, EFFECT_RANGE ) );
		cen_pos += rand_pos;
		createTactile( i, cen_pos );
	}
}
