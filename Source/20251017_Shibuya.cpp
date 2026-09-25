#include "Processing.h"

const int WIDTH = 300;
const int HEIGHT = 300;
const int BACKCOL = 0;
const int GRID_SIZE = 20;

int Framecount = 0;

void Create();

class Col_E {
public:
	int x, y;
	int dia;
	int spd;
	bool Stop;
public:
	void Setup() {
		dia = ( int )random(5, 30);
		x = ( int )random(WIDTH - dia);
		y = 0 - dia;
		Stop = false;
		spd = (int)random(2,10);
	};
	void Draw() {
		ellipse(x, y, dia,dia);
	};
	void Update() {
		if (y < HEIGHT - dia) {
			y += spd;
		}
		else if (y >= HEIGHT - dia && !Stop) {
			y = HEIGHT - dia / 2;
			Stop = true;
		}
	};
};

std::list<Col_E> spheres;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	setFrameRate(10);
	noStroke();
	for (int i = 0; i < 10; i++) {
		Create();
	}
	
}

void draw() {
	background(BACKCOL);

	for (auto& E : spheres) {
		fill(255);
		E.Draw();
		E.Update();
	}

	for (auto it = spheres.begin(); it != spheres.end(); ++it) {
		for (auto other = spheres.begin(); other != spheres.end(); ++other) {
			if (it != other) {
				int dx = other->x - it->x;
				int dy = other->y - it->y;
				double dirt = sqrt(( dx * dx ) + ( dy * dy ));
				if (dirt < other->dia / 2 + it->dia / 2) {
					double ang = atan2(other->y - it->y, other->x - it->x);
					double gap = other->dia / 2 + it->dia / 2 - dirt;
					it->x -= cos(ang) * gap / 2;
					it->y -= sin(ang) * gap / 2;
					other->x += cos(ang) * gap / 2;
					other->y += sin(ang) * gap / 2;
				}
			}
		}
	}

	blendMode(MULTIPLY);
	colorMode(HSB, 100, 100, 100);
	for (int w = 0; w < WIDTH; w += GRID_SIZE / 2) {
		for (int h = 0; h < HEIGHT; h += GRID_SIZE / 2) {
			fill(noise(w * 0.05, h * 0.05,Framecount*0.01) * 100, 100, 100);
			ellipse(w, h, GRID_SIZE);
		}
	}
	blendMode(BLEND);
	colorMode(RGB,255);

	if (Framecount % 60 == 0) {
		for (int i = 0; i < 10; i++) {
			Create();
		}
	}

	Framecount++;
}

void Create() {
	Col_E E;
	E.Setup();
	spheres.push_front(E);
	if (spheres.size() > 100) spheres.pop_back();
}
