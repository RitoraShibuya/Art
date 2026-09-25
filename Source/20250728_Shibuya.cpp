#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUNDCOLOR = 0;
const int BACKGROUNDGRAYSCALE = 10;
const int DIA = 50;
const int E_MIN = 90;
const int E_MAX = 315;
const int RECT_NUM = 20;
const int SPAWN_INTERVAL = 15;

struct MovingRect {
	int ang;
	int e_size;
	int x, y;
	int dia;
	int center_x, center_y;
	int delayFrames;
	int spd;
	bool active;
	bool clockwise;

	void init(int cx, int cy, int angleOffset, int delay) {
		center_x = cx;
		center_y = cy;
		ang = angleOffset;
		e_size = (int)random(E_MIN, E_MAX);
		delayFrames = delay;
		spd = random(1, 4);
		clockwise = (random(2) == 0);  // 50%‚ÌŠm—¦‚Å‹t‰ñ“]
		active = false;
	}

	void update(int frameCount) {
		if (!active) {
			if (frameCount >= delayFrames) {
				active = true;
				center_x = getMouseX();
				center_y = getMouseY();
			}
			else {
				return;
			}
		}

		float rad = radians(ang);
		x = center_x + sin(rad) * e_size;
		y = center_y + cos(rad) * e_size;
		dia = (int)map(e_size, 0, E_MAX, 0, DIA);

		noStroke();
		fill(255, 0, 0, 90);
		rect(x, y, dia, dia);

		ang = (clockwise ? (ang + 1) : (ang - 1) + 360) % 360;
		e_size -= spd;

		if (e_size <= 0) {
			ang = random(360);
			e_size = (int)random(E_MIN, E_MAX);
			delayFrames = frameCount + SPAWN_INTERVAL * random(1, RECT_NUM);
			spd = random(1, 5);
			clockwise = (random(2) == 0);  // Ä“xƒ‰ƒ“ƒ_ƒ€‚È‰ñ“]•ûŒü
			active = false;
		}
	}
};

MovingRect rects[RECT_NUM];
int globalFrame = 0;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKGROUNDCOLOR);
	rectMode(CENTER);

	for (int i = 0; i < RECT_NUM; i++) {
		int angleOffset = (360 / RECT_NUM) * i;
		int delay = SPAWN_INTERVAL * i;
		rects[i].init(WIDTH / 2, HEIGHT / 2, angleOffset, delay);
	}
}

void draw() {
	background(BACKGROUNDCOLOR, BACKGROUNDGRAYSCALE);
	globalFrame++;

	for (int i = 0; i < RECT_NUM; i++) {
		rects[i].update(globalFrame);
	}
}
