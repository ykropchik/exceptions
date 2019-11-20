//
// Created by YKROPCHIK on 16.11.2019.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int length(char input[]){
    int size = 0;

    while(input[size] != '\0'){
        size++;
    }

    return size;
}

bool isNumber(char input[]){
    for(int i = 0; i < length(input); i++){
        if (!isdigit(input[i])){
            return false;
        }
    }
    return true;
}

void connectFile(ifstream &inputFile, const string addressFile) {
    inputFile.open(addressFile);

    if (!inputFile.is_open()){
        throw invalid_argument("Файл не существует!");
    }
}

void readNumbers(ifstream &inputFile, int result[]){
    char c;
    inputFile.get(c);
    if (inputFile.eof()){
        throw runtime_error("Файл пуст!");
    }

    char* firstString = new char[50];
    char* secondString = new char[50];

    inputFile.seekg(0, ios_base::beg);
    inputFile >> firstString >> secondString;

    if (length(secondString) == 0){
        throw invalid_argument("Одна из строк пустая!");
    } else {
        if (isNumber(firstString)) {
            result[0] = atoi(firstString);
        } else {
            throw invalid_argument("В первой строке нет числа!");
        }

        if (isNumber(secondString)) {
            result[1] = atoi(secondString);
        } else {
            throw invalid_argument("Во второй строке нет числа!");
        }
    }
}

