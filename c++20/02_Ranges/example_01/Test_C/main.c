#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int size = 1000000;
    int* numbers = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) numbers[i] = i;

    // Simulated "range-based" approach (in C we have to do it manually)
    clock_t t1 = clock();
    int* result1 = (int*)malloc(size * sizeof(int));
    int count1 = 0;
    for (int i = 0; i < size; ++i) {
        if (numbers[i] % 2 == 0) {
            result1[count1++] = numbers[i] * numbers[i];
        }
    }
    // Resize to actual count
    result1 = (int*)realloc(result1, count1 * sizeof(int));
    clock_t t2 = clock();

    // Traditional loop
    clock_t t3 = clock();
    int* result2 = (int*)malloc(size * sizeof(int));
    int count2 = 0;
    for (int i = 0; i < size; ++i) {
        if (numbers[i] % 2 == 0) {
            result2[count2++] = numbers[i] * numbers[i];
        }
    }
    // Resize to actual count
    result2 = (int*)realloc(result2, count2 * sizeof(int));
    clock_t t4 = clock();

    double range_time = (double)(t2 - t1) / CLOCKS_PER_SEC * 1000000;
    double loop_time = (double)(t4 - t3) / CLOCKS_PER_SEC * 1000000;

    printf("Simulated range-based: %.0f μs\n", range_time);
    printf("Traditional loop: %.0f μs\n", loop_time);

    free(numbers);
    free(result1);
    free(result2);

    return 0;
}
