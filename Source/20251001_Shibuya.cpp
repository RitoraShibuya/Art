#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 50;
const double NOISERANGE = 0.005;  // 小さいほど変化が滑らか

int Framecount;

struct Vertexs {
	int x, y;
};

std::vector<Vertexs> points;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	stroke(255);
	colorMode(HSB, 360, 100, 100);
	Framecount = 0;
}

void draw() {
	background(BACKCOL);

	int mx = getMouseX();
	int my = getMouseY();

	// 一定フレームごとに点を追加
	if (Framecount % 20 == 0) {
		Vertexs newV{ mx, my };
		points.push_back(newV);

		// 古い点を削除して最大数を制限
		if (points.size() > 12) {
			points.erase(points.begin());
		}
	}

	int oldx1 = mx;
	int oldy1 = my;
	int oldx2 = mx;
	int oldy2 = my;

	beginShape();
	for (int i = 0; i < points.size(); i++) {
		Vertexs V = points[i];
		vertex(V.x, V.y);

		if (i % 2 == 0 && i > 1) {
			// 3点ごとに三角形
			int r = noise(V.x * NOISERANGE, V.y * NOISERANGE, Framecount * 0.01) * 255;
			int g = noise(V.x * NOISERANGE + 100, V.y * NOISERANGE, Framecount * 0.01) * 255;
			int b = noise(V.x * NOISERANGE, V.y * NOISERANGE + 100, Framecount * 0.01) * 255;
			fill(r, g, b, 150); // 半透明にすると重なりが映える
			triangle(V.x, V.y, oldx1, oldy1, oldx2, oldy2);
		}
		oldx2 = oldx1;
		oldy2 = oldy1;
		oldx1 = V.x;
		oldy1 = V.y;
	}
	triangle(points.begin()->x, points.begin()->y, oldx1, oldy1, oldx2, oldy2);
	endShape();

	Framecount++;
}
