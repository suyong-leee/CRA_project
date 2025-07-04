#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

enum eQuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
    NumOption = Run_Test
};

enum eCarType
{
    SEDAN = 1,
    SUV,
    TRUCK,
    Num_CarType
};

enum eEngine
{
    GM = 1,
    TOYOTA,
    WIA,
    Broken,
    Num_Engine
};

enum eBrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B,
    Num_BrakeSystem
};

enum eSteeringSystem
{
    BOSCH_S = 1,
    MOBIS,
    Num_SteeringSystem
};

enum eRunTest
{
    RunCar = 1,
    CarTest
};

enum eErrorCode
{
    NoError,
    Error1,
    Error2,
    Error3,
    Error4,
    Error5
};

class carOption
{
public:
    void setOption(int option);
    int getOption();
    virtual string returnOption() = 0;
    virtual bool checkValidInput(int input) = 0;
#ifndef _DEBUG
    virtual void printQuestion() = 0;
#endif

protected:
    virtual void printSelectedOption() = 0;

    int numOption = 0;
};