#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int getrand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void countingSort(uint32_t array[], uint32_t size) {
  uint32_t *output = calloc(size, sizeof(uint32_t));

  uint32_t max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  uint32_t count[max + 1];

  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

int main() {
  uint32_t sizeOfArray = 1000000;

  uint32_t array[sizeOfArray];
  for (int i = 0; i < sizeOfArray; i++) {
    array[i] = getrand(0, 100000);
  }
  uint32_t n = sizeof(array) / sizeof(array[0]);
  double time = wtime();
  countingSort(array, n);
  printf("%f\n", wtime() - time);
}
