#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;

const int SUN_H = 40;
const int SUN_LIGHT_H = 180;
const int SUN_LIGHT_B = 0;
const int SUN_DIA = 300;

const int MOUNTAIN_H = 250;
const int MOUNTAIN_B = 60;
const int MOUNTAIN_HEIGHT = 300;
const int MOUNTAIN_SPD = 2;

struct Mountain {
	Vector2 left_top_pos { MOUNTAIN_HEIGHT, -MOUNTAIN_HEIGHT };
	Vector2 left_left_pos { 0,0 };
	Vector2 left_center_pos { MOUNTAIN_HEIGHT,0 };
	Vector2 center_pos { MOUNTAIN_HEIGHT,-MOUNTAIN_HEIGHT };
	Vector2 right_top_pos { WIDTH - MOUNTAIN_HEIGHT, -MOUNTAIN_HEIGHT };
	Vector2 right_right_pos { WIDTH,0 };
	Vector2 right_center_pos { WIDTH - MOUNTAIN_HEIGHT,0 };
	Vector2 spd { 0,MOUNTAIN_SPD };
};

struct Sun {
	Vector2 pos { WIDTH / 2,HEIGHT / 2 };
	int light_h = SUN_LIGHT_H;
	int light_s = MAX_S;
	int light_b = SUN_LIGHT_B;
};

Mountain _mount;
Sun _sun;

void updateMountain( ) {
	if ( _mount.left_left_pos.y < HEIGHT ) {
		_mount.left_top_pos += _mount.spd;
		_mount.left_left_pos += _mount.spd;
		_mount.left_center_pos += _mount.spd;
		_mount.center_pos += _mount.spd;
		_mount.right_top_pos += _mount.spd;
		_mount.right_right_pos += _mount.spd;
		_mount.right_center_pos += _mount.spd;
	}
}

void drawSun( ) {
	fill( SUN_H, MAX_S, MAX_B );
	ellipse( _sun.pos.x, _sun.pos.y, SUN_DIA );
};

void drawMountain( ) {
	fill( MOUNTAIN_H, MAX_S, MOUNTAIN_B );
	triangle( _mount.left_top_pos, _mount.left_left_pos, _mount.left_center_pos );
	rect( _mount.center_pos.x, _mount.center_pos.y, WIDTH - ( MOUNTAIN_HEIGHT * 2 ), MOUNTAIN_HEIGHT );
	triangle( _mount.right_top_pos, _mount.right_right_pos, _mount.right_center_pos );
	rect( _mount.left_left_pos.x, _mount.left_left_pos.y, WIDTH, HEIGHT );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	noStroke( );
}

void draw( ) {
	int light_b = ( int )map( _mount.left_left_pos.y, 0, HEIGHT, 0, MAX_B );
	background( _sun.light_h, _sun.light_s, light_b );

	updateMountain( );
	drawSun( );
	drawMountain( );
}


