#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int MIN_DIA = 50;
const int MAX_DIA = 200;
const int SPD = 2;
const int C_NUM = 100;
const int COL_SPD = 3;

int framecount;

struct Light {
	int col_num, r, g, b;

	void Setup( ) {
		col_num = 0;
		r = 0;
		g = 0;
		b = 0;
	}

	void Update( ) {
		switch (col_num) {
		case 0:
			if (r < 255) {
				r += COL_SPD;
				if (g > 0) g -= COL_SPD;
				if (b > 0) b -= COL_SPD;
			}
			else {
				col_num++;
			}
			break;
		case 1:
			if (g < 255) {
				g += COL_SPD;
				if (r > 0) r -= COL_SPD;
				if (b > 0) b -= COL_SPD;
			}
			else {
				col_num++;
			}
			break;
		case 2:
			if (b < 255) {
				b += COL_SPD;
				if (r > 0) r -= COL_SPD;
				if (g > 0) g -= COL_SPD;
			}
			else {
				col_num++;
			}
			break;
		case 3:
			if (r < 255 || g < 255 || b < 255) {
				if (r < 255) r += COL_SPD;
				if (g < 255) g += COL_SPD;
				if (b < 255) b += COL_SPD;
			}
			else {
				col_num++;
			}
			break;
		case 4:
			if (r > 0 || g > 0 || b > 0) {
				if (r > 0) r -= COL_SPD;
				if (g > 0) g -= COL_SPD;
				if (b > 0) b -= COL_SPD;
			}
			else {
				col_num = 0;
			}
			break;
		}
	}

	void Draw( ) {
		fill(r, g, b);
		rect(getMouseX( ), getMouseY( ), 300, 300);
	}
};

struct Crack {
	int x, y, dia, r, g, b, spd, vec;

	void Setup( ) {
		x = (int)random(WIDTH);
		y = (int)random(HEIGHT);
		dia = (int)random(MIN_DIA, MAX_DIA);
		spd = (int)random(1, 5);
		vec = (int)random(4);
		r = ( (int)random(2) == 0 ? 0 : 255 );
		g = ( (int)random(2) == 0 ? 0 : 255 );
		b = ( (int)random(2) == 0 ? 0 : 255 );
	}

	void Draw( ) {
		fill(r, g, b);
		rect(x, y, dia, dia);
	}

	void Update( ) {
		if (y > HEIGHT + dia || y < 0 - dia || x > WIDTH + dia || x < 0 - dia)
		{
			Setup( );
		}
		else {
			switch (vec) {
			case 0:
				x += spd;
				break;
			case 1:
				x -= spd;
				break;
			case 2:
				y += spd;
				break;
			case 3:
				y -= spd;
				break;
			}
		}
	}
};

Light _circle;

Crack rects[ C_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	noStroke( );
	rectMode(CENTER);

	framecount = 0;

	for (int i = 0; i < C_NUM; i++)
	{
		_circle.Setup( );
		rects[ i ].Setup( );
	}
}

void draw( ) {
	background(BACKCOLOR);
	_circle.Update( );
	_circle.Draw( );
	rotate(radians(framecount));
	blendMode(MULTIPLY);
	for (int i = 0; i < C_NUM; i++)
	{
		rects[ i ].Draw( );
		rects[ i ].Update( );
	}
	blendMode(BLEND);
	framecount++;
}

