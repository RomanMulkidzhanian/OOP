#include <iostream>
#include <vector>
#include <string>

class Iterator {
public:
    virtual std::string next() = 0;
    virtual bool hasNext() = 0;
    virtual ~Iterator() {}
};

class ConcreteIterator : public Iterator {
private:
    std::vector<std::string> students;
    size_t position;
public:
    ConcreteIterator(const std::vector<std::string>& students)
        : students(students), position(0) {}

    std::string next() override {
        return students[position++];
    }

    bool hasNext() override {
        return position < students.size();
    }
};

class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
    virtual ~Aggregate() {}
};

class ConcreteAggregate : public Aggregate {
private:
    std::vector<std::string> students;
public:
    void addStudent(const std::string& student) {
        students.push_back(student);
    }

    Iterator* createIterator() override {
        return new ConcreteIterator(students);
    }
};

class Client {
public:
    void run() {
        ConcreteAggregate aggregate;
        aggregate.addStudent("Alice");
        aggregate.addStudent("Bob");
        aggregate.addStudent("Charlie");

        Iterator* iterator = aggregate.createIterator();
        while (iterator->hasNext()) {
            std::cout << iterator->next() << std::endl;
        }
        delete iterator;
    }
};

int main() {
    Client client;
    client.run();
    return 0;
}
//Приклад: У нас є колекція студентів, і ми хочемо мати можливість перебирати їх без прив'язки до конкретної реалізації колекції.
//Основна мета: Послідовний доступ до елементів колекції без розкриття її внутрішньої структури.
//Застосування: Коли потрібно забезпечити універсальний спосіб ітерації по елементах колекції.
//Характеристики:
//Інкапсулює логіку ітерації.
//Дозволяє мати кілька одночасних ітераторів.
//Підтримує різні типи ітерацій (прямий, зворотній, тощо).