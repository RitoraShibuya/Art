#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int GRID = 20;
const double NOISERANGE = 0.005;
const int E_NUM = 30;
const int MIN_DIA = 30;
const int MAX_DIA = 80;
const int MAX_LIFE = 60;   // 寿命（フレーム数）

struct Babble {
	double x, y;
	int dia, num, life;
	double ang, spd;

	void Setup(int i, int mx, int my) {
		x = mx;
		y = my;
		num = i;
		ang = PI2 * num / E_NUM;        // 放射状に配置
		dia = (int)random(MIN_DIA, MAX_DIA);
		spd = 0;
		life = MAX_LIFE;               // 初期寿命
	}

	void Update( ) {
		x += sin(ang) * spd;
		y += cos(ang) * spd;
		spd += 0.1;       // 加速
		life--;      // 寿命を減らす
	}

	void Draw( ) {
		ellipse(x, y, dia);
	}

	bool isDead( ) {
		return life <= 0;
	}
};

std::vector<Babble> ellipses;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	noStroke( );
	setFrameRate(30);
}

void draw( ) {
	background(BACKCOLOR, 10);  // 少し残像を残すように
	fill(255);
	for (auto it = ellipses.begin( ); it != ellipses.end( );) {
		it->Update( );
		it->Draw( );
		if (it->isDead( )) {
			it = ellipses.erase(it);   // 寿命切れで削除
		}
		else {
			++it;
		}
	}
	blendMode(MULTIPLY);
	for (int x = 0; x < WIDTH; x += GRID)
	{
		for (int y = 0; y < HEIGHT; y += GRID)
		{
			fill(noise(x * NOISERANGE, y * NOISERANGE) * 400,
				 noise(x * NOISERANGE + 100, y * NOISERANGE) * 400,
				 noise(x * NOISERANGE, y * NOISERANGE + 100) * 400);
				rect(x, y, GRID, GRID);
		}
	}
	blendMode(BLEND);
}

void mouseClicked( ) {
	for (int i = 0; i < E_NUM; i++) {
		Babble b;
		b.Setup(i, getMouseX( ), getMouseY( ));
		ellipses.push_back(b);
	}
}
