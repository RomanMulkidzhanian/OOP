#include <iostream>

class Subsystem1 {
public:
    void operation1() const {
        std::cout << "Subsystem1: Operation 1.\n";
    }
    void operation2() const {
        std::cout << "Subsystem1: Operation 2.\n";
    }
};

class Subsystem2 {
public:
    void operationA() const {
        std::cout << "Subsystem2: Operation A.\n";
    }
    void operationB() const {
        std::cout << "Subsystem2: Operation B.\n";
    }
};

class Facade {
private:
    Subsystem1 subsystem1;
    Subsystem2 subsystem2;
public:
    void operation() const {
        std::cout << "Facade coordinates subsystems:\n";
        subsystem1.operation1();
        subsystem2.operationA();
        subsystem1.operation2();
        subsystem2.operationB();
    }
};

int main() {
    Facade facade;
    facade.operation();
    return 0;
}
//#### Призначення:
//- **Основна мета**: Спрощення доступу до складної системи шляхом надання єдиного інтерфейсу.
// **Застосування**: Коли потрібно надати простий інтерфейс до складної системи.
//- **Характеристики**:
 // - Приховує складність системи.
  //- Зменшує кількість залежностей між підсистемами.
  //- Покращує зручність використання системи.
