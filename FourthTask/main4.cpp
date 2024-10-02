/*
Вам даётся массив целых чисел, отсортированных по возрастанию. 
Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел.
*/

#include <iostream>

int main () {
    int array[] = {-8, -7, -6, -5, 1, 10, 15};
    int min = array[0] < 0 ? array[0] * -1 : array[0], minInd = 0;
    int size = sizeof(array)/sizeof(array[0]);
    for (int i = 1; i < size; i++) {
        int temp = array[i] < 0 ? array[i] * -1 : array[i];
        if (temp < min) {
            min = temp;
            minInd = i;
        }
    }
    std::cout << "Initial sorting:\n";
    for (int i : array) std::cout << i << " ";
    std::cout << "\nSorting in ascending order of the module value:\n";
    std::cout << array[minInd] << " ";

    bool begin = false, end = false;
    for (int i = minInd - 1, y = minInd + 1; i >= 0 || y < size;){
        if ((!begin && -array[i == -1 ? i = 0 : i] <= array[y == size ? size - 1 : y]) || end) {
            if (!begin && i == 0) begin = true;
            std::cout << array[i--] << " ";
        } else {
            if (!end && y == size - 1) end = true;
            std::cout << array[y++] << " ";
        }
    }

    return 0;
}