#include "CarOption.h"
#include "CarType.h"
#include "CarEngine.h"
#include "CarBrakeSystem.h"
#include "CarSteeringSystem.h"
#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "car.cpp"

using namespace std;
void delay(int ms);

void getInput(char  inputData[100]);
bool isNumber(char* checkNumber);
bool isOnlyChangeStep(int& step, int answer);

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

int main()
{
    char inputData[100];
    int step = CarType_Q;
    car selectedCar;
    while (1)
    {

        selectedCar.printSelectQuestion(step);

        getInput(inputData);

        if (!strcmp(inputData, "exit"))
        {
            printf("바이바이\n");
            break;
        }

        char* checkNumber;
        int answer = strtol(inputData, &checkNumber, 10);

        if (isNumber(checkNumber) == false) continue;

        if (selectedCar.checkValidInput(step, answer) == false)
        {
            delay(800);
            continue;
        }

        if (isOnlyChangeStep(step, answer) == true) continue;


        if (step == Run_Test)
        {
            if (answer == RunCar)
            {
                selectedCar.runProducedCar();
            }
            else if (answer == CarTest)
            {
                printf("Test...\n");
                delay(1500);
                selectedCar.testProducedCar();
            }
            delay(2000);
        }
        else
        {
            selectedCar.selectOption(step, answer);
            delay(800);
            step++;
        }
    }
}

void getInput(char  inputData[100])
{
    fgets(inputData, sizeof(inputData), stdin);

    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(inputData, "\r", &context);
    strtok_s(inputData, "\n", &context);
}


bool isNumber(char* checkNumber)
{
    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay(800);
        return false;
    }
    return true;
}

bool isOnlyChangeStep(int& step, int answer)
{
    // 처음으로 돌아가기
    if (answer == 0 && step == Run_Test)
    {
        step = CarType_Q;
        return true;
    }

    // 이전으로 돌아가기
    if (answer == 0 && step >= 1)
    {
        step -= 1;
        return true;
    }
    return false;
}

#endif