class Engine {
public:
    void start() {
        // ... запуск двигуна
    }
};

class Car {
private:
    Engine engine;
public:
    void startEngine() {
        engine.start();
    }
};
//Принцип Law of Demeter (LoD) або "Принцип найменшого знання" говорить, що модуль (клас, метод, функція) повинен мати мінімум інформації про інші модулі,
// з якими він взаємодіє. Це означає, що об'єкт повинен взаємодіяти тільки зі своїми безпосередніми друзями (підлеглими або складовими).