#include <iostream>
#include <vector>

// Базовий клас для сховища даних
class DataStore {
public:
    virtual std::string readData() const = 0;
    virtual void writeData(const std::string& data) = 0;
    virtual ~DataStore() = default;
};

// Конкретна реалізація сховища даних у вигляді простого вектора
class VectorDataStore : public DataStore {
private:
    std::vector<std::string> data;

public:
    std::string readData() const override {
        std::string result;
        for (const auto& entry : data) {
            result += entry + " ";
        }
        return result;
    }

    void writeData(const std::string& newData) override {
        data.push_back(newData);
    }
};

// Декоратор для стискання даних
class CompressionDecorator : public DataStore {
private:
    DataStore* wrappee;

public:
    CompressionDecorator(DataStore* dataStore) : wrappee(dataStore) {}

    std::string readData() const override {
        // Декомпресуємо дані перед поверненням
        return decompress(wrappee->readData());
    }

    void writeData(const std::string& newData) override {
        // Спершу стискаємо дані перед записом
        wrappee->writeData(compress(newData));
    }

    std::string compress(const std::string& data) const {
        // Уявна функція стискання даних
        return "<compressed>" + data + "</compressed>";
    }

    std::string decompress(const std::string& compressedData) const {
        // Уявна функція декомпресії даних
        return compressedData.substr(12, compressedData.size() - 25); // Видаляємо теги стискання
    }
};

int main() {
    VectorDataStore* simpleDataStore = new VectorDataStore(); // Створюємо просте сховище даних
    CompressionDecorator* compressedDataStore = new CompressionDecorator(simpleDataStore); // Обгортаємо його у декоратор для стискання

    // Записуємо та зчитуємо дані через декороване сховище
    compressedDataStore->writeData("Hello, world!");
    std::cout << compressedDataStore->readData() << std::endl;

    delete compressedDataStore; // Звільняємо пам'ять
    delete simpleDataStore;

    return 0;
}
// систему зберігання та відображення даних, яку можна доповнювати різними функціональностями, наприклад, стисканням чи шифруванням даних.
//Decorator дозволяє динамічно додавати нові обов'язки або функціональність об'єктам без зміни їхньої структури.
//Decorator використовується, коли потрібно додавати функціональність до об'єкта на льоту, динамічно.
//Decorator додає нові можливості до об'єкта, змінюючи його поведінку.
//Decorator може бути складним у використанні, оскільки потрібно правильно комбінувати декоратори.
//Призначення:
//Основна мета: Додавання нових функцій до об'єктів динамічно, без модифікації їхніх класів.
//Застосування: Коли потрібно додати нову функціональність об'єктам динамічно та прозоро для користувача.
//Характеристики:
//Забезпечує гнучкий механізм для розширення об'єктів.
//Об'єкти можуть бути декоровані кілька разів.
//Використовує композицію замість наслідування.
