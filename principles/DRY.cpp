class Rectangle {
private:
    int width;
    int height;
public:
    int getArea() const {
        return width * height;
    }
    int getPerimeter() const {
        return 2 * (width + height);
    }
};

//Принцип DRY наголошує, що будь-яка інформація
// у програмній системі повинна бути представлена один раз і лише один раз. 
//Це допомагає уникнути дублювання коду та полегшує його підтримку.