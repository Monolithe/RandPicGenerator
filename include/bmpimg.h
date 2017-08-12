#ifndef BMPIMG_H
#define BMPIMG_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct bmpimg {
    const char *name;
    int height;
    int width;
    int size;
};

struct bmpimg *newbmpimg(const char* name, int height, int width);
void freebmpimg(struct bmpimg *img);
void genbmpimg(struct bmpimg *img);

#endif
