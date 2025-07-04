
#pragma once

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK,
    Num_CarType
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    Broken,
    Num_Engine
};

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B,
    Num_BrakeSystem
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS,
    Num_SteeringSystem
};

enum RunTest
{
    RunCar = 1,
    CarTest
};