#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "CarOption.h"
#include "CarEngine.h"
using namespace std;

string
carEngine::returnOption()
{
    if (numOption == GM)
        return "GM";
    if (numOption == TOYOTA)
        return "TOYOTA";
    if (numOption == WIA)
        return "WIA";
    if (numOption == Broken)
        return "Broken";
}

bool
carEngine::checkValidInput(int input)
{
    if (input >= 1 && input < Num_Engine)
    {
        return true;
    }
    printf("ERROR :: 엔진은 1 ~ %d 범위만 선택 가능\n", (Num_Engine - 1));
    return false;
}
#ifndef _DEBUG
void
carEngine::printQuestion()
{
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}
#endif

void
carEngine::printSelectedOption()
{
    if (numOption != Broken)
        printf("%s 엔진을 선택하셨습니다.\n", returnOption());
}
