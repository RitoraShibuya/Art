#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int MAXGAP = 300;
const int GAP = 200;
const int C_NUM = 5;

class WaveCircle {

public:
	int x, y, cx, cy, mx, my;
	int gap;
	int num;
	int baserad;
	double num_ang, ang;
	bool sizeswitch;
public:
	void Setup(int i) {
		gap = 0;
		num = i;
		baserad = (int)random(360);
		num_ang = PI2 * num / C_NUM;
		sizeswitch = true;
	};
	void Update(int s_mx, int s_my) {
		mx = s_mx;
		my = s_my;
		cx = mx + cos(num_ang) * GAP;
		cy = my + sin(num_ang) * GAP;
		if (sizeswitch) {
			gap++;
			if (gap >= MAXGAP) {
				sizeswitch = false;
			}
		}
		else {
			gap--;
			if (gap <= 0) {
				sizeswitch = true;
			}
		}
		num_ang += 0.005;
	};
	void Draw() {
		stroke(0, 0, 255);
		for (int c = 0; c < 270; c++)
		{
			double noisegap = noise(x * 0.01, y * 0.01, c * 0.01);
			x = cx + cos(radians(baserad + c)) * gap * noisegap;
			y = cy + sin(radians(baserad + c)) * gap * noisegap;
			point(x, y);
		}
		baserad++;
	};
};

WaveCircle _circles[C_NUM];

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	for (int i = 0; i < C_NUM; i++)
	{
		_circles[i].Setup(i);
	}
}

void draw() {
	background(BACKCOL, 5);
	for (int i = 0; i < C_NUM; i++)
	{
		_circles[i].Update(500, 500);
		_circles[i].Draw();
	}
}


