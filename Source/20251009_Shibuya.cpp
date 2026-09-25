#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 255;
const int COL = 0;
const int L_NUM = 50;
const double SPD = 0.5;
const int GRID_SIZE = 2;
const int C_GAP = 10;
const double NOISE_RANGE = 0.01;

class Crack {
public:
	int num;
	int cx, cy;
	int x, y;
	int dia;
	double spd;
	double ang;

public:
	void Setup(int i, int mx, int my) {
		num = i;
		cx = mx;
		cy = my;
		ang = PI2 / L_NUM * i + 1;
		x = cx + cos(ang) * C_GAP;
		y = cy + sin(ang) * C_GAP;
		dia = GRID_SIZE;
		spd = 0.0;
	};

	void Draw() {

		point(x, y);
	};

	void Update() {
		x = cx + cos(ang) * (C_GAP + spd);
		y = cy + sin(ang) * (C_GAP + spd);
		spd += SPD;
		ang += radians(map(noise(x * NOISE_RANGE, y * NOISE_RANGE, spd * NOISE_RANGE), 0, 1, -1, 1));
	};
};

std::vector<Crack> crackes;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
}

void draw() {

	fill(COL);
	for (auto& C : crackes) {
		C.Draw();
		C.Update();
	}
}

void mouseClicked() {
	crackes.clear();

	for (int i = 0; i < L_NUM; i++) {
		Crack newC;
		newC.Setup(i, getMouseX(), getMouseY());
		crackes.push_back(newC);
	}
}


