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

TEST(MachineCalculatorTest, VerifyArgument_ExpectsThrowUnknownMachineType) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    ASSERT_THROW(calc.GetPowerConsumption("UnknownMachine", 1), ArgumentException);
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

TEST(MachineCalculatorTest, Press_VerifyPowerConsumption_1Hour_ExpectLinear) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 1; // 1 hour
    const bool is_energy_saving = false;
    const double expceted_power_consumption = 7.2; // 7.2 kWh

    ASSERT_DOUBLE_EQ(calc.GetPowerConsumption("Press", duration, is_energy_saving),
                     expceted_power_consumption);
}

TEST(MachineCalculatorTest, Press_VerifyPowerConsumption_2Hour_ExpectLinear) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 2; // 2 hours
    const bool is_energy_saving = false;
    const double expceted_power_consumption = 14.4; // 14.4 kWh

    ASSERT_DOUBLE_EQ(calc.GetPowerConsumption("Press", duration, is_energy_saving),
                     expceted_power_consumption);
}

TEST(MachineCalculatorTest, Lathe_VerifyPowerConsumption_1Hour_ExpectLogarithmic) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 1; // 1 hour
    const bool is_energy_saving = false;
    const double expceted_power_consumption = 3.5 * std::log10(1 + 1); // 1.05 kWh

    ASSERT_DOUBLE_EQ(calc.GetPowerConsumption("Lathe", duration, is_energy_saving),
                     expceted_power_consumption);
}

TEST(MachineCalculatorTest, Lathe_VerifyPowerConsumption_10Hour_ExpectLogarithmic) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 10; // 10 hours
    const bool is_energy_saving = false;
    const double expceted_power_consumption = 3.5 * std::log10(10 + 1); // 3.5 kWh

    ASSERT_DOUBLE_EQ(calc.GetPowerConsumption("Lathe", duration, is_energy_saving),
                     expceted_power_consumption);
}

TEST(MachineCalculatorTest, Lathe_VerifyPowerConsumption_100Hour_ExpectLogarithmic) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 100; // 100 hours
    const bool is_energy_saving = false;
    const double expceted_power_consumption = 3.5 * std::log10(100 + 1); // 7.0 kWh

    ASSERT_EQ(calc.GetPowerConsumption("Lathe", duration, is_energy_saving),
              expceted_power_consumption);
}

TEST(MachineCalculatorTest, IMachine_Verify_EnergySaving) {
    MachinePowerCalculator calc{std::make_shared<MachineFactory>()};

    // data
    const int duration = 1; // 1 hour
    const bool is_energy_saving = true;
    const double expceted_power_consumption = 5.0 * 0.8; // 4.0 kWh

    ASSERT_EQ(calc.GetPowerConsumption("MillingMachine", duration, is_energy_saving),
              expceted_power_consumption);
}
