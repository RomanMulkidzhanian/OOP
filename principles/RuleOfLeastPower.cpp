#include <iostream>
#include <fstream>
#include <string>

class FileLogger {
public:
    void log(const std::string& message) {
        std::ofstream file("log.txt", std::ios_base::app);
        file << message << std::endl;
        file.close();
    }
};

class ConsoleLogger {
public:
    void log(const std::string& message) {
        std::cout << message << std::endl;
    }
};

class Application {
private:
    ConsoleLogger logger; // Змінили тип на менш потужний
public:
    void doSomething() {
        logger.log("Something happened");
    }
};

int main() {
    Application app;
    app.doSomething();

    return 0;
}
//Принцип найменшої потужності (Rule of Least Power) стверджує,
// що для вибору мови програмування або формату даних слід обирати найпростіший і найменш потужний варіант, який відповідає потребам програми.