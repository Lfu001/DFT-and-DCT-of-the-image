#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dft_idft_2d.h"
#include "dct_2d.h"


int main() {
    int x, y, u, v;               /* for文用変数 */
    Complex f[SIZE][SIZE];        /* 処理する入力画像 */
    Complex g[SIZE][SIZE];        /* 処理する出力画像 */
    unsigned char f1[SIZE][SIZE]; /* 入力画像 */
    unsigned char g1[SIZE][SIZE]; /* 出力画像 */
    FILE *fp1, *fp2;


    if ((fp1 = fopen("source/frog.raw", "rb")) == NULL) {
        printf("Failed to load file.");
        exit(EXIT_FAILURE);
    };
    fread(f1, 1, SIZE * SIZE, fp1);
    fclose(fp1);

    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            f[x][y].r = (double)f1[x][y];
            f[x][y].i = 0.0;
            g[x][y] = (Complex){0, 0};
        }
    }

    // 離散フーリエ変換
    dft_idft_2d(g, f, DFT);

    // パワースペクトル
    double p[SIZE][SIZE];
    for (u = 0; u < SIZE; u++) {
        for (v = 0; v < SIZE; v++) {
            g1[(u + 128) % SIZE][(v + 128) % SIZE] = (p[u][v] = 18.2 * log10(1 + (g[u][v].r)*(g[u][v].r) + (g[u][v].i)*(g[u][v].i))) > 255 ? 255 : (unsigned char)p[u][v];
        }
    }
    if ((fp2 = fopen("frog_dft_power_spectrum.raw", "wb")) == NULL) {
        printf("Failed to open file.");
        exit(EXIT_FAILURE);
    }
    fwrite(g1, sizeof(unsigned char), SIZE * SIZE, fp2);
    fclose(fp2);

    // 離散コサイン変換
    dct_2d(g, f);

    // パワースペクトル
    for (u = 0; u < SIZE; u++) {
        for (v = 0; v < SIZE; v++) {
            g1[u][v] = (p[u][v] = 18.2 * log10(1 + (g[u][v].r)*(g[u][v].r) + (g[u][v].i)*(g[u][v].i))) > 255 ? 255 : (unsigned char)p[u][v];
        }
    }
    if ((fp2 = fopen("frog_dct_power_spectrum.raw", "wb")) == NULL) {
        printf("Failed to open file.");
        exit(EXIT_FAILURE);
    }
    fwrite(g1, sizeof(unsigned char), SIZE * SIZE, fp2);
    fclose(fp2);
}
