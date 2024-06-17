#include <iostream>

// Target interface
class Target {
public:
    virtual void request() const {
        std::cout << "Target: Default request.\n";
    }
};

// Adaptee interface
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee: Specific request.\n";
    }
};

// Adapter class
class Adapter : public Target {
private:
    Adaptee adaptee;
public:
    void request() const override {
        adaptee.specificRequest();
    }
};

int main() {
    Adapter adapter;
    adapter.request();
    return 0;
}
//### Adapter (Адаптер)

//#### Призначення:
//- **Основна мета**: Перетворення інтерфейсу класу в інший інтерфейс, який очікують клієнти.
//- **Застосування**: Коли потрібно використовувати існуючий клас з іншим інтерфейсом.
//- **Характеристики**:
//  - Дозволяє використовувати класи з несумісними інтерфейсами.
 // - Забезпечує гнучкість у використанні класів.
 // - Може бути реалізований через наслідування або композицію.
