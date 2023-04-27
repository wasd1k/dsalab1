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

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}


int main() {
  int numIt = 0;
  uint32_t sizeOfArray = 50000;
  for (; sizeOfArray <= 1000000; sizeOfArray += 50000) {

    uint32_t array[sizeOfArray];
    for (int i = 0; i < sizeOfArray; i++) {
      array[i] = getrand(0, 100000);
    }
    int n = sizeof(array) / sizeof(array[0]);
    double time = wtime();
    bubbleSort(array, n);
    printf("%f\n", wtime() - time);
  }
  return 0;
}
