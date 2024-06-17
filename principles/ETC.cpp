class Calculator {
public:
    virtual double calculate(double a, double b) = 0;
};

class Addition : public Calculator {
public:
    double calculate(double a, double b) override {
        return a + b;
    }
};

class Subtraction : public Calculator {
public:
    double calculate(double a, double b) override {
        return a - b;
    }
};
//Принцип "легше змінювати" (Easier to Change) стверджує, що програмні системи повинні бути легко змінюваними для відповіді
// на змінюючіся вимоги або умови. Це може включати в себе використання гнучких архітектурних рішень,
//добре структурований та зрозумілий код, а також мінімальну залежність між компонентами системи.