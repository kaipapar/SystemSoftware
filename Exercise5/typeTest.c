#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array(int arr[], int length) {
    int i;
    srand(time(NULL));  // initialize random number generator with current time
    for (i = 0; i < length; i++) {
        arr[i] = rand() % 1000000;  // generate a random number between 0 and 999999
    }
}

int main() {
    int arr[10] = {0};  // create an empty array of size 10
    int i;

    fill_array(arr, 10);  // fill the array with random numbers

    printf("The array is: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);  // print the array
    }
    printf("\n");

    return 0;
}
