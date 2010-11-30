#include <stdio.h>
#include <stdlib.h>
#include "d3des.h"

int main() {
    char *key = "browsers";
    unsigned char data[16];
    int j;
    FILE *in, *out;

    deskey(key, EN0);
    
    in = fopen("challenge", "r");
    if (!in) {
        printf("failed opening challenge\n");
        exit(1);
    }
    fread(data, 1, 16, in);
    fclose(in);

    for (j=0; j<16; j += 8) {
        des(data+j, data+j);
    }

    out = fopen("out", "w+");
    if (!out) {
        printf("failed opening out\n");
        exit(1);
    }
    fwrite(data, 1, 16, out);
    fclose(out);

    return 0;
}

