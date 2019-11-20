#include <iostream>
#include <fstream>
#include <lib.h>

using namespace std;

const string FILE_ADDRESS = "../input.txt";
int* numbers = new int[2];
int answer(0);
ifstream inputFile;

int main() {
    try{
        connectFile(inputFile, FILE_ADDRESS);
        readNumbers(inputFile, numbers);
        answer = divisionNumbers(numbers);
        cout << "Ответ: " << answer;

    } catch (invalid_argument &err) {
        cout << "Ошибка! " << err.what();
    } catch (runtime_error &err){
        cout << "Ошибка! " << err.what();
    } catch (domain_error &err){
        cout << "Ошибка! " << err.what();
    }

    delete [] numbers;
    inputFile.close();
    return 0;
}
