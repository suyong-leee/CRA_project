#include "gmock/gmock.h"
#include "CarOption.h"
#include "CarType.h"
#include "CarEngine.h"
#include "CarBrakeSystem.h"
#include "CarSteeringSystem.h"
#include "car.cpp"
TEST(CarOption, CheckCarTypeValid)
{
	carType option;
	for (int i = 1; i < Num_CarType; i++)
	{
		EXPECT_EQ(true, option.checkValidInput(i));
	}
	EXPECT_EQ(false, option.checkValidInput(Num_CarType));
}

TEST(CarOption, SetCarType)
{
	carType option;
	option.setOption(1);
	EXPECT_EQ("Sedan", option.returnOption());
	option.setOption(2);
	EXPECT_EQ("SUV", option.returnOption());
	option.setOption(3);
	EXPECT_EQ("Truck", option.returnOption());
	for (int i = 1; i < Num_CarType; i++)
	{
		option.setOption(i);
		EXPECT_EQ(i, option.getOption());
	}
}

TEST(CarOption, CheckCarEngineValid)
{
	carEngine option;
	for (int i = 1; i < Num_Engine; i++)
	{
		EXPECT_EQ(true, option.checkValidInput(i));
	}
	EXPECT_EQ(false, option.checkValidInput(Num_Engine));
}

TEST(CarOption, SetCarEngine)
{
	carEngine option;
	option.setOption(1);
	EXPECT_EQ("GM", option.returnOption());
	option.setOption(2);
	EXPECT_EQ("TOYOTA", option.returnOption());
	option.setOption(3);
	EXPECT_EQ("WIA", option.returnOption());
	option.setOption(4);
	EXPECT_EQ("Broken", option.returnOption());
}

TEST(CarOption, CheckCarBrakeSystem)
{
	carBrakeSystem option;
	for (int i = 1; i < Num_BrakeSystem; i++)
	{
		EXPECT_EQ(true, option.checkValidInput(i));
	}
	EXPECT_EQ(false, option.checkValidInput(Num_BrakeSystem));
}

TEST(CarOption, SetCarBrakeSystem)
{
	carBrakeSystem option;
	option.setOption(1);
	EXPECT_EQ("MANDO", option.returnOption());
	option.setOption(2);
	EXPECT_EQ("CONTINENTAL", option.returnOption());
	option.setOption(3);
	EXPECT_EQ("BOSCH", option.returnOption());
}

TEST(CarOption, CheckCarSteeringSystem)
{
	carSteeringSystem option;
	for (int i = 1; i < Num_SteeringSystem; i++)
	{
		EXPECT_EQ(true, option.checkValidInput(i));
	}
	EXPECT_EQ(false, option.checkValidInput(Num_SteeringSystem));
}

TEST(CarOption, SetCarSteeringSystem)
{
	carSteeringSystem option;
	option.setOption(1);
	EXPECT_EQ("BOSCH", option.returnOption());
	option.setOption(2);
	EXPECT_EQ("MOBIS", option.returnOption());
}

TEST(CarClass, IntegratedCarTest)
{
	car selectedCar;
	selectedCar.selectOption(CarType_Q, SEDAN);
	selectedCar.selectOption(Engine_Q, GM);
	selectedCar.selectOption(BrakeSystem_Q, MANDO);
	selectedCar.selectOption(SteeringSystem_Q, BOSCH_S);
	selectedCar.runProducedCar();
	EXPECT_EQ(0, selectedCar.isValidCheck());
}

TEST(CarClass, InvalidIntegratedCarTest0)
{
	car selectedCar;
	selectedCar.selectOption(CarType_Q, SEDAN);
	selectedCar.selectOption(Engine_Q, Broken);
	selectedCar.selectOption(BrakeSystem_Q, MANDO);
	selectedCar.selectOption(SteeringSystem_Q, BOSCH_S);
	selectedCar.runProducedCar();
	EXPECT_EQ(NoError, selectedCar.isValidCheck());
}

TEST(CarClass, InvalidIntegratedCarTest1)
{
	car selectedCar;
	selectedCar.selectOption(CarType_Q, SEDAN);
	selectedCar.selectOption(Engine_Q, GM);
	selectedCar.selectOption(BrakeSystem_Q, CONTINENTAL);
	selectedCar.selectOption(SteeringSystem_Q, BOSCH_S);
	selectedCar.runProducedCar();
	EXPECT_EQ(Error1, selectedCar.isValidCheck());
}

TEST(CarClass, InvalidIntegratedCarTest2)
{
	car selectedCar;
	selectedCar.selectOption(CarType_Q, SUV);
	selectedCar.selectOption(Engine_Q, TOYOTA);
	selectedCar.selectOption(BrakeSystem_Q, MANDO);
	selectedCar.selectOption(SteeringSystem_Q, BOSCH_S);
	selectedCar.runProducedCar();
	EXPECT_EQ(Error2, selectedCar.isValidCheck());
}

TEST(CarClass, InvalidIntegratedCarTest3)
{
	car selectedCar;
	selectedCar.selectOption(CarType_Q, TRUCK);
	selectedCar.selectOption(Engine_Q, WIA);
	selectedCar.selectOption(BrakeSystem_Q, MANDO);
	selectedCar.selectOption(SteeringSystem_Q, BOSCH_S);
	selectedCar.runProducedCar();
	EXPECT_EQ(Error3, selectedCar.isValidCheck());
}

TEST(CarClass, InvalidIntegratedCarTest4)
{
	car selectedCar;
	selectedCar.selectOption(CarType_Q, TRUCK);
	selectedCar.selectOption(Engine_Q, GM);
	selectedCar.selectOption(BrakeSystem_Q, MANDO);
	selectedCar.selectOption(SteeringSystem_Q, BOSCH_S);
	selectedCar.runProducedCar();
	EXPECT_EQ(Error4, selectedCar.isValidCheck());
}

TEST(CarClass, InvalidIntegratedCarTest5)
{
	car selectedCar;
	selectedCar.selectOption(CarType_Q, SEDAN);
	selectedCar.selectOption(Engine_Q, GM);
	selectedCar.selectOption(BrakeSystem_Q, BOSCH_B);
	selectedCar.selectOption(SteeringSystem_Q, MOBIS);
	selectedCar.runProducedCar();
	EXPECT_EQ(Error5, selectedCar.isValidCheck());
}

TEST(CarClass, CarTest)
{
	car selectedCar;
	EXPECT_EQ(true, selectedCar.checkValidInput(CarType_Q, SEDAN));
	EXPECT_EQ(false, selectedCar.checkValidInput(CarType_Q, Num_CarType));
}

TEST(CarClass, RunCarTest)
{
	car selectedCar;
	EXPECT_EQ(true, selectedCar.checkValidInput(Run_Test, 0));
	EXPECT_EQ(true,selectedCar.checkValidInput(Run_Test, RunCar));
	EXPECT_EQ(true, selectedCar.checkValidInput(Run_Test, CarTest));
	EXPECT_EQ(false, selectedCar.checkValidInput(Run_Test, 3));
}