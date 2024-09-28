/*
Вам даётся массив целых чисел.
Необходимо найти в массиве такие два индекса i и j, что сумма a[i], a[i+1], a[i+2], …, a[j] будет максимально возможной, и вывести их.
*/

#include <iostream>

int main () {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max = a[0] + a[1];
    int start = 0, end = 1;
    int size = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < size - 1; i++) {
        int sum = a[i];
        for (int y = i + 1; y < size; y++) {
            sum += a[y];
            if (sum > max) {
                max = sum;
                start = i;
                end = y;
            }
        }
    }

    std::cout << "Array:\n";
    for (int i : a) std::cout << i << " ";
    std::cout << "\nThe maximum possible sum of the array elements: " << max << ".\n"
              << "The elements were stacked from " << start << " to " << end << ": ";
    for (int i = start; i <= end; i++) std::cout << a[i] << " ";
}