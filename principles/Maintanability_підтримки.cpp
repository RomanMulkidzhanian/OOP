class Employee {
private:
    std::string name;
    double salary;

public:
    Employee(const std::string& name, double salary)
        : name(name), salary(salary) {}

    std::string getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double newSalary) {
        if (newSalary > 0) {
            salary = newSalary;
        }
    }
};
//Принцип підтримуваності означає, що код повинен бути написаний таким чином, щоб його було легко розуміти, змінювати та підтримувати з плином часу
//. Це включає в себе хорошу структуру коду, коментарі, документування та використання зрозумілих імен змінних та методів.