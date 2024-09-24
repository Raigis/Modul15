/*
С клавиатуры вводятся числа.
Когда пользователь вводит «−1», необходимо выводить на экран пятое по возрастанию число среди введённых.
Когда пользователь вводит «−2», программа завершает работу.
*/

#include <iostream>
#include <vector>

void print_error () {
    std::cout << "Введено меньше 5-ти чисел.";
}

void print_back (std::vector<int> &input) {
    std::cout << "Пятое по возрастанию введённое число: " << input[4] <<".";
}

void insertion (std::vector<int> &input, int &enter) {
    if (input.size() == 0 || (input.size() < 5 && enter >= input[input.size()-1])) {
        input.push_back(enter);
    } else if (input.size() == 1) {
        input.push_back(input[0]);
        input[0] = enter;
    } else {
        for (int i = 0, y = i + 1; y <= input.size(); i++, y++) {
            if (enter >= input[i] && enter < input[y]) {
                if (input.size() == 5) input.pop_back();
                auto pos = input.begin();
                input.insert(std::next(pos, y), enter);
                break;
            } 
        }
    }
}

void check (std::vector<int> &input, int &enter) {
    if (input.size() != 5 && enter == -1) {
        print_error();
    } else if (enter == -1) {
        print_back(input);
    } else {
        insertion(input, enter);
    }
}

int main () {
    std::vector<int> input;
    int enter;
    do {
        std::cout << "Введите число: ";
        std::cin >> enter;
        if (enter != -2) {
            check(input, enter);
        }
    } while (enter != -2);

    return 0;
}