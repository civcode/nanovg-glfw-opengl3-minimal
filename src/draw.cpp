#include "draw.h"

#include <random>
#include <vector>
#include <execution>

#include "shape.h"

using std::vector;

NVGcontext * Draw::vg_ = nullptr;


void Draw::set_nvgContext(NVGcontext *ctx) {
    vg_ = ctx;
    Shape::set_nvgContext(ctx);
}

void Draw::draw() {

    static int n = 10000;
    static vector<Circle> circles;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> rand_pos(50, 350);
    std::uniform_real_distribution<float> rand_col(0, 1);

    if (circles.size() == 0) {
        for (int i=0; i<n; i++) {
            int x = rand_pos(mt);
            int y = rand_pos(mt);
            float r = rand_col(mt);
            float g = rand_col(mt);
            float b = rand_col(mt);
            int rad = 2;
            circles.push_back(Circle(x, y, rad, Color(r,g,b)));
        }  

    }

    if (true) {
        for (auto &c : circles) {
            std::uniform_int_distribution<int> delta(-1, 1);
            int dx = delta(mt);
            int dy = delta(mt);
            auto [x,y] = c.position();
            c.set_position(x+dx, y+dy);
        }
    } else {
        std::for_each(
            std::execution::par,
            circles.begin(),
            circles.end(),
            [&](auto &&item) {
                std::random_device rd;
                std::mt19937 mt(rd());
                std::uniform_int_distribution<int> delta(-1, 1);
                int dx = delta(mt);
                int dy = delta(mt);
                auto [x,y] = item.position();
                item.set_position(x+dx, y+dy);
            }
        );
    }

    for (auto c : circles) {
        //c.print();
        c.render();
    }
}
