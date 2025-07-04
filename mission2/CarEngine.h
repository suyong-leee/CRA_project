#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "CarOption.h"
using namespace std;

class carEngine : public carOption
{
public:
    string returnOption() override;
    bool checkValidInput(int input) override;
#ifndef _DEBUG
    void printQuestion() override;
#endif
protected:
    void printSelectedOption() override;
};