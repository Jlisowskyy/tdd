#include <gtest/gtest.h>

#include <io_lib.hpp>

TEST(MachineCalculatorTest, VerifyArgument_ExpectsExceptionEmptyMachineType) {
    MachinePowerCalculator calc{};

    ASSERT_THROW(calc.GetPowerConsumption("", 0), ArgumentException);
}

TEST(MachineCalculatorTest, VerifyArgument_ExpectsExceptionNegativeDuration) {
    MachinePowerCalculator calc{};

    ASSERT_THROW(calc.GetPowerConsumption("MillingMachine", -1), ArgumentException);
}
