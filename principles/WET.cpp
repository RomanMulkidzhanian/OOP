class Rectangle {
private:
    int width;
    int height;
public:
    int getWidth() const {
        return width;
    }
    int getHeight() const {
        return height;
    }
    int calculateArea() const {
        return width * height;
    }
    int calculateAreaAgain() const {
        return width * height;
    }
};
//Принцип WET є протилежністю DRY і часто застосовується як приклад поганої практики.
// Він означає дублювання коду або інформації, що ускладнює його підтримку та підвищує ймовірність помилок.