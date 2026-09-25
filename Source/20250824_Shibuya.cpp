#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int P_NUM = 5;
const int P_SIZE = 50;
const int MIN_GAP = 30;

struct Pendulum {
	double x, y, center_x, center_y;
	int num, ang, gap;

	void Setup( int set_num, int set_gap ) {
		gap = set_gap;
		num = set_num;
	}

	void Draw( double c_x, double c_y ) {
		center_x = c_x;
		center_y = c_y;
		x = center_x + sin( radians( ang ) ) * gap;
		y = center_y + cos( radians( ang ) ) * gap;

		stroke( noise( x * 0.05, y * 0.05 ) * 255, noise( x + 100 * 0.05, y * 0.05 ) * 255, noise( x * 0.05, y + 100 * 0.05 ) * 255 );
		point( x, y );

		if (num % 2)
		{
			ang -= num + 1;
		}
		else
		{
			ang += num + 1;
		}

	}

};

Pendulum Ellipses[ P_NUM ];

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOLOR );
	for (int i = 0; i < P_NUM; i++)
	{
		Ellipses[ i ].Setup( i, MIN_GAP * ( i + 1 ) );
	}
}

void draw( ) {
	background( BACKCOLOR, 2 );
	int old_x = CENTER_X;
	int old_y = CENTER_Y;

	for (int i = 0; i < P_NUM; i++)
	{
		Ellipses[ i ].Draw( old_x, old_y );
		old_x = Ellipses[ i ].x;
		old_y = Ellipses[ i ].y;
	}
}


