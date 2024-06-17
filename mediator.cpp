#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Colleague;

class Mediator {
public:
    virtual void notify(Colleague *sender, const std::string &event) const = 0;
};

class Colleague {
protected:
    Mediator *mediator;
public:
    Colleague(Mediator *mediator) : mediator(mediator) {}
    virtual void send(const std::string &event) const = 0;
};

class ConcreteColleague1 : public Colleague {
public:
    ConcreteColleague1(Mediator *mediator) : Colleague(mediator) {}
    void send(const std::string &event) const override {
        std::cout << "ConcreteColleague1 sends event: " << event << "\n";
        mediator->notify(this, event);
    }
};

class ConcreteColleague2 : public Colleague {
public:
    ConcreteColleague2(Mediator *mediator) : Colleague(mediator) {}
    void send(const std::string &event) const override {
        std::cout << "ConcreteColleague2 sends event: " << event << "\n";
        mediator->notify(this, event);
    }
};

class ConcreteMediator : public Mediator {
private:
    ConcreteColleague1 *colleague1;
    ConcreteColleague2 *colleague2;
public:
    void setColleague1(ConcreteColleague1 *colleague) {
        colleague1 = colleague;
    }
    void setColleague2(ConcreteColleague2 *colleague) {
        colleague2 = colleague;
    }
    void notify(Colleague *sender, const std::string &event) const override {
        if (sender == colleague1) {
            std::cout << "Mediator reacts on ConcreteColleague1's event and triggers ConcreteColleague2's operation.\n";
            colleague2->send(event);
        } else if (sender == colleague2) {
            std::cout << "Mediator reacts on ConcreteColleague2's event and triggers ConcreteColleague1's operation.\n";
            colleague1->send(event);
        }
    }
};

int main() {
    ConcreteMediator mediator;
    ConcreteColleague1 colleague1(&mediator);
    ConcreteColleague2 colleague2(&mediator);

    mediator.setColleague1(&colleague1);
    mediator.setColleague2(&colleague2);

    colleague1.send("Event 1");
    colleague2.send("Event 2");

    return 0;
}
//#### Призначення:
//- **Основна мета**: Інкапсуляція способу взаємодії об'єктів, зменшення залежностей між об'єктами.
//- **Застосування**: Коли потрібно централізувати логіку взаємодії між об'єктами.
//- **Характеристики**:
//  - Зменшує кількість прямих залежностей між об'єктами.
//  - Полегшує зміну взаємодії між об'єктами.
//  - Забезпечує централізований контроль над взаємодією.