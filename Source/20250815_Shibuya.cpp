#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int R_SIZE = 100;
const int FRAMERATE = 60;
const int ROTATEWAITFRAME = 2;
const double SIZESPD = R_SIZE / FRAMERATE;

int _framecount, _rotatecount;
double _ang;
bool _rotateswitch;

struct FLOWERS {
	int x, y, center, _size, _sizeadd;
	double ang;

	void Setup( int sx, int sy ) {
		rectMode( CENTER );
		_size = R_SIZE;
		center = _size / 2;
		x = sx;
		y = sy;
		_sizeadd = 0;
	}

	void Draw( ) {
		_size += _sizeadd;
		rect( x + center, y + center, _size, _size );
		ang += PI * 1 / 1000;
	}

	void Update( ) {
		switch ( ( int )random( 2 ) )
		{
		case 0:
			_sizeadd = _size <= R_SIZE ? SIZESPD : -SIZESPD ;
			break;
		case 1:
			_sizeadd = 0;
			break;
		}
	}
};

std::vector<FLOWERS> rects;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOLOR );
	noFill( );
	stroke( 255 );
	strokeWeight( 10 );

	_ang = 0;
	_rotatecount = 0;
	_framecount = 0;
	_rotateswitch = false;

	for ( int i = 0; i < WIDTH / R_SIZE; i++ )
	{
		for ( int c = 0; c < HEIGHT / R_SIZE; c++ )
		{
			FLOWERS re;
			re.Setup( i * R_SIZE, c * R_SIZE );
			rects.push_back( re );
		}

	}
}

void draw( ) {
	background( BACKCOLOR );
	rotate( _ang );
	for ( auto& re : rects ) {
		re.Draw( );
	}
	if ( _framecount % ( FRAMERATE * ROTATEWAITFRAME ) == 0 )
	{
		_rotateswitch = true;
		for ( auto& re : rects ) {
			re.Update( );
		}
	}
	if ( _rotateswitch )
	{
		_ang += PI * 1 / FRAMERATE;

		_rotatecount++;
		if ( _rotatecount >= FRAMERATE )
		{
			_rotatecount = 0;
			_rotateswitch = false;
		}
	}

	_framecount++;
}


