#include <math.h>
#include "settings.h"


void dft_idft_2d(Complex converted[SIZE][SIZE], Complex original[SIZE][SIZE], transMode m) {
    int x, y, u, v;   /* for文用変数 */

    Complex t[SIZE][SIZE] = {0, 0};

    // x方向の1D-DFT
    for (y = 0; y < SIZE; y++) {
        for (u = 0; u < SIZE; u++) {
            for (x = 0; x < SIZE; x++) {
                t[y][u].r += original[y][x].r * cos(2 * PI * u * x / (double)SIZE) + (m == DFT ? 1 : -1) * original[y][x].i * sin(2 * PI * u * x / (double)SIZE);
                t[y][u].i += original[y][x].i * cos(2 * PI * u * x / (double)SIZE) - (m == DFT ? 1 : -1) * original[y][x].r * sin(2 * PI * u * x / (double)SIZE);
            }
            
        }
    }

    // y方向の1D-DFT
    for (u = 0; u < SIZE; u++) {
        for (v = 0; v < SIZE; v++) {
            for (y = 0; y < SIZE; y++) {
                converted[v][u].r += t[y][u].r * cos(2 * PI * v * y / (double)SIZE) + (m == DFT ? 1 : -1) * t[y][u].i * sin(2 * PI * v * y / (double)SIZE);
                converted[v][u].i += t[y][u].i * cos(2 * PI * v * y / (double)SIZE) - (m == DFT ? 1 : -1) * t[y][u].r * sin(2 * PI * v * y / (double)SIZE);
            }
        }
    }
    
    if (m == IDFT) {
        double n = SIZE * SIZE;
        for (x = 0; x < SIZE; x++) {
            for (y = 0; y < SIZE; y++) {
                converted[x][y].r /= n;
                converted[x][y].i /= n;
            }
        }
    }
}
