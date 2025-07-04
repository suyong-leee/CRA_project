#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "CarOption.h"
#include "CarBrakeSystem.h"
using namespace std;

string
carBrakeSystem::returnOption()
{
    if (numOption == MANDO)
        return "MANDO";
    if (numOption == CONTINENTAL)
        return "CONTINENTAL";
    if (numOption == BOSCH_B)
        return "BOSCH";
}

bool
carBrakeSystem::checkValidInput(int input)
{
    if (input >= 1 && input < Num_BrakeSystem)
    {
        return true;
    }
    printf("ERROR :: 제동장치는 1 ~ %d 범위만 선택 가능\n", (Num_BrakeSystem - 1));
    return false;
}
#ifndef _DEBUG
void
carBrakeSystem::printQuestion()
{
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}
#endif

void
carBrakeSystem::printSelectedOption()
{
    printf("%s 제동장치를 선택하셨습니다.\n", returnOption());
}