#include <stdio.h>
#include <iostream>

int main() {
    int arr[5] = { 0, };
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &arr[i]);
    }

    int min, max, sum;
    min = max = sum = arr[0];

    for (int i = 1; i < 5; ++i) {
        min = min < arr[i] ? min : arr[i];
        max = max > arr[i] ? max : arr[i];
        sum += arr[i];
    }

    std::cout 
        << "min: " << min << std::endl
        << "max: " << max << std::endl
        << "sum: " << sum << std::endl; 
}
