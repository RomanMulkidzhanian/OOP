#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // Необхідний для std::remove_if

// Базовий клас Component, що визначає інтерфейс для всіх компонентів (листків і композитів)
class Component {
public:
    virtual void operation() const = 0;
    virtual void add(std::unique_ptr<Component> component) {}
    virtual void remove(Component* component) {}
    virtual ~Component() = default;
};

// Клас Leaf представляє окремі об'єкти, які не мають підкомпонентів
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation.\n";
    }
};

// Клас Composite представляє об'єкти, які можуть містити інші компоненти
class Composite : public Component {
private:
    std::vector<std::unique_ptr<Component>> children;
public:
    // Метод для додавання підкомпонентів
    void add(std::unique_ptr<Component> component) override {
        children.push_back(std::move(component));
    }
    
    // Метод для видалення підкомпонентів
    void remove(Component* component) override {
        children.erase(std::remove_if(children.begin(), children.end(),
            [&](const std::unique_ptr<Component>& child) {
                return child.get() == component;
            }), children.end());
    }
    
    // Метод для виконання операції, що викликається для кожного підкомпонента
    void operation() const override {
        std::cout << "Composite operation.\n";
        for (const auto &child : children) {
            child->operation();
        }
    }
};

int main() {
    // Створення композита root, який містить два листки та один підкомпозит
    std::unique_ptr<Composite> root = std::make_unique<Composite>();
    root->add(std::make_unique<Leaf>());
    
    std::unique_ptr<Composite> subtree = std::make_unique<Composite>();
    subtree->add(std::make_unique<Leaf>());
    subtree->add(std::make_unique<Leaf>());

    root->add(std::move(subtree));
    
    // Виконання операції для всіх компонентів в дереві
    root->operation();

    return 0;
}


    
//#### Призначення:
//- **Основна мета**: Організація об'єктів у деревоподібну структуру для представлення ієрархії "частина-ціле".
//- **Застосування**: Коли потрібно працювати з групою об'єктів так само, як з одним об'єктом.
//- **Характеристики**:
 // - Дозволяє об'єктам бути складеними з інших об'єктів.
//  - Забезпечує єдиний інтерфейс для роботи з одиничними об'єктами та їхніми композиціями.
 // - Спрощує роботу з ієрархічними структурами.
