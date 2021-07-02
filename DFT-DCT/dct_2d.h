#include <math.h>
#include "settings.h"


void dct_2d(Complex converted[SIZE][SIZE], Complex original[SIZE][SIZE]) {
    int x, y, j, k, u, v;   /* for文用変数 */

    Complex t[SIZE][SIZE] = {0, 0};
    
    for (j = 0; j < SIZE; j += 8){
        for (k = 0; k < SIZE; k += 8) {
            for (u = 0; u < 8; u++) {
                for (v = 0; v < 8; v++) {
                    for (x = 0; x < 8; x++) {
                        for (y = 0; y < 8; y++) {
                            t[j + u][k + v].r += (u == 0 ? 1 / sqrt(2) : 1) * (v == 0 ? 1 / sqrt(2) : 1) / 4.0 * original[j + x][k + y].r * cos((2 * x + 1) * u * PI / 16.0) * cos((2 * y + 1) * v * PI / 16.0);
                        }
                    }
                }
            }
        }
    }

    for (j = 0; j < SIZE; j++) {
        for (k = 0; k < SIZE; k++) {
            converted[j][k] = (Complex){t[j][k].r, 0.0};
        }
    }

}
