#include "Processing.h"
#include <cmath>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_R = 20;
const int BACK_G = 50;
const int BACK_B = 20;
const int SPAWN_Y = 20;
const int SPAWN_NUM = 100;
const int MAX_RGB = 255;
const int STROKE_ALPHA = 100;
const int STROKE_WEIGHT = 20;
const double MIN_SPD = 1.0;
const double MAX_SPD = 50.0;

int _frame_count = 0;
std::list<Vector2> _pos;

void spawnLine( ) {
	Vector2 p( ( int )random( WIDTH ), SPAWN_Y );
	_pos.push_back( p );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_B, BACK_G );
	strokeWeight( STROKE_WEIGHT );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		spawnLine( );
	}
}

void draw( ) {
	std::list<Vector2>::iterator it = _pos.begin( );
	while ( it != _pos.end( ) ) {
		Vector2& pos = *it;

		double col_r = std::fmod( abs( pos.x * pos.x + pos.y ), MAX_RGB );
		double col_g = std::fmod( abs( pos.y * pos.y + pos.x ), MAX_RGB );
		double col_b = std::fmod( abs( pos.x * pos.y ) * _frame_count, MAX_RGB );

		double ang = std::fmod( abs( pos.x * pos.y ), PI );
		double spd = MIN_SPD + std::fmod( pos.x * pos.y, MAX_SPD );
		Vector2 old = pos;
		pos += Vector2( spd, 0.0 ).rotate( ang );

		stroke( col_r, col_g, col_b, STROKE_ALPHA );
		line( old, pos );

		if ( pos.y > ( double )HEIGHT ) {
			it = _pos.erase( it );
			spawnLine( );
		} else {
			it++;
		}
	}
	_frame_count++;
}


