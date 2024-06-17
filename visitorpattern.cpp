#include <iostream>
#include <vector>
#include <memory>

// Forward declaration
class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual void visit(ConcreteElementA *element) = 0;
    virtual void visit(ConcreteElementB *element) = 0;
};

class Element {
public:
    virtual void accept(Visitor *visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor *visitor) override {
        visitor->visit(this);
    }
    void operationA() {
        std::cout << "ConcreteElementA operation.\n";
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor *visitor) override {
        visitor->visit(this);
    }
    void operationB() {
        std::cout << "ConcreteElementB operation.\n";
    }
};

class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElementA *element) override {
        element->operationA();
    }
    void visit(ConcreteElementB *element) override {
        element->operationB();
    }
};

int main() {
    std::vector<std::unique_ptr<Element>> elements;
    elements.push_back(std::make_unique<ConcreteElementA>());
    elements.push_back(std::make_unique<ConcreteElementB>());

    ConcreteVisitor visitor;
    for (const auto &element : elements) {
        element->accept(&visitor);
    }

    return 0;
}
//### Visitor (Відвідувач)

//#### Призначення:
//- **Основна мета**: Відокремлення алгоритмів від структури об'єктів, по яких вони діють.
//- **Застосування**: Коли необхідно виконати операції над елементами структури об'єктів без зміни класів цих об'єктів.
//- **Характеристики**:
//  - Дозволяє додавати нові операції без зміни класів об'єктів.
//  - Спрощує додавання нових операцій.
//  - Відокремлює алгоритм від структури даних.