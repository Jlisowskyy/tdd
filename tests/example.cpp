#include <gtest/gtest.h>

#include <io_lib.hpp>

TEST(MachineCalculatorTest, VerifyArgument_ExpectsException) {
    MachinePowerCalculator calc{};

    ASSERT_THROW(calc.GetPowerConsumption("", 0), ArgumentException);
}
