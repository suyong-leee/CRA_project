#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "CarOption.h"
#include "CarType.h"
using namespace std;

string
carType::returnOption()
{
    if (numOption == SEDAN)
        return "Sedan";
    if (numOption == SUV)
        return "SUV";
    if (numOption == TRUCK)
        return "Truck";
}

bool 
carType::checkValidInput(int input)
{
    if (input >= 1 && input < Num_CarType)
    {
        return true;
    }
    printf("ERROR :: 차량 타입은 1 ~ %d 범위만 선택 가능\n", (Num_CarType-1));
    return false;
}
#ifndef _DEBUG
void 
carType::printQuestion()
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
#endif

void 
carType::printSelectedOption()
{
    printf("차량 타입으로 %s", returnOption());
    printf("을 선택하셨습니다.\n");
}