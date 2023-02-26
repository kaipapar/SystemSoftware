

#include <stdio.h>

int main() {
    // declare and initialize an array with char and int elements
    char arr[] = {'a', 1, 'b', 2, 'c', 3};
    int len = sizeof(arr) / sizeof(arr[0]);  // get the length of the array

    for (int i = 0; i < len; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            printf("%d ", arr[i] - '0');  // convert char to int and print
        } else {
            printf("%c ", arr[i]);  // print character element
        }
    }

    return 0;
}
