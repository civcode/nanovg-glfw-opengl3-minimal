#ifndef DRAW_H_
#define DRAW_H_

#include "nanovg.h"

class Draw {
public:
    Draw(){};

    static void set_nvgContext(NVGcontext *ctx);

    //static void init_shapes();

    static void draw();

private:
    static NVGcontext *vg_;
};

#endif // DRAW_H_
