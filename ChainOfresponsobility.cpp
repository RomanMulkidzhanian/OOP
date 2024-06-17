#include <iostream>
#include <string>

class Handler {
public:
    virtual void handleRequest(const std::string& request) = 0;
    virtual ~Handler() {}
};

class ConcreteHandler1 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "spam") {
            std::cout << "Request handled by ConcreteHandler1" << std::endl;
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "virus") {
            std::cout << "Request handled by ConcreteHandler2" << std::endl;
        }
    }
};

class Client {
public:
    void run() {
        Handler* handler1 = new ConcreteHandler1();
        Handler* handler2 = new ConcreteHandler2();
        handler1->handleRequest("spam");
        handler2->handleRequest("virus");
        delete handler1;
        delete handler2;
    }
};

int main() {
    Client client;
    client.run();
    return 0;
}
//перевірка на спам, перевірка на віруси, фільтрація контенту тощо
//Основна мета: Передача запитів уздовж ланцюжка обробників, доки один з них не обробить запит.
//Застосування: Коли кілька об'єктів можуть обробити запит, але точний обробник заздалегідь невідомий.
//Характеристики:
//Зменшує кількість прямих залежностей між відправником і отримувачем запиту.
//Дозволяє динамічно змінювати ланцюжок обробників.
//Полегшує додавання нових обробників.