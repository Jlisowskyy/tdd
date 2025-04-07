#include <gtest/gtest.h>

#include <io_lib.hpp>

TEST(MachineCalculatorTest, VerifyArgument_ExpectsExceptionEmptyMachineType) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    ASSERT_THROW(calc.GetPowerConsumption("", 0), ArgumentException);
}

TEST(MachineCalculatorTest, VerifyArgument_ExpectsExceptionNegativeDuration) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    ASSERT_THROW(calc.GetPowerConsumption("MillingMachine", -1), ArgumentException);
}

TEST(MachineCalculatorTest, MillingMachine_VerifyPowerConsumption_1Hour_ExpectLinear) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 1; // 1 hour
    const bool is_energy_saving = false;
    const double expceted_power_consumption = 5.0; // 5 kWh

    ASSERT_DOUBLE_EQ(calc.GetPowerConsumption("MillingMachine", duration, is_energy_saving),
                     expceted_power_consumption);
}

TEST(MachineCalculatorTest, MillingMachine_VerifyPowerConsumption_2Hours_ExpectLinear) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 2; // 2 hours
    const bool is_energy_saving = false;
    const double expceted_power_consumption = 10.0; // 10 kWh

    ASSERT_DOUBLE_EQ(calc.GetPowerConsumption("MillingMachine", duration, is_energy_saving),
                     expceted_power_consumption);
}
