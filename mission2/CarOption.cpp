#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "CarOption.h"
using namespace std;

void
carOption::setOption(int option)
{
    numOption = option;
    printSelectedOption();
}

int
carOption::getOption()
{
    return numOption;
}