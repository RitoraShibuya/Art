#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int BACKCOL = 0;
const int GRID = 10;
const int X_COUNT = WIDTH / GRID;
const int Y_COUNT = HEIGHT / GRID;
const int SPD = 1;

int Framecount = 0;

class C_L {
public:
	double x, y;
	double ang;
	int h;
public:
	void Setup(int sx, int sy) {
		x = sx;
		y = sy;
		ang = atan2(CY - y, CX - x);
	}
	void Draw() {
		stroke(h, 100, 100);
		point(x, y);
	}
	void Update() {
		x += cos(ang) * (noise(x * 0.01, y * 0.01) - 0.5) * SPD;
		y += sin(ang) * (noise(x * 0.01, y * 0.01) - 0.5) * SPD;
		h = noise(x * 0.01, y * 0.01, Framecount * 0.01) * 360;
	}
};

std::list<C_L> col_l;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	colorMode(HSB, 360, 100, 100);

	for (int x = GRID / 2; x < WIDTH; x += GRID)
	{
		for (int y = GRID / 2; y < HEIGHT; y += GRID)
		{
			C_L L;
			L.Setup(x, y);
			col_l.push_back(L);
		}
	}
}

void draw() {
	background(BACKCOL);
	for (auto it = col_l.begin();it != col_l.end();++it) {
		it->Draw();
		it->Update();
	}
	Framecount++;
}


void mouseClicked() {
	for (auto it = col_l.begin();it != col_l.end();++it) {
		it->ang += PI;
	}
}