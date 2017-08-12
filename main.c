#include <stdlib.h>
#include <stdio.h>

#include "include/bmpimg.h"

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage : %s <HEIGHT> <WIDTH> <IMGNAME.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct bmpimg *img = newbmpimg(argv[3], strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
    genbmpimg(img);
    freebmpimg(img);

    return 0;
}
