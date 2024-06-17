#include <iostream>
#include <memory>

// Prototype interface
class Prototype {
public:
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void operation() const = 0;
};

// Concrete Prototype
class ConcretePrototype : public Prototype {
public:
    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype>(*this);
    }
    void operation() const override {
        std::cout << "ConcretePrototype: Cloned operation.\n";
    }
};

int main() {
    std::unique_ptr<Prototype> prototype = std::make_unique<ConcretePrototype>();
    std::unique_ptr<Prototype> clone = prototype->clone();
    clone->operation();
    return 0;
}
//#### Призначення:
//- **Основна мета**: Створення нових об'єктів шляхом клонування існуючих екземплярів.
//- **Застосування**: Коли потрібно створювати об'єкти на основі прототипів.
//- **Характеристики**:
//  - Дозволяє створювати нові об'єкти шляхом копіювання.
//  - Зменшує необхідність у створенні підкласів для кожного типу об'єкта.
 // - Підтримує створення об'єктів з попередньо налаштованими станами.