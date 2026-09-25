#include "Processing.h"
#include <list>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int WEIGHT = 10;
const int GRID_SIZE = 100;
const int DIA = GRID_SIZE - WEIGHT / 2;
const int G_COUNT_X = WIDTH / GRID_SIZE;
const int G_COUNT_Y = HEIGHT / GRID_SIZE;

int Framecount = 0;

void Kill( );
void Create( );

class FallBlock {
public:
	int x, y;
	bool isStop;
public:
	void Setup( ) {
		x = (int)random(G_COUNT_X);
		y = 0;
		isStop = false;
	};
	void Draw( ) {
		fill(0, 0, 100);
		rect(x * GRID_SIZE, y * GRID_SIZE, DIA, DIA);
	};
	void Update( ) {
		if (!isStop)
		{
			y++;
		}
	};
};

std::list<FallBlock> blocks;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke( );
	colorMode(HSB, 360, 100, 100);

	FallBlock F;
	F.Setup( );
	blocks.push_back(F);
}

void draw( ) {
	background(BACKCOL, 0, 0);

	for (auto it = blocks.begin( ); it != blocks.end( ); ++it) {
		it->Draw( );

		if (Framecount % 10 == 0) {
			bool canFall = true;
			for (auto other = blocks.begin( ); other != blocks.end( ); ++other) {
				if (other != it && other->x == it->x && other->y == it->y + 1) {
					canFall = false;
					break;
				}
			}

			if (!it->isStop && canFall && it->y < G_COUNT_Y - 1) {
				it->Update( );
			}
			else if (!it->isStop && ( !canFall || it->y >= G_COUNT_Y - 1 )) {
				it->isStop = true;
				Create( );
			}
		}
	}

	blendMode(MULTIPLY);
	for (int w = 0; w < WIDTH; w += 10)
	{
		for (int h = 0; h < HEIGHT; h += 10)
		{
			int H = noise(w * 0.008, h * 0.008, Framecount * 0.01) * 360;
			int B = noise(w * 0.01, h * 0.01) * 100;
			fill(H, 100, B);
			rect(w, h, 10, 10);
		}
	}
	blendMode(BLEND);

	Framecount++;
}

void Kill( ) {
	/*if (it->isStop) {
		it = blocks.erase(it);
	}
	else {
		++it;
	}*/
}

void Create( ) {
	FallBlock F;
	F.Setup( );
	blocks.push_front(F);
}
