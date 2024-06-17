#include <iostream>
#include <map>

class Point {
private:
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    void draw() {
        std::cout << "Drawing point at (" << x << ", " << y << ")" << std::endl;
    }
};

class PointFactory {
private:
    std::map<std::pair<int, int>, Point*> points;

public:
    Point* getPoint(int x, int y) {
        auto key = std::make_pair(x, y);
        if (points.find(key) == points.end()) {
            points[key] = new Point(x, y);
        }
        return points[key];
    }

    int getSize() {
        return points.size();
    }
};

int main() {
    PointFactory factory;
    for (int i = 0; i < 1000; ++i) {
        Point* point = factory.getPoint(i % 100, i / 100);
        point->draw();
    }
    std::cout << "Number of points created: " << factory.getSize() << std::endl;

    return 0;
}
//Основна мета: Зменшення витрат пам'яті шляхом спільного використання об'єктів, які спільно використовують однакові дані.
//Застосування: Коли необхідно створити багато об'єктів з однаковими даними.
//Характеристики:
//Використовує спільні об'єкти для зменшення витрат пам'яті.
//Поділяє спільний стан між кількома об'єктами.
//Забезпечує розділення внутрішнього і зовнішнього стану об'єктів.