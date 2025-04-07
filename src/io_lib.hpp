#ifndef IO_LIB_HPP
#define IO_LIB_HPP

#include <string>
#include <exception>
#include <memory>
#include <unordered_map>
#include <functional>

class ArgumentException final : public std::exception {
    std::string message;

public:
    explicit ArgumentException(const std::string &msg)
        : message("ArgumentException: " + msg) {
    }

    const char *what() const noexcept override {
        return message.c_str();
    }
};

class IMachine {
public:
    IMachine() = default;

    virtual ~IMachine() = default;

    virtual double GetPowerConsumption(int duration, bool is_energy_saving) = 0;
};

class MillingMachine : public IMachine {
    static constexpr double kBaseConsumption = 5.0; // Base power consumption in kWh
public:
    MillingMachine() = default;

    ~MillingMachine() override = default;

    double GetPowerConsumption(int duration, [[maybe_unused]] bool is_energy_saving) override {
        return kBaseConsumption * duration;
    }
};

class IMachineFactory {
public:
    IMachineFactory() = default;

    virtual ~IMachineFactory() = default;

    virtual std::shared_ptr<IMachine> CreateMachine(const std::string &) = 0;
};

class MachineFactory : public IMachineFactory {
public:
    MachineFactory() = default;
    ~MachineFactory() override = default;

    std::shared_ptr<IMachine> CreateMachine(const std::string &machine_type) override {
        static std::unordered_map<std::string, std::function<std::shared_ptr<IMachine>()>> machine_map = {
            {"MillingMachine", []() { return std::make_shared<MillingMachine>(); }},
        };

        if (machine_map.find(machine_type) != machine_map.end()) {
            return machine_map[machine_type]();
        }

        throw ArgumentException("Unknown machine type: " + machine_type);
    }
};

class MachinePowerCalculator {
    std::shared_ptr<IMachineFactory> factory_;

public:
    explicit MachinePowerCalculator(std::shared_ptr<IMachineFactory> factory): factory_(std::move(factory)) {
        if (!factory_) {
            throw ArgumentException("Factory cannot be null");
        }
    }

    double GetPowerConsumption(const std::string &machine_type, int duration, bool is_energy_saving = false) {
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
