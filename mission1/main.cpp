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
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"

int carOption[10];

void selectCarType(int answer);
void printCarType(int answer);
void selectEngine(int answer);
void printEngine(int answer);
void selectBrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);

void printSelectQuestion(int step);

bool checkValidInput(int step, int answer);

void getInput(char  inputData[100]);

bool isNumber(char* checkNumber);

bool isOnlyChangeStep(int answer, int& step);


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
            printf("���̹���\n");
            break;
        }

        char* checkNumber;
        int answer = strtol(inputData, &checkNumber, 10);

        if (isNumber(checkNumber) == false) continue;

        if (checkValidInput(step, answer) == false) continue;

        if (isOnlyChangeStep(answer, step) == true) continue;


        if (step == Run_Test)
        {
            if (answer == 1)
            {
                runProducedCar();
            }
            else if (answer == 2)
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
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void printEngineQuestion()
{
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
}

void printBrakeSystemQuestion()
{
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void printSteeringSystemQuestion()
{
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void printRunTestQuestion()
{
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
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
    if (step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == BrakeSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        delay(800);
        return false;
    }

    return true;
}

void getInput(char  inputData[100])
{
    fgets(inputData, sizeof(inputData), stdin);

    // ���� ���๮�� ����
    char* context = nullptr;
    strtok_s(inputData, "\r", &context);
    strtok_s(inputData, "\n", &context);
}


bool isNumber(char* checkNumber)
{
    // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        delay(800);
        return false;
    }
    return true;
}

bool isOnlyChangeStep(int answer, int& step)
{
    // ó������ ���ư���
    if (answer == 0 && step == Run_Test)
    {
        step = CarType_Q;
        return true;
    }

    // �������� ���ư���
    if (answer == 0 && step >= 1)
    {
        step -= 1;
        return true;
    }
    return false;
}

void selectCarType(int answer)
{
    carOption[CarType_Q] = answer;
    printCarType(answer);
}

void printCarType(int answer)
{
    printf("���� Ÿ������ ");
    if (answer == 1)
        printf("Sedan");
    if (answer == 2)
        printf("SUV");
    if (answer == 3)
        printf("Truck");
    printf("�� �����ϼ̽��ϴ�.\n");
}

void selectEngine(int answer)
{
    carOption[Engine_Q] = answer;
    printEngine(answer);
}

void printEngine(int answer)
{
    if (answer == 1)
        printf("GM");
    if (answer == 2)
        printf("TOYOTA");
    if (answer == 3)
        printf("WIA");
    if (answer != 4)
        printf(" ������ �����ϼ̽��ϴ�.\n");
}

void selectBrakeSystem(int answer)
{
    carOption[BrakeSystem_Q] = answer;
    if (answer == 1)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == 2)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == 3)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void selectSteeringSystem(int answer)
{
    carOption[SteeringSystem_Q] = answer;
    if (answer == 1)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == 2)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (carOption[Engine_Q] == 4)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            if (carOption[CarType_Q] == 1)
                printf("Car Type : Sedan\n");
            if (carOption[CarType_Q] == 2)
                printf("Car Type : SUV\n");
            if (carOption[CarType_Q] == 3)
                printf("Car Type : Truck\n");
            if (carOption[Engine_Q] == 1)
                printf("Engine : GM\n");
            if (carOption[Engine_Q] == 2)
                printf("Engine : TOYOTA\n");
            if (carOption[Engine_Q] == 3)
                printf("Engine : WIA\n");
            if (carOption[BrakeSystem_Q] == 1)
                printf("Brake System : Mando\n");
            if (carOption[BrakeSystem_Q] == 2)
                printf("Brake System : Continental\n");
            if (carOption[BrakeSystem_Q] == 3)
                printf("Brake System : Bosch\n");
            if (carOption[SteeringSystem_Q] == 1)
                printf("SteeringSystem : Bosch\n");
            if (carOption[SteeringSystem_Q] == 2)
                printf("SteeringSystem : Mobis\n");

            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (carOption[CarType_Q] == SEDAN && carOption[BrakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (carOption[CarType_Q] == SUV && carOption[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (carOption[CarType_Q] == TRUCK && carOption[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (carOption[CarType_Q] == TRUCK && carOption[BrakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (carOption[BrakeSystem_Q] == BOSCH_B && carOption[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}

#endif