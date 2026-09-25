#include "Processing.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int BACKALPHA = 15;
const int S_NUM = 15;
const int GAP = 30;
const double ANGADD_MIN = -0.02;
const double ANGADD_MAX = 0.02;

struct Sphere {
	int x, y, v_num, weight;
	double ang,angbase, angadd;

	void Setup( int i ) {
		x = CENTER_X;
		y = CENTER_Y;
		weight = i * GAP;
		v_num = ( ( int )random( 3, 9 ) );
		ang = 0;
		angbase = ang;
		angadd = (double)random(ANGADD_MIN,ANGADD_MAX);
	}

	void Draw( ) {
		beginShape( );
		for ( int i = 0; i < v_num; i++ )
		{
			ang = PI * 2 * i / v_num + angbase;
			vertex( x + sin( ang ) * weight, y + cos( ang ) * weight );
		}
		endShape( CLOSE );
		angbase += angadd;
	}
};

Sphere Polygons[ S_NUM ];

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOLOR );
	stroke( 255 );
	strokeWeight( 5 );

	for ( int i = 0; i < S_NUM; i++ )
	{
		Polygons[ i ].Setup( i );
	}
}

void draw( ) {
	background( BACKCOLOR, BACKALPHA );

	for ( int i = 0; i < S_NUM; i++ )
	{
		Polygons[ i ].Draw( );
	}
}


