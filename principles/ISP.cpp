class Printer {
public:
    virtual void print() = 0;
};

class Scanner {
public:
    virtual void scan() = 0;
};

class AllInOnePrinter : public Printer, public Scanner {
public:
    void print() override {
        std::cout << "Printing document" << std::endl;
    }

    void scan() override {
        std::cout << "Scanning document" << std::endl;
    }
};
//Принцип поділу інтерфейсів (ISP) говорить, що клієнти не повинні бути змушені реалізовувати інтерфейси, які вони не використовують.
// Краще мати кілька вузькоспеціалізованих інтерфейсів, ніж один великий загальний інтерфейс.
//
//