#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;

struct Click_P {
	int x, y;
	int fx[ 5 ];
	int fy[ 5 ];
};

std::list<Click_P>points;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	stroke(255);
}

void draw( ) {
	background(BACKCOL,1);
	for (auto it = points.begin( );it != points.end( );++it) {
		for (int i = 0; i < 5; i++)
		{
			it->fx[ i ] += cos(radians(360 * ( i   / 5.0 )));
			it->fy[ i ] += sin(radians(360 * ( i  / 5.0 )));
			point(it->fx[ i ], it->fy[ i ]);
		}

	}
}

void mouseClicked( ) {
	Click_P P;
	P.x = getMouseX( );
	P.y = getMouseY( );
	for (int i = 0; i < 5; i++)
	{
		P.fx[ i ] = P.x;
		P.fy[ i ] = P.y;
	}
	points.push_front(P);
}
