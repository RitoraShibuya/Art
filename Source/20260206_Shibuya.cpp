#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 30;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;

const int LIGHT_ALPHA = 50;
const int LIGHT_SPD = 5;
const int LIGHT_DIA = 500;
const int LIGHT_RADIUS = LIGHT_DIA / 2;
const int LINE_NUM = 10;
const int LINE_WEIGHT = 10;
const double NOISE_RANGE = 0.005;

struct Light {
	Vector2 pos;
	Vector2 vec;
	Vector2 origin;
	double col_h = 0;
};

std::vector<Light> _lights;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	strokeWeight( LINE_WEIGHT );

	for ( int i = 0; i < 4; i++ ) {
		Light l;
		switch ( i ) {
		case 0:
			l.pos = Vector2( 0, 0 );
			break;
		case 1:
			l.pos = Vector2( WIDTH, 0 );
			break;
		case 2:
			l.pos = Vector2( 0, HEIGHT );
			break;
		case 3:
			l.pos = Vector2( WIDTH, HEIGHT );
			break;
		}
		l.vec = Vector2( LIGHT_SPD, 0 ).rotate( random( PI2 ) );
		l.origin = l.pos;
		l.col_h = random( MAX_H );
		_lights.push_back( l );
	}
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );
	for ( Light& light : _lights ) {
		light.pos += light.vec;
		if ( light.pos.x > WIDTH + LIGHT_RADIUS ||
			 light.pos.x < -LIGHT_RADIUS ) {
			light.vec.x *= -1;
		}
		if ( light.pos.y > HEIGHT + LIGHT_RADIUS ||
			 light.pos.y < -LIGHT_RADIUS ) {
			light.vec.y *= -1;
		}

		double n1 = light.col_h * NOISE_RANGE;
		double n2 = light.pos.x * NOISE_RANGE;
		double n3 = light.pos.y * NOISE_RANGE;
		double noise_h = noise( n1, n2, n3 ) * MAX_H;
		fill( noise_h, MAX_S, MAX_B, LIGHT_ALPHA );
		stroke( noise_h, MAX_S, MAX_B, LIGHT_ALPHA );
		light.col_h = noise_h;

		ellipse( light.pos.x, light.pos.y, LIGHT_DIA );
		for ( int i = 0; i < LINE_NUM; i++ ) {
			double ang = PI2 * i / LINE_NUM;
			Vector2 pos = light.pos + Vector2( LIGHT_RADIUS, 0 ).rotate( ang );
			line( light.origin, pos );
		}
	}
}


