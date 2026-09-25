#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID = 10;
const int DIA = 2;
const int GAP = 20;

class Col_E {
public:
	double x, y;
	double dx, dy;
	double ang;

	void Setup(int sx, int sy) {
		dx = sx;
		dy = sy;
		x = dx;
		y = dy;
		ang = random(0, 1) * PI2;
	}
	void Draw() {
		point(x, y);
	}
	void Update() {
		x = dx + cos(ang) * noise(x * 0.01, y * 0.01, ang * 0.01) * GAP;
		y = dy + sin(ang) * noise(x * 0.01, y * 0.01, ang * 0.01) * GAP;
		ang += noise(x * 0.01, y * 0.01, ang * 0.005);
	}
};

std::list<Col_E>c_list;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke();
	for (int x = GRID / 2; x < WIDTH; x += GRID)
	{
		for (int y = GRID / 2; y < HEIGHT; y += GRID)
		{
			Col_E E;
			E.Setup(x, y);
			c_list.push_back(E);
		}
	}
}

void draw() {
	background(BACKCOL,20);
	stroke(255);
	for (auto it = c_list.begin(); it != c_list.end(); ++it)
	{
		it->Draw();
		it->Update();
	}
}


