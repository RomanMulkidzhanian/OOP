class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        std::cout << "Sparrow is flying" << std::endl;
    }
};

void makeBirdFly(Bird& bird) {
    bird.fly();
}
//Принцип підстановки Лісков (LSP) говорить, що об'єкти підкласу повинні бути замінювані 
//об'єктами базового класу без порушення коректності програми. Це означає, що підклас повинен підтримувати контракт базового класу.

