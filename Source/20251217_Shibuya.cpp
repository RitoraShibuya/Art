#include "Processing.h"
#include "smart_ptr.h"

//
// parameter
//

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 20;
const int COLOR_MAX_H = 360;
const int COLOR_S = 100;
const int COLOR_B = 100;

const Vector2 PET_AREA = { 300,300 };
//const double PET_AREA_X = 300;
//const double PET_AREA_Y = 300;
const Vector2 PET_CENTER_GAP = { PET_AREA.x / 2,PET_AREA.y / 2 };
const int PET_ALPHA = 200;
const double PET_SPD = 0.01;
const double CHAOS_INIT_MIN = 0.5;
const double CHAOS_INIT_MAX = 0.501;
const double CHAOS_NUM = 3.9;

//
// Pet Class
//

class Pet {
public:
	Pet( );
	virtual ~Pet( );
	void update( );
	void draw( );
private:
	Vector2 _pos = { 0,0 };
	int _h = random( COLOR_MAX_H );
};

Pet::Pet( ) {
	int mx = getMouseX( );
	_pos = Vector2( mx, 0 );
}

Pet::~Pet( ) {
}

//
// member
//
PTR( Pet );
std::list<PetPtr> _pets;

//
// Pet Method
//

void Pet::update( ) {
	int mx = getMouseX( );
	int my = getMouseY( );
	Vector2 add_vec = Vector2( mx, my ) - _pos;
	_pos += add_vec * PET_SPD;
}

void Pet::draw( ) {
	stroke( _h, COLOR_S, COLOR_B ,PET_ALPHA);

	double chaos_x = map( _pos.x, 0, WIDTH, CHAOS_INIT_MIN, CHAOS_INIT_MAX );

	for ( int i = 0; i < PET_AREA.y; ++i ) {
		chaos_x = CHAOS_NUM * chaos_x * ( 1.0 - chaos_x );
		double x = _pos.x - PET_CENTER_GAP.x + chaos_x * PET_AREA.x;
		double y = _pos.y - PET_CENTER_GAP.y + i;

		point( x, y );
	}
}

//
// Main
//


void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, COLOR_MAX_H, COLOR_S, COLOR_B );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	std::list<PetPtr>::iterator it = _pets.begin( );
	while ( it != _pets.end( ) ) {
		PetPtr pet = *it;
		pet->update( );
		pet->draw( );
		it++;
	}
}

void mouseClicked( ) {
	_pets.push_back( PetPtr( new Pet ) );
}
