#include <iostream>
#include <vector>
#include <memory>

// Command interface
class Command {
public:
    virtual void execute() const = 0;
};

// Receiver
class Receiver {
public:
    void action() const {
        std::cout << "Receiver: Performing action.\n";
    }
};

// Concrete Command
class ConcreteCommand : public Command {
private:
    const Receiver *receiver;
public:
    ConcreteCommand(const Receiver *receiver) : receiver(receiver) {}
    void execute() const override {
        receiver->action();
    }
};

// Invoker
class Invoker {
private:
    std::vector<std::unique_ptr<Command>> commands;
public:
    void setCommand(std::unique_ptr<Command> command) {
        commands.push_back(std::move(command));
    }
    void executeCommands() const {
        for (const auto &command : commands) {
            command->execute();
        }
    }
};

int main() {
    Receiver receiver;
    Invoker invoker;

    invoker.setCommand(std::make_unique<ConcreteCommand>(&receiver));
    invoker.executeCommands();

    return 0;
}
//#### Призначення:
//- **Основна мета**: Інкапсуляція запиту як об'єкта, дозволяючи параметризувати клієнтів різними запитами, чергами або логами запитів, а також підтримку скасування операцій.
//- **Застосування**: Коли необхідно інкапсулювати запити як об'єкти.
//- **Характеристики**:
 // - Дозволяє параметризувати клієнтів різними запитами.
 // - Підтримує логування та скасування операцій.
 // - Інкапсулює операції в окремі об'єкти.