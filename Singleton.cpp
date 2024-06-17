#include <iostream>

class Singleton {
private:
    static Singleton *instance;
    Singleton() {}
public:
    static Singleton *getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    void operation() const {
        std::cout << "Singleton: Operation.\n";
    }
};

Singleton *Singleton::instance = nullptr;

int main() {
    Singleton *singleton = Singleton::getInstance();
    singleton->operation();
    return 0;
}
//### Призначення:
//- **Основна мета**: Забезпечення існування лише одного екземпляра класу та надання глобальної точки доступу до нього.
//- **Застосування**: Коли необхідно мати лише один екземпляр класу в системі.
//- **Характеристики**:
 // - Гарантує існування лише одного екземпляра класу.
 // - Забезпечує глобальну точку доступу до цього екземпляра.
  //- Легко реалізується і використовується.