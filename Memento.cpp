#include <iostream>
#include <string>

class Memento {
private:
    std::string state;
public:
    Memento(const std::string &state) : state(state) {}
    std::string getState() const {
        return state;
    }
};

class Originator {
private:
    std::string state;
public:
    void setState(const std::string &state) {
        this->state = state;
    }
    std::string getState() const {
        return state;
    }
    Memento saveStateToMemento() {
        return Memento(state);
    }
    void getStateFromMemento(const Memento &memento) {
        state = memento.getState();
    }
};

class Caretaker {
private:
    Memento memento;
public:
    void saveState(Originator &originator) {
        memento = originator.saveStateToMemento();
    }
    void restoreState(Originator &originator) {
        originator.getStateFromMemento(memento);
    }
};

int main() {
    Originator originator;
    Caretaker caretaker;

    originator.setState("State1");
    originator.setState("State2");
    caretaker.saveState(originator);

    originator.setState("State3");
    std::cout << "Current State: " << originator.getState() << "\n";

    caretaker.restoreState(originator);
    std::cout << "Restored State: " << originator.getState() << "\n";

    return 0;
}
//#### Призначення:
//- **Основна мета**: Збереження та відновлення попереднього стану об'єкта без порушення його інкапсуляції.
//- **Застосування**: Коли потрібно зберігати та відновлювати стан об'єкта.
//- **Характеристики**:
 // - Забезпечує збереження стану об'єкта.
 // - Підтримує принцип інкапсуляції.
 // - Дозволяє легко відновлювати попередні стани.