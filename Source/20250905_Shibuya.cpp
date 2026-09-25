#include "Processing.h"
#include <vector>
#include <cmath>

// ========= 設定 =========
const int   WIDTH = 1000;
const int   HEIGHT = 1000;
const int   BACKCOLOR = 0;
const int   FADE_ALPHA = 3;      // 背景のフェード量（大きいほど早く消える）
const int   RIBBON_COUNT = 30;      // 帯の本数
const double THICK_MIN = 1.0;     // 最小太さ
const double THICK_MAX = 1.0;    // 最大太さ
const double STEP = 2.0;      // 1フレームで進む距離
const double NOISE_SCALE = 0.003;   // ノイズ座標のスケール
const double TIME_SPEED = 0.004;   // 時間に対するノイズの変化速度
const int   LIFE_MIN = 800;     // 帯の最短寿命（フレーム）
const int   LIFE_MAX = 1500;    // 帯の最長寿命

// ========= ユーティリティ =========
static double rand01() { return random(1000000) / 1000000.0; }
static double mapd(double v, double a, double b, double c, double d) {
    double t = (v - a) / (b - a);
    return c + (d - c) * t;
}

// ========= 帯 =========
struct Ribbon {
    double x, y;       // 現在位置
    double px, py;     // ひとつ前の位置（線分用）
    double t;          // 時間オフセット（色/流れの変化に使用）
    double thick;      // 太さ
    int life;          // 残り寿命
    int r, g, b;       // 色

    void respawn() {
        // 画面のどこかにランダム配置
        x = px = random(WIDTH);
        y = py = random(HEIGHT);
        // ランダムな時間バイアス
        t = random(10000) * 0.001;
        // 太さ・寿命をランダム化
        thick = mapd(rand01(), 0, 1, THICK_MIN, THICK_MAX);
        life = (int)mapd(rand01(), 0, 1, LIFE_MIN, LIFE_MAX);

        // 色は sin パレットで滑らかに
        double base = random(10000) * 0.01;
        r = (int)(127.5 + 127.5 * sin(base + 0.0));
        g = (int)(127.5 + 127.5 * sin(base + 2.094)); // 2π/3 ずらし
        b = (int)(127.5 + 127.5 * sin(base + 4.188)); // 4π/3 ずらし
    }

    void updateAndDraw(double globalTime) {
        // 進行方向をノイズで決める（0..1 → 0..TWO_PI）
        double ang = noise(x * NOISE_SCALE, y * NOISE_SCALE, (t + globalTime) * TIME_SPEED) * PI2;

        // 次の位置
        double nx = x + cos(ang) * STEP;
        double ny = y + sin(ang) * STEP;

        // 描画（太い半透明の線で帯っぽく）
        stroke(r, g, b, 90);
        strokeWeight((float)thick);
        line(px, py, nx, ny);

        // 次のステップに向けて更新
        px = x; py = y;
        x = nx; y = ny;
        life--;

        // 画面外に出た／寿命が尽きたら再出現
        if (x < -50 || x > WIDTH + 50 || y < -50 || y > HEIGHT + 50 || life <= 0) {
            respawn();
        }
    }
};

std::vector<Ribbon> ribbons;
static double globalTime = 0.0;

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    noFill();

    ribbons.reserve(RIBBON_COUNT);
    for (int i = 0; i < RIBBON_COUNT; ++i) {
        Ribbon r;
        r.respawn();
        ribbons.push_back(r);
    }
}

void draw() {
    // フェード：前フレームの残像を少しだけ残す
    background(BACKCOLOR, FADE_ALPHA);

    // 帯を更新＆描画
    for (auto& r : ribbons) {
        r.updateAndDraw(globalTime);
    }

    globalTime += 1.0; // 時間を進める
}
