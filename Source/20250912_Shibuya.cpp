#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int L_NUM = 50;
const int R_NUM = 20;

struct Rect {
	int x, y, dia, spd;

	void Setup( ) {
		x = (int)random(WIDTH);
		y = 0;
		dia = (int)random(10, 100);
		spd = (int)random(1,10);
	}

	void Draw( ) {
		if (y > HEIGHT + dia)
		{
			Setup( );
			y = 0 - dia;
		}
		else {
			y += spd;
		}
		rect(x, y, dia, dia);
	}
};

struct Line {
	int x = 0;
	int y = 0;
	int x2 = 1000;
	int y2 = 1000;

	void Setup( ) {
		switch ((int)random(4)) {
		case 0:
			x = (int)random(WIDTH);
			x2 = (int)random(WIDTH);
			break;
		case 1:
			y = (int)random(HEIGHT);
			y2 = (int)random(HEIGHT);
			break;
		}
	}

	void Draw( ) {
		line(x, y, x2, y2);
	}
};

Rect rects[ R_NUM ];
Line lines[ L_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	for (int i = 0; i < R_NUM; i++)
	{
		rects[ i ].Setup( );
	}
	for (int i = 0; i < L_NUM; i++) {
		lines[ i ].Setup( );
	}
}

void draw( ) {
	background(BACKCOLOR);
	fill(255);
	noStroke( );
	for (int i = 0; i < R_NUM; i++)
	{
		rects[ i ].Draw( );
	}

	blendMode(MULTIPLY);
	stroke(0);
	for (int i = 0; i < L_NUM; i++) {
		lines[ i ].Draw( );
	}
	blendMode(BLEND);

}


