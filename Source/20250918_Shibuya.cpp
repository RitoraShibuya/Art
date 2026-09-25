#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int E_NUM = 5;
const int GAP = 50;
const int DIA_GAP = 10;
const int MAX_DIA = 200;
const double NOISERANGE = 0.01;

int Framecount;

struct BigCircle {
	int x, y, dia;

	void Setup( ) {
		x = getMouseX( );
		y = getMouseY( );
		dia = 0;
	}

	void Draw( ) {
		int r = noise(x * NOISERANGE, y * NOISERANGE, dia * NOISERANGE) * 255;
		int g = noise(x * NOISERANGE+100, y * NOISERANGE, dia * NOISERANGE) * 255;
		int b = noise(x * NOISERANGE, y * NOISERANGE+100, dia * NOISERANGE) * 255;
		stroke(r,g,b , 50);
		ellipse(x, y, dia);
	}

	void Update( ) {
		dia += DIA_GAP;
	}
};

std::vector<BigCircle> ellipses;

void setup( ) {
    setFrameRate(30);
	size(WIDTH, HEIGHT);
    background(BACKCOLOR);
	Framecount = 0;
}

void draw( ) {
    background(BACKCOLOR, 5);
    noFill( );

    if (Framecount % 10 == 0) {
        BigCircle newE;
        newE.Setup( );
        ellipses.push_back(newE);
        for (auto& E : ellipses) {
            E.Update( );
        }

        // è¡Ç∑Ç◊Ç´â~ÇèúäOÅiC++11 à»ç~Åj
        ellipses.erase(
            std::remove_if(ellipses.begin( ), ellipses.end( ), [] (const BigCircle& e) {
                return e.dia >= MAX_DIA;
                           }),
            ellipses.end( )
        );
    }

    // Ç‹Ç∏çXêV
    

    // ï`âÊ
    for (auto& E : ellipses) {
        E.Draw( );
    }

    Framecount++;
}



