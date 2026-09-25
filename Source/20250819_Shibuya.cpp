#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int START_NUM = 20;
const int CENTERGAP = 500;
const int SPD_MAX = 10;

struct HOLE {
	double x, y, r, g, b, ang;

	void Setup(int i) {
		ang = PI * 2 * i / START_NUM;
	}

	void Draw() {
		r = 0;
		g = 0;
		b = 255;
		stroke(r, g, b, 30);
	}

	void Update() {
		ang += random(SPD_MAX) * 0.05;
		x = CENTER_X + sin(ang) * CENTERGAP;
		y = CENTER_Y + cos(ang) * CENTERGAP;
	}
};

std::vector<HOLE> Ellipses;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	strokeWeight(1);

	for (int i = 0; i < START_NUM; i++) {
		HOLE h;
		h.Setup(i);
		Ellipses.push_back(h);
	}
}

void draw() {
	beginShape();
	background(BACKCOLOR,5);
	for (int c = 0; c < Ellipses.size(); c++) {
		Ellipses[c].Update();
		Ellipses[c].Draw();
		vertex(Ellipses[c].x, Ellipses[c].y);
	}
	endShape(CLOSE);
}



