#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int E_NUM = 20;
const int SPD = 3;

struct C_Point {
	int x = 250;
	int y = 250;
};

struct P_E {
	int x = WIDTH / 2;
	int y = HEIGHT / 2;
	double ang = 0.0;
	int dia = 50;
};

class Col_E {
public:
	int x, y;
	int dia;
	int spd;
	int r, g, b;
public:
	void Setup( ) {
		x = (int)random(WIDTH);
		y = 0;
		dia = random(50, 200);
		spd = (int)random(SPD) + 1.0;
		r = 0;
		g = 0;
		b = 0;
		switch ((int)random(3)) {
		case 0:
			r = 255;
			break;
		case 1:
			g = 255;
			break;
		case 2:
			b = 255;
			break;
		}
	};
	void Draw( ) {
		fill(r, g, b);
		ellipse(x, y, dia);
	};
	void Update( ) {
		if (y < WIDTH + dia) {
			y += spd;
		}
		else {
			y = 0 - dia;
		}
	};
};

C_Point player;

P_E pet;

Col_E enemy[ E_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	noStroke( );
	for (int i = 0; i < E_NUM; i++)
	{
		enemy[ i ].Setup( );
	}
}

void draw( ) {
	background(BACKCOL);

	fill(255);
	ellipse(player.x, player.y, 20, 20);

	for (int i = 0; i < E_NUM; i++)
	{
		enemy[ i ].Draw( );
		enemy[ i ].Update( );
	}

	stroke(255);
	noFill( );

	ellipse(pet.x, pet.y, pet.dia, pet.dia);

	noStroke( );

	pet.ang = atan2(player.y - pet.y, player.x - pet.x);

	pet.x += cos(pet.ang)*SPD;
	pet.y += sin(pet.ang)*SPD;

	for (int j = 0; j < E_NUM; j++)
	{
		int dx = pet.x - enemy[ j ].x;
		int dy = pet.y - enemy[ j ].y;
		double dist = sqrt(dx * dx + dy * dy);
		if (dist < (pet.dia + enemy[j].dia) / 2)
		{
			enemy[ j ].Setup( );
		}
	}
}

void mouseClicked( ) {
	int mx = getMouseX( );
	int my = getMouseY( );
	player.x = mx;
	player.y = my;
}

