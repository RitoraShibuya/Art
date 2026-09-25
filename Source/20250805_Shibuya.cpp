#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 255;
const int BACKALPHA = 5;
const int POINTS = 2;

float hue_value = 0;  // 色相（0～360）

struct POINT
{
	double x;
	double y;

	void Setup(int i)
	{
		x = 500 + (i % 2 == 0 ? i : -i) * 100;
		y = 500 + (i % 2 == 0 ? i : -i) * 100;
	}

	void Update()
	{
		x += random(-50, 50);
		y += random(-50, 50);

		if (x > WIDTH) x = 0;
		if (x < 0)     x = WIDTH;
		if (y > HEIGHT) y = 0;
		if (y < 0)      y = HEIGHT;
	}
};

POINT vertexes[POINTS];

void setup()
{
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	strokeWeight(5);
	colorMode(HSB, 360, 100, 100);  // 色相、彩度、明度で色を設定

	for (int i = 0; i < POINTS; i++)
		vertexes[i].Setup(i);
}

void draw()
{
	background(BACKCOLOR, BACKALPHA);

	for (int i = 0; i < POINTS; i++)
		vertexes[i].Update();

	// ゆっくり色相を回す（1フレームごとに +1）
	hue_value += 1;
	if (hue_value > 360)
		hue_value = 0;

	stroke(hue_value, 100, 100);  // 彩度100・明度100の鮮やかな色
	line(vertexes[0].x, vertexes[0].y, vertexes[1].x, vertexes[1].y);
}
