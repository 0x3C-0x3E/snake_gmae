#include "util_random.h"

void rand_init() {
    srand((unsigned int)time(NULL));
}

int rand_range(int min, int max) {
    if (min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }

    unsigned int range = (unsigned int) (max - min + 1);

    unsigned int limit = RAND_MAX - (RAND_MAX % range);
    int r;
    do {
        r = rand();
    } while ((unsigned int) r >= limit);

    return min + (r % range);
}
