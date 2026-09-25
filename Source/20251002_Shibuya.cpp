#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int R_NUM = 10;
const int MIN_DIA = 30;
const int MAX_DIA = 100;
const int SPD = 1;
const double NOISERANGE = 0.02;

class Tree {
public:
	int x;
	int y;
	int dia;
	int spd;
	double ang;

	void Setup(int i) {
		x = x = (int)((i + 0.5) * WIDTH / R_NUM);
		y = 0;
		dia = (int)random(MIN_DIA, MAX_DIA);
		spd = SPD;
		ang = 0;
	}

	void Draw() {
		rect(x, y, dia, dia);
	}

	void Update() {
		// ノイズに基づいた角度
		ang = radians(noise(x * NOISERANGE, y * NOISERANGE) * 360);

		// 横にふらふら動く（sin を使う）
		x += sin(ang) * 2;

		// 下方向に一定速度で進む
		y += spd;

		// サイズを毎回ランダムに（オプション）
		dia = (int)map(noise(x * NOISERANGE, y * NOISERANGE), 0, 1, MAX_DIA, MIN_DIA);
	}
};

Tree Rects[R_NUM];

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noFill();
	stroke(255);
	strokeWeight(2);
	for (int i = 0; i < R_NUM; i++) {
		Rects[i].Setup(i);
	}
}

void draw() {
	// background(BACKCOL); // 軌跡が残るようにコメントアウト
	for (int i = 0; i < R_NUM; i++) {
		Rects[i].Draw();
		Rects[i].Update();
	}
}

void mouseClicked() {
	background(BACKCOL);
	for (int i = 0; i < R_NUM; i++) {
		Rects[i].Setup(i);
	}
}
