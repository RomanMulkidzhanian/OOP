#include <iostream>
#include <memory>

// Abstract Product A
class AbstractProductA {
public:
    virtual void operation() const = 0;
};

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void operation() const override {
        std::cout << "ConcreteProductA1: Operation.\n";
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void operation() const override {
        std::cout << "ConcreteProductA2: Operation.\n";
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }
};

int main() {
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractProductA> productA1 = factory1->createProductA();
    productA1->operation();

    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<AbstractProductA> productA2 = factory2->createProductA();
    productA2->operation();

    return 0;
}
//#### Призначення:
//- **Основна мета**: Надання інтерфейсу для створення сімейств взаємопов'язаних або взаємозалежних об'єктів без зазначення їх конкретних класів.
//- **Застосування**: Коли система повинна бути незалежною від способу створення, композиції та представлення її об'єктів.
//- **Характеристики**:
 // - Дозволяє створювати сімейства пов'язаних об'єктів без зазначення їх конкретних класів.
  //- Підтримує принцип відкритості/закритості.
 // - Забезпечує узгодженість створених об'єктів.