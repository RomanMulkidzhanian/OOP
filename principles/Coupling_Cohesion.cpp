// Погано: висока зв'язність і низька сполученість
class BadExample {
private:
    int x;
    int y;
public:
    void setX(int value) {
        x = value;
    }
    void setY(int value) {
        y = value;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
};

// Краще: низька зв'язність і висока сполученість
class GoodExample {
private:
    int z;
public:
    void setZ(int value) {
        z = value;
    }
    int calculate(int x, int y) const {
        return x + y + z;
    }
};

//Зв'язність (coupling) визначає ступінь, до якої клас або модуль залежить від інших класів або модулів. Сполученість (cohesion) визначає ступінь,
 //до якої елементи внутрішньої структури класу або модуля пов'язані між собою. Чим менше зв'язність і вища сполученість, тим краще.