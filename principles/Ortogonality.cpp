class Logger {
public:
    void log(const std::string& message) {
        // Запис повідомлення в лог
        std::cout << "Log: " << message << std::endl;
    }
};

class Application {
private:
    Logger logger;
public:
    void run() {
        logger.log("Application started");
        // Логіка додатку
        logger.log("Application finished");
    }
};
//Принцип ортогональності означає, що різні компоненти системи повинні бути незалежними один від одного.
// Зміна одного компонента не повинна впливати на інші. Це дозволяє легко змінювати або замінювати компоненти без ризику порушити інші частини системи.