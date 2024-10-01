/*
Вам даётся массив целых чисел и одно число — результат.
Необходимо найти в массиве два числа, сумма которых будет давать результат, и вывести их на экран.
Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
*/

#include <iostream>

int main () {
    int a[] = {2, 7, 11, 15};
    int res = 9, first = 0, second;
    int size = sizeof(a)/sizeof(a[0]);
    for (second = first + 1; first < size - 1 || second < size; second++) {
        if (second == size) first++, second = first + 1;
        if (a[first] + a[second] == res) {
            std::cout << "Array:\n";
            for (int i : a) std::cout << i << " ";
            std::cout << "\nThe required result " << res << " is obtained by the sum of the elements " << a[first] << " and " << a[second] << ":\n"
                      << a[first] << " + " << a[second] << " = " << res;
            return 0;
        }
    }
    std::cout << "\nIt is impossible to get the required result from two elements of this array";
    return 0;
}