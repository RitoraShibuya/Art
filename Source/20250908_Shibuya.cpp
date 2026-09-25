#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int BACKGRAY = 10;
const int GAP = 1;                 // 進む距離
const double NOISERANGE = 0.001;
const double NOISE_COL = 0.005;
const int LINE_NUM = 50;           // 線の本数

struct Walker {
	double x, y;
	double ang;       // 角度
	int framecount;

	void setup() {
		// 画面内のランダムな位置から開始
		x = random(WIDTH);
		y = random(HEIGHT);
		ang = random(TWO_PI);
		framecount = 0;
	}

	void update() {
		// ノイズから角度を変化させる
		ang = radians(noise(x * NOISERANGE, y * NOISERANGE, framecount * NOISERANGE) * 360);

		// 移動
		x += sin(ang) * GAP;
		y += cos(ang) * GAP;

		// 色
		fill(noise(x * NOISE_COL, y * NOISE_COL) * 255,
			noise(x * NOISE_COL + 100, y * NOISE_COL) * 255,
			noise(x * NOISE_COL, y * NOISE_COL + 100) * 255,
			150);

		ellipse(x, y, 1);

		// 画面外に出たらランダムな位置に戻す
		if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) {
			x = random(WIDTH);
			y = random(HEIGHT);
			ang = random(TWO_PI);  // 新しい方向で再出発
		}

		framecount++;
	}
};



Walker walkers[LINE_NUM];

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	noStroke();
	for (int i = 0; i < LINE_NUM; i++) {
		walkers[i].setup();
	}
}

void draw() {
	for (int i = 0; i < LINE_NUM; i++) {
		walkers[i].update();
	}
}
