#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int BACKCOL = 0;
const int R_DIA = 50;
const int R_SPD = 3;
const double NOISERANGE = 0.01;

void drawnoise( );

int High_Line;

struct Tower {
	int x, y, dw, dh;
	bool Stop;

	void Setup( ) {
		x = (int)random(0, CENTER_X);
		y = 0;
		dw = (CENTER_X - x) + (int)random(0,CENTER_X);
		dh = R_DIA;
		Stop = false;
	}

	void Update( ) {
		if (y < High_Line)
		{
			y += R_SPD;
		}
		else if (!Stop) {
			Stop = true;
			High_Line -= R_DIA - R_SPD;
		}
	}

	void Draw( ) {
		rect(x, y, dw, dh);
	}
};

std::vector<Tower> rects;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	High_Line = HEIGHT - R_DIA;
}

void draw( ) {
	background(BACKCOL);
	fill(255);
	noStroke( );
	for (auto& R : rects)
	{
		R.Update( );
		R.Draw( );
	}
	blendMode(MULTIPLY);
	drawnoise( );
	blendMode(BLEND);
}

void drawnoise( ) {
	for (int x = 0; x < WIDTH; x += 5)
	{
		for (int y = 0; y < HEIGHT; y += 5)
		{
			int r = noise(x * NOISERANGE, y * NOISERANGE) * 255;
			int g = noise(x * NOISERANGE + 100, y * NOISERANGE) * 255;
			int b = noise(x * NOISERANGE, y * NOISERANGE + 100) * 255;
			fill(r, g, b);
			ellipse(x, y, 5);
		}
	}
}

void mouseClicked( ) {
	Tower newR;
	newR.Setup( );
	rects.push_back(newR);
}

