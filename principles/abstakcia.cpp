class Shape {
public:
    virtual double getArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};
//Абстракція полягає у виділенні суттєвих характеристик об'єкта,
// відокремлюючи їх від несуттєвих деталей. Це дозволяє створювати моделі реальних об'єктів, що є більш зрозумілими та простими для використання.