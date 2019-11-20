//
// Created by YKROPCHIK on 16.11.2019.
//

#include "gtest/gtest.h"
#include "lib.h"

using namespace std;

TEST(connectFile, expectedResult){
    int* numbers = new int[2];

    ifstream noExist;
    ifstream inEmpty("../emptyFile.txt");
    ifstream inNoNum("../noNumber.txt");
    ifstream inValid("../validFile.txt");

    EXPECT_THROW(connectFile(noExist, "../randomName"), invalid_argument);
    EXPECT_THROW(readNumbers(inEmpty, numbers), runtime_error);
    EXPECT_THROW(readNumbers(inNoNum, numbers), invalid_argument);

    readNumbers(inValid, numbers);
    EXPECT_EQ(numbers[0], 65);
    EXPECT_EQ(numbers[1], 5);
}

TEST(devision, expectedResult){
    int* numbers = new int[2];
    int result = 0;

    numbers[0] = 5;
    numbers[1] = 5;
    result = divisionNumbers(numbers);
    EXPECT_EQ(result, 1);

    numbers[0] = 49;
    numbers[1] = 7;
    result = divisionNumbers(numbers);
    EXPECT_EQ(result, 7);

    numbers[0] = 321;
    numbers[1] = 0;
    EXPECT_THROW(divisionNumbers(numbers), domain_error);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
