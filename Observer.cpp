#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string& stock, double price) = 0;
    virtual ~Observer() = default;
};

class StockObserver : public Observer {
private:
    std::string name;

public:
    StockObserver(const std::string& name) : name(name) {}

    void update(const std::string& stock, double price) override {
        std::cout << "Notified " << name << " of " << stock << " price change to " << price << std::endl;
    }
};

class Subject {
private:
    std::vector<Observer*> observers;
    std::string stock;
    double price;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // Implement detach logic
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update(stock, price);
        }
    }

    void setPrice(double newPrice) {
        price = newPrice;
        notify();
    }

    void setStock(const std::string& newStock) {
        stock = newStock;
    }
};

int main() {
    Subject subject;
    StockObserver observer1("Observer 1");
    StockObserver observer2("Observer 2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setStock("AAPL");
    subject.setPrice(150.25);

    return 0;
}
//Реалізуємо спостерігача, який відслідковує зміни в стані стокової ціни та повідомляє підписників про ці зміни.
//Основна мета: Визначення залежностей один до одного між об'єктами таким чином, що коли один об'єкт змінює свій стан, всі залежні від нього об'єкти автоматично повідомляються та оновлюються.
//Застосування: Коли зміни одного об'єкта вимагають оновлення інших об'єктів.
//Характеристики:
//Дозволяє визначати відносини між об'єктами один-до-багатьох.
//Полегшує підтримку та розширення системи.
//Забезпечує автоматичне повідомлення спостерігачів про зміни.