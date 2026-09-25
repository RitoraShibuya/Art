#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int CAGE_GRAY = 255;
const int CAGE_ALPHA = 10;
const int SPAWN_NUM = 10;
const int MIN_DIA = 10;
const int MAX_DIA = 300;
const int DIA_SPD = 3;
const int CAGE_SPD = 1;

class Cage {
public:
	void init( );
	void update( );
	Vector2 getPos1( );
	Vector2 getPos2( );

private:
	Vector2 _pos1;
	Vector2 _pos2;
	Vector2 _vec;
	int _dia = MIN_DIA;
	int _step = 1;
};

std::vector<Cage> _cages;

void Cage::init( ) {
	int dia = ( int )random( MIN_DIA, MAX_DIA );
	int radius = dia / 2;

	int x = ( int )random( WIDTH );
	int y = ( int )random( HEIGHT );
	_pos1 = Vector2( x, y );
	_pos2 = Vector2( x + dia, y + dia );
	_vec = Vector2( CAGE_SPD, 0 ).rotate( random( PI2 ) );
}

void Cage::update( ) {
	if ( _dia > MAX_DIA ) {
		_dia = MAX_DIA;
		_step = -1;
	} else if ( _dia < MIN_DIA ) {
		_dia = MIN_DIA;
		_step = 1;
	}

	_dia += _step * DIA_SPD;
	_pos2 = _pos1 + Vector2( _dia, _dia );

	if ( _pos2.x < 0 || _pos1.x > WIDTH ||
		 _pos2.y < 0 || _pos1.y > HEIGHT ) {
		init( );
	}

	_pos1 += _vec;
}

Vector2 Cage::getPos1( ) {
	return _pos1;
}

Vector2 Cage::getPos2( ) {
	return _pos2;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( CAGE_GRAY, CAGE_ALPHA );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Cage c;
		c.init( );
		_cages.push_back( c );
	}
}

void draw( ) {
	beginShape( );
	for ( Cage& cage : _cages ) {
		cage.update( );
		vertex( cage.getPos1( ).x, cage.getPos1( ).y );
		vertex( cage.getPos2( ).x, cage.getPos1( ).y );
		vertex( cage.getPos2( ).x, cage.getPos2( ).y );
		vertex( cage.getPos1( ).x, cage.getPos2( ).y );
	}
	Vector2 old_pos = _cages.front( ).getPos1( );
	vertex( old_pos.x, old_pos.y );
	endShape( CLOSE );
}

