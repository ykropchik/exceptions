//
// Created by YKROPCHIK on 16.11.2019.
//
#include <iostream>

using namespace std;

int divisionNumbers(int numbers[]){
    if (numbers[1] == 0){
        throw domain_error("Произошло деление на ноль!");
    }

    return numbers[0]/numbers[1];
}