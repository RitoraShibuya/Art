#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID = 10;

int Framecount = 0;

class Col_R {
public:
	double x, y;
	double ang;
	double h;
public:
	void Setup(double sx, double sy) {
		x = sx;
		y = sy;
		ang = noise(x * 0.01, y * 0.01, Framecount * 0.01)*360 * PI2;
		h = noise(x * 0.01, y * 0.01, Framecount * 0.01) * 360;
	}
	void Draw() {
		fill(h, 100, 100);
		rect(x, y, 1, 1);
	}
	void Update() {
		if (x > WIDTH) x -= WIDTH;
		if (x < 0) x += WIDTH;
		if (y > HEIGHT) y -= HEIGHT;
		if (y < 0) y += HEIGHT;
		ang = noise(x * 0.01, y * 0.01, Framecount * 0.01) * 360 * PI2;
		x += cos(ang);
		y += sin(ang);
	}
};

std::list<Col_R> c_r;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	rectMode(CENTER);
	noStroke();
	//colorMode(HSB, 360, 100, 100);
	
	for (int x = GRID / 2; x < WIDTH; x += GRID)
	{
		for (int y = GRID / 2; y < HEIGHT; y += GRID)
		{
			Col_R R;
			R.Setup(x, y);
			c_r.push_back(R);
		}
	}
}

void draw() {
	background(BACKCOL,5);
	//fill(255);

	for (auto it = c_r.begin(); it != c_r.end(); ++it) {

		it->Draw();
		it->Update();
	}

	Framecount++;
}


