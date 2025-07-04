#include "CarOption.h"

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

using namespace std;
#define CLEAR_SCREEN "\033[H\033[2J"

int carOption[10];

void selectCarType(int answer);
string returnCarType(int answer);
string returnEngine(int answer);
string returnBrakeSystem(int answer);
string returnSteeringSystem(int answer);
void selectEngine(int answer);
void selectBrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);

void printSelectQuestion(int step);

bool checkValidInput(int step, int answer);

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

    while (1)
    {
        printSelectQuestion(step);
        getInput(inputData);

        if (!strcmp(inputData, "exit"))
        {
            printf("바이바이\n");
            break;
        }

        char* checkNumber;
        int answer = strtol(inputData, &checkNumber, 10);

        if (isNumber(checkNumber) == false) continue;

        if (checkValidInput(step, answer) == false) continue;

        if (isOnlyChangeStep(step, answer) == true) continue;


        if (step == Run_Test)
        {
            if (answer == RunCar)
            {
                runProducedCar();
            }
            else if (answer == CarTest)
            {
                printf("Test...\n");
                delay(1500);
                testProducedCar();
            }
            delay(2000);
        }
        else
        {
            if (step == CarType_Q)
            {
                selectCarType(answer);
            }
            else if (step == Engine_Q)
            {
                selectEngine(answer);
            }
            else if (step == BrakeSystem_Q)
            {
                selectBrakeSystem(answer);
            }
            else if (step == SteeringSystem_Q)
            {
                selectSteeringSystem(answer);
            }
            delay(800);
            step++;
        }
    }
}


void printCarTypeQuestion()
{
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void printEngineQuestion()
{
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}

void printBrakeSystemQuestion()
{
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void printSteeringSystemQuestion()
{
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

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
    if (step == CarType_Q)
    {
        printCarTypeQuestion();
    }
    else if (step == Engine_Q)
    {
        printEngineQuestion();
    }
    else if (step == BrakeSystem_Q)
    {
        printBrakeSystemQuestion();
    }
    else if (step == SteeringSystem_Q)
    {
        printSteeringSystemQuestion();
    }
    else if (step == Run_Test)
    {
        printRunTestQuestion();
    }
    printf("===============================\n");

    printf("INPUT > ");
}

bool checkValidInput(int step, int answer)
{
    if (step == CarType_Q && !(answer >= 1 && answer < Num_CarType))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == Engine_Q && !(answer >= 0 && answer < Num_Engine))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == BrakeSystem_Q && !(answer >= 0 && answer < Num_BrakeSystem))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer < Num_SteeringSystem))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == Run_Test && !(answer >= 0 && answer <= CarTest))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return false;
    }

    return true;
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

string returnCarType(int answer)
{
    if (answer == SEDAN)
        return "Sedan";
    if (answer == SUV)
        return "SUV";
    if (answer == TRUCK)
        return "Truck";
}
string returnEngine(int answer)
{
    if (answer == GM)
        return "GM";
    if (answer == TOYOTA)
        return "TOYOTA";
    if (answer == WIA)
        return "WIA";
    if (answer == Broken)
        return "Broken";
}
string returnBrakeSystem(int answer)
{
    if (answer == MANDO)
        return "MANDO";
    if (answer == CONTINENTAL)
        return "CONTINENTAL";
    if (answer == BOSCH_B)
        return "BOSCH";
}
string returnSteeringSystem(int answer)
{
    if (answer == BOSCH_S)
        return "BOSCH";
    if (answer == MOBIS)
        return "MOBIS";
}


void selectCarType(int answer)
{
    carOption[CarType_Q] = answer;
    printf("차량 타입으로 %s", returnCarType(answer));
    printf("을 선택하셨습니다.\n");
}

void selectEngine(int answer)
{
    carOption[Engine_Q] = answer;
    if (answer != Broken)
        printf("%s 엔진을 선택하셨습니다.\n",returnEngine(answer));
}

void selectBrakeSystem(int answer)
{
    carOption[BrakeSystem_Q] = answer;
    printf("%s 제동장치를 선택하셨습니다.\n",returnBrakeSystem(answer));
}

void selectSteeringSystem(int answer)
{
    carOption[SteeringSystem_Q] = answer;
    printf("%s 조향장치를 선택하셨습니다.\n",returnSteeringSystem(answer));
}

int isValidCheck()
{
    if (carOption[CarType_Q] == SEDAN && carOption[BrakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (carOption[CarType_Q] == SUV && carOption[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (carOption[CarType_Q] == TRUCK && carOption[Engine_Q] == WIA)
    {
        return false;
    }
    else if (carOption[CarType_Q] == TRUCK && carOption[BrakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (carOption[BrakeSystem_Q] == BOSCH_B && carOption[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (carOption[Engine_Q] == Broken)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            printf("Car Type : %s\n", returnCarType(carOption[CarType_Q]));
            printf("Engine : %s\n", returnCarType(carOption[Engine_Q]));
            printf("Brake System : %s\n", returnCarType(carOption[BrakeSystem_Q]));
            printf("SteeringSystem : %s\n", returnCarType(carOption[SteeringSystem_Q]));
            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (carOption[CarType_Q] == SEDAN && carOption[BrakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (carOption[CarType_Q] == SUV && carOption[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (carOption[CarType_Q] == TRUCK && carOption[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (carOption[CarType_Q] == TRUCK && carOption[BrakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (carOption[BrakeSystem_Q] == BOSCH_B && carOption[SteeringSystem_Q] != BOSCH_S)
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