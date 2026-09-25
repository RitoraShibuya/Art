#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int S_NUM = 100;
const double NOISERANGE = 0.05;

int Framecount = 0;

void SphereShahull();

enum Sphere { Rect, Circle, Triangle };
Sphere SH;  // 今描画する図形タイプ

struct Point {
	int x, y, dia;
};

Point points[S_NUM];

void setNoiseStroke(int x, int y, int f) {
	int r = map(noise(x * NOISERANGE, y * NOISERANGE, f * NOISERANGE), 0.0, 1.0, 0, 255);
	int g = map(noise(x * NOISERANGE + 100, y * NOISERANGE, f * NOISERANGE), 0.0, 1.0, 0, 255);
	int b = map(noise(x * NOISERANGE, y * NOISERANGE + 100, f * NOISERANGE), 0.0, 1.0, 0, 255);
	stroke(r, g, b);
}

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noFill();
	strokeWeight(2);
	rectMode(CENTER);

	for (int i = 0; i < S_NUM; i++) {
		points[i].x = (int)random(WIDTH);
		points[i].y = (int)random(HEIGHT);
		points[i].dia = (int)random(200);
	}

	SH = Rect;
	Framecount = 0;
}

void draw() {
	background(BACKCOL);

	// 180フレームごとに形を切り替え
	if (Framecount % 180 == 0) {
		SphereShahull();
		Framecount = 0;
	}

	// 回転角度を決める（全体で共通）
	float angle = radians(Framecount);

	rotate(angle);

	for (int c = 0; c < S_NUM; c++) {
		setNoiseStroke(points[c].x, points[c].y, Framecount);

		switch (SH) {
		case Rect:
			rect(points[c].x, points[c].y, points[c].dia, points[c].dia);
			break;
		case Circle:
			ellipse(points[c].x, points[c].y, points[c].dia, points[c].dia);
			break;
		case Triangle:
			triangle(points[c].x,
				points[c].y - points[c].dia / 2,
				points[c].x - points[c].dia / 2,
				points[c].y + points[c].dia / 2,
				points[c].x + points[c].dia / 2,
				points[c].y + points[c].dia / 2);
			break;
		}
	}

	Framecount++;
}

void SphereShahull() {
	if (SH == Triangle) {
		SH = Rect;
	}
	else {
		SH = (Sphere)((int)SH + 1);
	}
}

void mouseClicked() {
	SphereShahull();
}
