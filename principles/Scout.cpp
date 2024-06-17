class Calculator {
public:
    int add(int a, int b) const {
        return a + b;
    }

    int subtract(int a, int b) const {
        return a - b;
    }

    int multiply(int a, int b) const {
        return a * b;
    }

    int divide(int a, int b) const {
        if (b != 0) {
            return a / b;
        } else {
            // Обробка помилки
            return 0;
        }
    }
};
//Принцип скаута (Scout Rule) вимагає, щоб розробники "підуть вперед" 
//і підтримували код базовим та чистим у процесі розробки, не чекаючи, коли це стане необхідним.