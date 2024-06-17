class Shape {
public:
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
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
//Принцип відкритості/закритості (OCP) говорить, що програмні сутності 
//(класи, модулі, функції) повинні бути відкритими для розширення, але закритими для змін.
// Це означає, що поведінку можна змінювати шляхом додавання нового коду, а не зміни існуючого.