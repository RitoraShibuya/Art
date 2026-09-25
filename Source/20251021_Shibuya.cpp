#include "Processing.h"

const int WIDTH = 300;
const int HEIGHT = 500;
const int DIA = 100;
const int SPD = 5;
const int GRID = 20;

int Framecount = 0;
int backcol = 0;
bool isgravity = false;

void create( );

class Col_E {
public:
	int x, y;
	int dia;
	bool Stop;
public:
	void Setup(int mx) {
		x = mx;
		y = 0;
		dia = (int)random(50, 100);
		Stop = false;
	};

	void Draw( ) {
		ellipse(x, y, dia);
	};

	void Update( ) {
		if (y >= HEIGHT - dia / 2) {
			Stop = true;
		}
		else {
			y += SPD;
		}
	};
};

std::list<Col_E> spheres;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(backcol);
	noStroke( );
	setFrameRate(30);
}

void draw( ) {
	background(backcol);

	strokeWeight(10);
	stroke(255);
	line(getMouseX(), 0, getMouseX( ), HEIGHT);
	noStroke( );

	if (Framecount % 30 == 0)
	{
		create( );
	}
	fill(255);
	for (auto it = spheres.begin( ); it != spheres.end( );++it)
	{
		it->Draw( );
		if (it->Stop)continue;
		it->Update( );
		for (auto other = spheres.begin( ); other != spheres.end( );++other) 
		{
			if (it != other)
			{
				int dx = other->x - it->x;
				int dy = other->y - it->y;
				int dist = sqrt(dx * dx + dy * dy);
				int gap = it->dia / 2 + other->dia / 2;
				if (dist < gap)
				{
					if (isgravity)
					{
						double ang = atan2(dy, dx);
						it->x -= cos(ang) * SPD;
						it->y -= sin(ang) * SPD;
					}
					else {
						it->Stop = true;
					}
				}
			}
		}

		
	}

	blendMode(MULTIPLY);
	for (int x = 0; x < WIDTH; x += GRID)
	{
		for (int y = 0; y < HEIGHT; y += GRID)
		{
			fill(noise(x * 0.01, y * 0.01, Framecount * 0.01) * 255,
				 noise(x * 0.01 + 300, y * 0.01, Framecount * 0.01) * 255,
				 noise(x * 0.01, y * 0.01 + 300, Framecount * 0.01) * 255);
			rect(x, y, GRID, GRID);
		}
	}
	blendMode(BLEND);

	Framecount++;
}

void create( ) {
	Col_E E;
	E.Setup(getMouseX( ));
	spheres.push_front(E);
}

void mouseClicked( ) {
	
	if (isgravity)
	{
		backcol = 0;
		isgravity = false;
	}
	else{
		isgravity = true;
		backcol = 170;
		for (auto it = spheres.begin( ); it != spheres.end( );++it)
		{
			if (it->y <= HEIGHT + DIA / 2)it->Stop = false;
		}
	}
	
}
