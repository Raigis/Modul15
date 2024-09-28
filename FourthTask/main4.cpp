/*
Вам даётся массив целых чисел, отсортированных по возрастанию. 
Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел.
*/

#include <iostream>

int main () {
    int array[] = {-100, -50, -5, 1, 10, 15};
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

    for (int i = 1, y = 1, k = 1; k < size; k++) {
        int tempInd1 = minInd - i >= 0 ? minInd - i : 0;
        int tempInd2 = minInd + y < size ? minInd + y : size - 1;
        int temp1 = array[tempInd1] < 0 ? array[tempInd1] * -1 : array[tempInd1];
        int temp2 = array[tempInd2] < 0 ? array[tempInd2] * -1 : array[tempInd2];
        if (temp1 <= temp2 || minInd + y >= size) {
            std::cout << array[tempInd1] << " ";
            i++;
        } else if (temp1 > temp2 || minInd - i < 0) {
            std::cout << array[tempInd2] << " ";
            y++;
        }
        
    }

    return 0;
}