#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int MAX_RAD = 360;
const int MAX_LIFE = 300;
const int MAX_RGB = 400;
const int ALPHA = 50;
const int DIAMETER = 3;
const int COLOR_GAP = 200;
const int SPEED = 5;
const double NOISE_RANGE = 0.03;

int _framecount = 0;

class ColLine {
private:
	double _x = CENTER_X;
	double _y = CENTER_Y;
	double _ang = 0;
	int _life = MAX_LIFE;
	bool _isdead = false;

public:
	void setUp( double set_x, double set_y ) {
		_x = set_x;
		_y = set_y;
		_ang = radians( random( MAX_RAD ) );
	}

	void update( ) {
		if ( _life <= 0 ) {
			_isdead = true;
		} else {
			_ang = ( noise( _x * NOISE_RANGE, _y * NOISE_RANGE, _life * NOISE_RANGE ) - 0.5 ) * PI2;
			_x = _x + cos( _ang ) * SPEED;
			_y = _y + sin( _ang ) * SPEED;
			_life--;
		}
	}

	void drawLine( ) {
		double col_r = noise( _x * NOISE_RANGE, _y * NOISE_RANGE, _framecount * NOISE_RANGE ) * MAX_RGB;
		double col_g = noise( _x * NOISE_RANGE + COLOR_GAP, _y * NOISE_RANGE, _framecount * NOISE_RANGE ) * MAX_RGB;
		double col_b = noise( _x * NOISE_RANGE, _y * NOISE_RANGE + COLOR_GAP, _framecount * NOISE_RANGE ) * MAX_RGB;
		fill( col_r, col_g, col_b, ALPHA );
		ellipse( _x, _y, DIAMETER );
	}

	bool isDead( ) const {
		return _isdead;
	}
};

std::list<ColLine> _lines;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
	setFrameRate( 30 );
}

void draw( ) {

	if ( _framecount % 5 == 0 ) {
		double mx = getMouseX( );
		double my = getMouseY( );
		ColLine newC;
		newC.setUp( mx, my );
		_lines.push_back( newC );
	}

	for ( auto it = _lines.begin( ); it != _lines.end( ); ) {
		if ( it->isDead( ) ) {
			it = _lines.erase( it );
		} else {
			it->drawLine( );
			it->update( );
			++it;
		}
	}

	_framecount++;
}


