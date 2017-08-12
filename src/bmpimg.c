#include "../include/bmpimg.h"

struct bmpimg *newbmpimg(const char *imgname, int height, int width) {
    struct bmpimg *img = malloc(sizeof(struct bmpimg));
    img->name = imgname;
    img->height = height;
    img->width = width;
    img->size = (sizeof(char) * height * width * 24) + 54;
}

void freebmpimg(struct bmpimg *img) {
    free(img);
}

void genbmpimg(struct bmpimg *img) {
    if(!(img->height > 0 && img->width > 0 && img->size > 0)) {
        fprintf(stderr, "Error : the bmp is not initialized");
        return;
    }

    FILE *file = NULL;
    file = fopen(img->name, "ab+");
    
    if(file == NULL) {
        fprintf(stderr, "Error while creating the file");
        return;
    }
    
    char sign1 = 'B';
    char sign2 = 'M';
    int zeroi = 0;
    short zero = 0;
    short one = 1;
    int offset = 54;
    int bmpinfosize = 40;
    short bitsperpix = 24;
    int imgsize = img->size - 54;
   
    int hres = 1080;
    int vres = 1920;

    // BMP Header
    fwrite(&sign1, sizeof(char), 1, file);          //B
    fwrite(&sign2, sizeof(char), 1, file);          //M
    fwrite(&(img->size), sizeof(int), 1, file);     //File size
    fwrite(&zero, sizeof(short), 1, file);          //reserved (0)
    fwrite(&zero, sizeof(short), 1, file);          //reserved (0)
    fwrite(&offset, sizeof(int), 1, file);          //offset (54)
    // BMP Info
    fwrite(&bmpinfosize, sizeof(int), 1, file);     //bitmapinfo size (40)
    fwrite(&(img->width), sizeof(int), 1, file);    //width
    fwrite(&(img->height), sizeof(int), 1, file);   //height
    fwrite(&one, sizeof(short), 1, file);           //number of plans (1)
    fwrite(&bitsperpix, sizeof(short), 1, file);    //bits per pixels (24)
    fwrite(&zeroi, sizeof(int), 1, file);           //not compressed
    fwrite(&(imgsize), sizeof(int), 1, file);       //image size
    fwrite(&vres, sizeof(int), 1, file);            //horizontal resolution
    fwrite(&hres, sizeof(int), 1, file);            //vertical resolution
    fwrite(&zeroi, sizeof(int), 1, file);           // 0
    fwrite(&zeroi, sizeof(int), 1, file);           // 0

    int color = 255;
    int black = 0;

    srand(time(NULL));
    
    // Writing random image
    for(int i = 0; i < img->height * img->width * 24; i++) {
        int r = rand() % 256;
        fwrite(&r, sizeof(char), 1, file);
    }

    fclose(file);
}
