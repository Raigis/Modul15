/*
С клавиатуры вводятся числа.
Когда пользователь вводит «−1», необходимо выводить на экран пятое по возрастанию число среди введённых.
Когда пользователь вводит «−2», программа завершает работу.
*/

#include <iostream>
#include <vector>

void print_error (int code) {
    switch (code) {
    case 1: 
        std::cout << "\nFewer than 5 numbers have been entered.\n\n";
        break;
    case 2:
        std::cout << "\nIncorrect input.\n\n";
    }
}

void print_back (std::vector<int> &input) {
    std::cout << "\nThe fifth highest number entered: " << input[4] <<".\n\n";
}

void insertion (std::vector<int> &input, int &enter) {
    if (input.size() == 0 || (input.size() < 5 && enter >= input[input.size()-1])) {
        input.push_back(enter);
    } else if (input.size() == 1) {
        input.push_back(input[0]);
        input[0] = enter;
    } else {
        for (int i = 0; i <= input.size(); i++) {
            if (enter <= input[i]) {
                if (input.size() == 5) input.pop_back();
                input.insert(std::next(input.begin(), i), enter);
                break;
            } 
        }
    }
}

void conversion (std::vector<int> &input, std::string &enter) {
    int en;
    for (int i = 0; i < enter.size(); i++) {
        if (enter[i] >= '0' && enter[i] <= '9'){
            en = i == 0 ? enter[i] - '0' : en * 10 + (enter[i] - '0');
        } else {
            print_error(2);
            return;
        }
    }
    insertion(input, en);
}

void check (std::vector<int> &input, std::string &enter) {
    if (input.size() != 5 && enter == "-1") {
        print_error(1);
    } else if (enter == "-1") {
        print_back(input);
    } else {
        conversion(input, enter);
    }
}

int main () {
    std::vector<int> input (5, 0);
    input.shrink_to_fit();
    input.clear();
    std::string enter;
    do {
        std::cout << "Enter a number: ";
        std::cin >> enter;
        if (enter != "-2") {
            check(input, enter);
        }
    } while (enter != "-2");

    std::cout << "The work of the program is completed";

    return 0;
}