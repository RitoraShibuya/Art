#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int BACK_COL = 0;
const int E_NUM = 3;
const int GAP = 200;
const int DIAMETER = 300;
const double SPEED = 0.01;

double g_base_ang;

struct CenterEllipse {
	int x = CX;
	int y = CY;
	double ang = 0;
};

CenterEllipse c_e;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACK_COL);
	noStroke( );
}

void draw( ) {
	background(BACK_COL,1);

	int _mx = getMouseX( );
	int _my = getMouseY( );

	c_e.x += ( _mx - c_e.x ) * SPEED;
	c_e.y += ( _my - c_e.y ) * SPEED;

	fill(100, 100, 255);
	for (int i = 0; i < E_NUM; i++)
	{
		double _ang = PI2 * i / E_NUM + g_base_ang;
		int _x = c_e.x + cos(_ang) * GAP;
		int _y = c_e.y + sin(_ang) * GAP;
		ellipse(_x, _y, DIAMETER, DIAMETER);
	}

	g_base_ang += 0.01;
}


