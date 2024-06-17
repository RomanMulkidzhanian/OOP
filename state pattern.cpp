#include <iostream>
#include <string>

class State {
public:
    virtual void handle() = 0;
    virtual ~State() = default;
};

class WorkingState : public State {
public:
    void handle() override {
        std::cout << "Working state: working hard" << std::endl;
    }
};

class RestingState : public State {
public:
    void handle() override {
        std::cout << "Resting state: taking a break" << std::endl;
    }
};

class MaintenanceState : public State {
public:
    void handle() override {
        std::cout << "Maintenance state: under maintenance" << std::endl;
    }
};

class Robot {
private:
    State* currentState;

public:
    Robot() : currentState(nullptr) {}

    void setState(State* state) {
        currentState = state;
    }

    void performTask() {
        if (currentState) {
            currentState->handle();
        } else {
            std::cout << "No state set" << std::endl;
        }
    }
};

int main() {
    Robot robot;
    WorkingState workingState;
    RestingState restingState;
    MaintenanceState maintenanceState;

    robot.setState(&workingState);
    robot.performTask();

    robot.setState(&restingState);
    robot.performTask();

    robot.setState(&maintenanceState);
    robot.performTask();

    return 0;
}
//Основна мета: Зміна поведінки об'єкта при зміні його внутрішнього стану.
//Застосування: Коли об'єкт повинен змінювати свою поведінку залежно від свого стану.
//Характеристики:
//Інкапсулює стан як окремі об'єкти.
//Дозволяє змінювати поведінку об'єкта динамічно.
//Спрощує додавання нових станів.