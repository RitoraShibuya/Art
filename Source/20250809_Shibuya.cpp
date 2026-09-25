#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 255;
const int R_NUM = 8;
const int STEP_NUM = 10;
const int W_MAXSIZE = 300;
const int H_MAXSIZE = 100;

struct STEPS
{
    int sx, sy; // スタート位置

    void Setup(int set_x, int set_y)
    {
        sx = set_x;
        sy = set_y;
    }

    void Draw()
    {
        int mx = getMouseX();
        int my = getMouseY();

        for (int i = 0; i < STEP_NUM; i++)
        {
            // 0.0〜1.0 の比率で線形補間
            float t = (float)i / STEP_NUM;

            float x_pos = sx + (mx - sx) * t;
            float y_pos = sy + (my - sy) * t;

            float w = W_MAXSIZE * (1.0 - t);
            float h = H_MAXSIZE * (1.0 - t);

            rectMode(CENTER);
            rect(x_pos, y_pos, w, h);
        }
    }
};

STEPS rects[R_NUM];

void setup()
{
    size(WIDTH, HEIGHT);
    noStroke();
    fill(0);
    background(BACKCOLOR);

    // 四隅をセット
    rects[0].Setup(0, 0);
    rects[1].Setup(CENTER_X, 0);
    rects[2].Setup(WIDTH, 0);
    rects[3].Setup(0, CENTER_Y);
    rects[4].Setup(0, HEIGHT);
    rects[5].Setup(CENTER_X, HEIGHT);
    rects[6].Setup(WIDTH, HEIGHT);
    rects[7].Setup(WIDTH, CENTER_Y);
}

void draw()
{
    background(BACKCOLOR);

    for (int i = 0; i < R_NUM; i++)
    {
        rects[i].Draw();
    }
}
