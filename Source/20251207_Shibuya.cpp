#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int POINT_R = 0;
const int POINT_G = 0;
const int POINT_B = 255;
const int MAX_DIA = 500;
const int MAX_NUM = 360;
const int WAVE_DIA_SPD = 1;

const double WAVE_ANG_SPD = 0.01;
const double NOISE_RANGE = 0.01;

class Wave {
public:
	Wave( int mx, int my );
	virtual ~Wave( );
	void draw( );
	int getDia( );

private:
	struct Point {
		Vector2 pos { CENTER_X, CENTER_Y };
		double ang = 0;
	};

private:
	Vector2 _wave_pos { CENTER_X, CENTER_Y };
	double _wave_ang = 0;
	int _wave_dia = 0;
	Point _points[ MAX_NUM ];
};

int _frame_count = 0;
std::list<Wave> _waves;

Wave::Wave( int mx, int my ) {
	_wave_pos = Vector2( mx, my );

	for ( int i = 0; i < MAX_NUM; i++ ) {
		_points[ i ].pos = _wave_pos;
		_points[ i ].ang = PI2 * i / MAX_NUM;
	}
}


Wave::~Wave( ) {
}

void Wave::draw( ) {
	for ( int i = 0; i < MAX_NUM; i++ ) {
		double n1 = _points[ i ].pos.x * NOISE_RANGE;
		double n2 = _points[ i ].pos.y * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		double p_noise = noise( n1, n2, n3 );
		double p_gap = p_noise * _wave_dia;
		double p_ang = _wave_ang + _points[ i ].ang;

		Vector2 vec( 1, 0 );
		vec = vec.rotate( p_ang );
		vec = vec * p_gap;
		_points[ i ].pos = _wave_pos + vec;

		point( _points[ i ].pos.x, _points[ i ].pos.y );
	}

	_wave_ang += WAVE_ANG_SPD;
	_wave_dia += WAVE_DIA_SPD;
}

int Wave::getDia( ) {
	return _wave_dia;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	std::list<Wave>::iterator it = _waves.begin( );
	while ( it != _waves.end( ) ) {
		stroke( POINT_R, POINT_G, POINT_B );
		it->draw( );

		if ( it->getDia( ) < MAX_DIA ) {
			it++;
		} else {
			it = _waves.erase( it );
		}
	}
	_frame_count++;
}

void mouseDragged( ) {
	int mx = getMouseX( );
	int my = getMouseY( );
	_waves.emplace_back( mx, my );
}
