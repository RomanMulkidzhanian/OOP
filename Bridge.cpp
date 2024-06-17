#include <iostream>

// Implementation interface
class Implementation {
public:
    virtual void operationImplementation() const = 0;
};

// Concrete Implementations
class ConcreteImplementationA : public Implementation {
public:
    void operationImplementation() const override {
        std::cout << "ConcreteImplementationA: Implementation.\n";
    }
};

class ConcreteImplementationB : public Implementation {
public:
    void operationImplementation() const override {
        std::cout << "ConcreteImplementationB: Implementation.\n";
    }
};

// Abstraction
class Abstraction {
protected:
    Implementation* implementation;
public:
    Abstraction(Implementation* imp) : implementation(imp) {}
    virtual void operation() const {
        implementation->operationImplementation();
    }
};

// Extended Abstraction
class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation* imp) : Abstraction(imp) {}
    void operation() const override {
        std::cout << "ExtendedAbstraction: Extended operation with:\n";
        implementation->operationImplementation();
    }
};

int main() {
    ConcreteImplementationA impA;
    ExtendedAbstraction extendedA(&impA);
    extendedA.operation();

    ConcreteImplementationB impB;
    ExtendedAbstraction extendedB(&impB);
    extendedB.operation();

    return 0;
}
//#### Призначення:
//- **Основна мета**: Розділення абстракції та її реалізації, дозволяючи їм змінюватися незалежно.
//- **Застосування**: Коли необхідно відокремити абстракцію від її реалізації для незалежної модифікації.
//- **Характеристики**:
//  - Дозволяє змінювати реалізацію незалежно від абстракції.
//  - Зменшує зв'язність між абстракцією та реалізацією.
 // - Підтримує принцип розділення інтерфейсу та реалізації.