#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GAP = 150;
const int B_NUM = 5;

class Bug {
public:
	int x, y, x2, y2, x3, y3;
	int ang;
	int r, g, b;
	int dia, dia2;
	int spd;
	int gap;
public:
	void Setup(int ox, int oy) {
		x = ox;
		y = oy;
		x2 = x;
		y2 = y;
		x3 = x;
		y3 = y;
		ang = 0;
		r = 0;
		g = 0;
		b = 255;
		dia = 100;
		dia2 = 50;
		spd = 2;
		gap = 150;
	};
	void Draw( ) {
		stroke(255, 80);
		strokeWeight(20);
		line(x, y, x2, y2);
		line(x, y, x3, y3);
		fill(r, g, b);
		noStroke( );
		ellipse(x, y, dia);
		ellipse(x2, y2, dia2);
		ellipse(x3, y3, dia2);
	};
	void Update( ) {
		if (x > WIDTH + dia) x -= WIDTH;
		if (x < 0 - dia) x += WIDTH;
		if (y > HEIGHT + dia) y -= HEIGHT;
		if (y < 0 - dia) y += HEIGHT;
		x += cos(radians(ang)) * spd;
		y += sin(radians(ang)) * spd;
		x2 = x + cos(radians(ang + 90)) * gap;
		y2 = y + sin(radians(ang + 90)) * gap;
		x3 = x + cos(radians(ang + 270)) * gap;
		y3 = y + sin(radians(ang + 270)) * gap;
		ang = ( ( noise(x * 0.01, y * 0.01) ) - 0.5 ) * 720;

	};
};

Bug b_es[ B_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	int nx = 500;
	int ny = 500;
	for (int i = 0; i < B_NUM; i++)
	{
		b_es[ i ].Setup(nx, ny);
		nx = b_es[ i ].x + cos(radians(b_es[ i ].ang + 180)) * GAP;
		ny = b_es[ i ].y + sin(radians(b_es[ i ].ang + 180)) * GAP;
	}
}

void draw( ) {
	background(BACKCOL);
	int nx;
	int ny;
	int oldx = b_es[ 0 ].x;
	int oldy = b_es[ 0 ].y;
	for (int i = 0; i < B_NUM; i++)
	{
		b_es[ i ].Update( );
		stroke(255, 80);
		line(oldx, oldy, b_es[ i ].x, b_es[ i ].y);
		b_es[ i ].Draw( );
		oldx = b_es[ i ].x;
		oldy = b_es[ i ].y;

	}
}


