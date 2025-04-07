#ifndef IO_LIB_HPP
#define IO_LIB_HPP

#include <string>
#include <exception>

class ArgumentException : public std::exception {
    std::string message;
public:
    explicit ArgumentException(const std::string& msg)
        : message("ArgumentException: " + msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
class IMachine {
public:
    IMachine() = default;
    virtual ~IMachine() = default;

    virtual double GetPowerConsumption(int duration, bool is_energy_saving) = 0;
};

class MachinePowerCalculator {
public:
    double GetPowerConsumption(const std::string& machine_type, int duration, bool is_energy_saving = false) {
        if (machine_type.empty()) {
            throw ArgumentException("Machine type cannot be empty");
        }

        if (duration < 0) {
            throw ArgumentException("Duration must be greater than zero");
        }

        return {};
    }
};

#endif //IO_LIB_HPP
