#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "CarOption.h"
#include "CarSteeringSystem.h"
using namespace std;

string
carSteeringSystem::returnOption()
{
    if (numOption == BOSCH_S)
        return "BOSCH";
    if (numOption == MOBIS)
        return "MOBIS";
}

bool
carSteeringSystem::checkValidInput(int input)
{
    if (input >= 1 && input < Num_SteeringSystem)
    {
        return true;
    }
    printf("ERROR :: 조향장치는 1 ~ %d 범위만 선택 가능\n", (Num_SteeringSystem - 1));
    return false;
}
#ifndef _DEBUG
void
carSteeringSystem::printQuestion()
{
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}
#endif

void
carSteeringSystem::printSelectedOption()
{
    printf("%s 조향장치를 선택하셨습니다.\n", returnOption());
}