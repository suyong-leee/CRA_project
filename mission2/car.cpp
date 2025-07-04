#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "CarOption.h"
#include "CarType.h"
#include "CarEngine.h"
#include "CarBrakeSystem.h"
#include "CarSteeringSystem.h"
using namespace std;

class car
{
#define CLEAR_SCREEN "\033[H\033[2J"
public:
    carOption* option[NumOption];
    car()
    {
        option[CarType_Q] = new carType;
        option[Engine_Q] = new carEngine;
        option[BrakeSystem_Q] = new carBrakeSystem;
        option[SteeringSystem_Q] = new carSteeringSystem;
    }
#ifndef _DEBUG
    void printRunTestQuestion()
    {
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }

    void printSelectQuestion(int step)
    {
        printf(CLEAR_SCREEN);
        if (step == Run_Test)
        {
            printRunTestQuestion();
        }
        else
        {
            option[step]->printQuestion();
        }
        printf("===============================\n");
        printf("INPUT > ");
    }
#endif
    bool checkValidInput(int step, int answer)
    {
        if (step == Run_Test)
        {
            if (answer >= 0 && answer <= CarTest) return true;
            else
            {
                printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
                return false;
            }
        }
        return option[step]->checkValidInput(answer);
    }

    void selectOption(int step, int answer)
    {
        option[step]->setOption(answer);
    }

    void runProducedCar()
    {
        if (isValidCheck() != NoError)printf("자동차가 동작되지 않습니다\n");
        else
        {
            if (option[Engine_Q]->getOption() == Broken)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                printf("Car Type : %s\n", option[CarType_Q]->returnOption());
                printf("Engine : %s\n", option[Engine_Q]->returnOption());
                printf("Brake System : %s\n", option[BrakeSystem_Q]->returnOption());
                printf("SteeringSystem : %s\n", option[SteeringSystem_Q]->returnOption());
                printf("자동차가 동작됩니다.\n");
            }
        }
    }
#ifndef _DEBUG
    void testProducedCar()
    {
        int checkResult = isValidCheck();
        if (checkResult == Error1)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
        }
        else if (checkResult == Error2)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
        }
        else if (checkResult == Error3)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        else if (checkResult == Error4)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
        }
        else if (checkResult == Error5)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    }
#endif

    int isValidCheck()
    {
        if (option[CarType_Q]->getOption() == SEDAN && option[BrakeSystem_Q]->getOption() == CONTINENTAL)return Error1;
        else if (option[CarType_Q]->getOption() == SUV && option[Engine_Q]->getOption() == TOYOTA)return Error2;
        else if (option[CarType_Q]->getOption() == TRUCK && option[Engine_Q]->getOption() == WIA)return Error3;
        else if (option[CarType_Q]->getOption() == TRUCK && option[BrakeSystem_Q]->getOption() == MANDO)return Error4;
        else if (option[BrakeSystem_Q]->getOption() == BOSCH_B && option[SteeringSystem_Q]->getOption() != BOSCH_S)return Error5;
        else return NoError;
    }
};