
/*
 * week4_1_dynamic_array.c
 * Author: Yagiz Sen
 * Description:
 *   Creates a dynamic array, reads integers,
 *   calculates sum and average, and frees memory.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int* arr = NULL;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  // Check that the allocation size is safe.
  if ((size_t)n > SIZE_MAX / sizeof(int)) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Allocate memory for the integers.
  arr = malloc((size_t)n * sizeof(int));

  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  long long sum = 0;

  printf("Enter %d integers: ", n);

  // Read the integers and calculate their sum.
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }

    sum += arr[i];
  }

  // Use floating point division for the average.
  double average = (double)sum / n;

  printf("Sum = %lld\n", sum);
  printf("Average = %.2f\n", average);

  // Release dynamically allocated memory.
  free(arr);

  return 0;
}
