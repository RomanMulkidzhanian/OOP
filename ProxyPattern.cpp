#include <iostream>

class Subject {
public:
    virtual void request() const = 0;
};

class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request.\n";
    }
};

class Proxy : public Subject {
private:
    RealSubject realSubject;
public:
    void request() const override {
        std::cout << "Proxy: Delegating request to RealSubject.\n";
        realSubject.request();
    }
};

int main() {
    Proxy proxy;
    proxy.request();
    return 0;
}
//### Proxy (Проксі)

//#### Призначення:
//- **Основна мета**: Контролювання доступу до об'єкта, створюючи його замісника або сурогата.
//- **Застосування**: Коли потрібно забезпечити контроль доступу до об'єкта або додати додаткові функції.
// **Характеристики**:
//  - Може використовуватися для леніового створення об'єктів, контролю доступу, кешування, логування тощо.
 // - Дозволяє додавати додаткову логіку до методів об'єкта.
 // - Зберігає оригінальний інтерфейс об'єкта.
