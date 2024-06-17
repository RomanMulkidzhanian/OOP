#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    std::string color;

public:
    void setMake(const std::string& make) {
        this->make = make;
    }

    void setModel(const std::string& model) {
        this->model = model;
    }

    void setColor(const std::string& color) {
        this->color = color;
    }

    void display() const {
        std::cout << "Car: " << make << " " << model << ", Color: " << color << std::endl;
    }
};

class CarBuilder {
protected:
    Car car;

public:
    virtual void buildMake() = 0;
    virtual void buildModel() = 0;
    virtual void buildColor() = 0;

    Car getCar() {
        return car;
    }
};

class SedanCarBuilder : public CarBuilder {
public:
    void buildMake() override {
        car.setMake("Honda");
    }

    void buildModel() override {
        car.setModel("Civic");
    }

    void buildColor() override {
        car.setColor("Red");
    }
};

class Director {
private:
    CarBuilder* builder;

public:
    Director(CarBuilder* builder) : builder(builder) {}

    Car buildCar() {
        builder->buildMake();
        builder->buildModel();
        builder->buildColor();
        return builder->getCar();
    }
};

int main() {
    SedanCarBuilder sedanBuilder;
    Director director(&sedanBuilder);

    Car sedan = director.buildCar();
    sedan.display();

    return 0;
}
//Паттерн Builder використовується для побудови складних об'єктів шляхом послідовного додавання різних компонентів.
//будівельник для створення об'єктів автомобілів з різними характеристиками.
//Builder використовується для послідовної побудови складних об'єктів.
//Builder використовується для створення об'єктів зі складними конфігураціями.