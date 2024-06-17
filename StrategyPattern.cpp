#include <iostream>
#include <vector>
#include <algorithm>

// Інтерфейс стратегії сортування
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) const = 0;
    virtual ~SortingStrategy() = default;
};

// Стратегія сортування за зростанням
class AscendingSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::sort(data.begin(), data.end());
    }
};

// Стратегія сортування за спаданням
class DescendingSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::sort(data.begin(), data.end(), std::greater<int>());
    }
};

// Контекст для використання стратегії
class Sorter {
private:
    SortingStrategy* strategy;

public:
    Sorter(SortingStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortingStrategy* newStrategy) {
        delete strategy;
        strategy = newStrategy;
    }

    void sort(std::vector<int>& data) const {
        strategy->sort(data);
    }

    ~Sorter() {
        delete strategy;
    }
};

int main() {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    Sorter sorter(new AscendingSort());

    sorter.sort(data);
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sorter.setStrategy(new DescendingSort());
    sorter.sort(data);
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
//сортуваyння масива чисел за зростанням або спаданням.
//Основна мета: Визначення сімейства алгоритмів, упакування їх у класи та забезпечення їх взаємозамінності.
//Застосування: Коли необхідно мати можливість вибору різних алгоритмів для виконання конкретної задачі.
//Характеристики:
//Інкапсулює алгоритми.
//Забезпечує можливість заміни алгоритму під час виконання програми.
//Спрощує додавання нових алгоритмів.