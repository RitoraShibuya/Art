#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int GRID_SIZE = 100;
const int GRID_COUNT_X = WIDTH / GRID_SIZE;
const int GRID_COUNT_Y = HEIGHT / GRID_SIZE;

int GRID_X[ GRID_COUNT_X ];
int GRID_Y[ GRID_COUNT_Y ];

int Framecount = 0;

int getGrid_x(int x);
int getGrid_y(int y);

class Dron {
public:
    int x;
    int y;

    void Setup( ) {
        x = 0;
        y = 0;
    }

    void Draw( ) {
        fill(255);
        rect(getGrid_x(x), getGrid_y(y), GRID_SIZE, GRID_SIZE);
    }

    void Update( ) {
        y++;
        if (y >= GRID_COUNT_Y) {
            y = 0;
            x++;
            if (x >= GRID_COUNT_X) {
                x = 0; // 全走査したらリセット
            }
        }
    }
};

class Grass {
public:
    int x;
    int y;
    int graw;
    int s_count;
    int grawtime;

    void Setup(int set_x, int set_y) {
        x = set_x;
        y = set_y;
        graw = 0;
        s_count = Framecount;
        grawtime = 30;
    }

    void Draw( ) {
        fill(0, 255, 0);
        switch (graw) {
        case 0:
            rect(getGrid_x(x), getGrid_y(y), 25, 25);
            break;
        case 1:
            rect(getGrid_x(x), getGrid_y(y), 50, 50);
            break;
        case 2:
            rect(getGrid_x(x), getGrid_y(y), GRID_SIZE, GRID_SIZE);
            break;
        }
    }

    void Update( ) {
        if (Framecount >= s_count + grawtime) {
            if (graw < 2) graw++;
            s_count = Framecount;
        }
    }
};

Dron D_rect;
std::vector<Grass> G_rects;

void setup( ) {
    size(WIDTH, HEIGHT);
    setFrameRate(30);
    rectMode(CENTER);
    background(0);

    // グリッド座標を初期化
    for (int i = 0; i < GRID_COUNT_X; i++) GRID_X[ i ] = i;
    for (int i = 0; i < GRID_COUNT_Y; i++) GRID_Y[ i ] = i;

    D_rect.Setup( );
}

void draw( ) {
    background(0);

    // 地面
    stroke(0);
    fill(155, 80, 50);
    for (int x = 0; x < GRID_COUNT_X; x++) {
        for (int y = 0; y < GRID_COUNT_Y; y++) {
            rect(getGrid_x(x), getGrid_y(y), GRID_SIZE, GRID_SIZE);
        }
    }

    // 草の生成（60フレームごと）
    if (Framecount % 60 == 0) {
        int g_x, g_y;
        bool plantable;
        do {
            g_x = (int)random(GRID_COUNT_X);
            g_y = (int)random(GRID_COUNT_Y);
            plantable = true;

            // 重複チェック
            for (auto& G : G_rects) {
                if (G.x == g_x && G.y == g_y) {
                    plantable = false;
                    break;
                }
            }
        } while (!plantable);

        Grass G;
        G.Setup(g_x, g_y);
        G_rects.push_back(G);
    }

    // 草の描画・更新
    for (auto& G : G_rects) {
        G.Update( );
        G.Draw( );
    }

    // ドローンの移動と草の削除（5フレームごと）
    if (Framecount % 5 == 0) {
        for (int i = 0; i < (int)G_rects.size( ); i++) {
            if (G_rects[ i ].x == D_rect.x && G_rects[ i ].y == D_rect.y) {
                G_rects.erase(G_rects.begin( ) + i);
                i--;
            }
        }
        D_rect.Update( );
    }

    // ドローン描画
    D_rect.Draw( );

    Framecount++;
}

int getGrid_x(int x) {
    return GRID_X[ x ] * GRID_SIZE + GRID_SIZE / 2;
}

int getGrid_y(int y) {
    return GRID_Y[ y ] * GRID_SIZE + GRID_SIZE / 2;
}
