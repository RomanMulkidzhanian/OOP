class Logger {
public:
    virtual void log(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "Log: " << message << std::endl;
    }
};

class Application {
private:
    Logger& logger;
public:
    Application(Logger& logger) : logger(logger) {}

    void doSomething() {
        // Дія, яку потрібно залогувати
        logger.log("Something happened");
    }
};
//Принцип інверсії залежностей (DIP) стверджує, що модулі програми повинні залежати від абстракцій,
// а не від конкретних реалізацій. Це дозволяє змінювати реалізацію без зміни коду, який використовує модуль.