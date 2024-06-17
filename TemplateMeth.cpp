#include <iostream>
#include <vector>

// Базовий клас з шаблонним методом
class SearchAlgorithm {
public:
    int findExtreme(const std::vector<int>& data) const {
        int result = data.front();
        for (const auto& item : data) {
            result = compare(result, item);
        }
        return result;
    }

protected:
    virtual int compare(int current, int candidate) const = 0;
};

// Пошук максимального елементу
class MaxSearch : public SearchAlgorithm {
protected:
    int compare(int current, int candidate) const override {
        return (candidate > current) ? candidate : current;
    }
};

// Пошук мінімального елементу
class MinSearch : public SearchAlgorithm {
protected:
    int compare(int current, int candidate) const override {
        return (candidate < current) ? candidate : current;
    }
};

int main() {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    SearchAlgorithm* searchAlgorithm = new MaxSearch();

    std::cout << "Max: " << searchAlgorithm->findExtreme(data) << std::endl;

    delete searchAlgorithm;
    searchAlgorithm = new MinSearch();

    std::cout << "Min: " << searchAlgorithm->findExtreme(data) << std::endl;

    delete searchAlgorithm;

    return 0;
}
//реалізац. пошук найбільшого та найменшого елементів у масиві.
//Основна мета: Визначення скелету алгоритму в методі, делегування конкретних кроків підкласам.
//Застосування: Коли алгоритм повинен мати фіксовану структуру, але окремі кроки можуть бути змінені в підкласах.
//Характеристики:
//Спрощує створення варіацій алгоритму.
//Скелет алгоритму визначається в базовому класі.
//Підкласам дозволяється змінювати окремі кроки алгоритму.
