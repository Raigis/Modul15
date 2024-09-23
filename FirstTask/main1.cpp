/*
Вам даётся массив целых чисел.
Необходимо найти в массиве такие два индекса i и j, что сумма a[i], a[i+1], a[i+2], …, a[j] будет максимально возможной, и вывести их.
*/

#include <iostream>

int main () {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max = a[0] + a[1];
    int start = 0, end = 1;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]) - 1; i++) {
        int sum = a[i];
        for (int y = i + 1; y < sizeof(a)/sizeof(a[0]); y++) {
            sum += a[y];
            if (sum > max) {
                max = sum;
                start = i;
                end = y;
            }
        }
    }
    std::cout << "Максимально возможная сумма элементов массива: " << max << ".\n"
              << "Были сложены элементы с " << start << " по " << end << ": ";
    for (int i = start; i <= end; i++) std::cout << a[i] << " ";
}