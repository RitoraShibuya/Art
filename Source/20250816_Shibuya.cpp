#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int E_SIZE = 200;
const int MAX_NUM = 15;
const int E_ALPHA_MIN = 20;
const int E_ALPHA_MAX = 120;
const int E_MAX_SPD = 3;
const int GAP = 5;

struct Jellyfish {
	double mx, my, _x00, _y00, _x01, _y01, _x10, _y10, _x11, _y11, _size, _sizemax, _size_2, _size_c, r, g, b, _alpha, _addx, _addy;
	bool _alphaswitch, _sizeswitch;

	void Setup( ) {
		_size = ( int )random( E_SIZE / 2, E_SIZE );
		_sizemax = _size;
		_size_2 = _size / 4;
		_size_c = _size_2 / 2 + GAP;
		mx = getMouseX( );
		my = getMouseY( );
		_addx = ( double )( random( -E_MAX_SPD, E_MAX_SPD ) ) / 10;
		_addy = ( double )( random( -E_MAX_SPD, E_MAX_SPD ) ) / 10;
		r = 220;
		g = 220;
		b = 255;
		_alpha = E_ALPHA_MAX;
		_alphaswitch = false;
		_sizeswitch = false;
	}
	void Draw( ) {
		ellipse( mx, my, _size );
		_x00 = mx - _size_c;
		_y00 = my - _size_c;

		ellipse( _x00, _y00, _size_2 );
		_x01 = mx + _size_c;
		_y01 = my - _size_c;
		ellipse( _x01, _y01, _size_2 );
		_x10 = mx - _size_c;
		_y10 = my + _size_c;
		ellipse( _x10, _y10, _size_2 );
		_x11 = mx + _size_c;
		_y11 = my + _size_c;
		ellipse( _x11, _y11, _size_2 );

		mx += _addx;
		my += _addy;
	}
	void Update( ) {
		if ( _alphaswitch && _alpha <= E_ALPHA_MAX )
		{
			_alpha++;
		} else {
			_alphaswitch = false;
			if ( _alpha > E_ALPHA_MIN ) {
				_alpha--;
			} else
			{
				_alphaswitch = true;
			}
		}

		if ( _sizeswitch && _size <= _sizemax )
		{
			_size += 0.2;
		} else {
			_sizeswitch = false;
			if ( _size > _sizemax - 20 ) {
				_size -= 0.2;
			} else
			{
				_sizeswitch = true;
			}
		}

		stroke( r, g, b, _alpha );
		strokeWeight( 10 );
	}
};

std::vector<Jellyfish> Ellipses;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOLOR );
	noFill( );
}

void draw( ) {
	background( BACKCOLOR );
	for ( auto& e : Ellipses ) {
		e.Update( );
		e.Draw( );
	}
}

void mouseClicked( ) {
	Jellyfish e;
	e.Setup( );
	Ellipses.push_back( e );
	if ( Ellipses.size( ) > MAX_NUM )
	{
		Ellipses.erase( Ellipses.begin( ) );
	}
}


