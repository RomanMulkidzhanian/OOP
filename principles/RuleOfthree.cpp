class Resource {
private:
    int* data;
public:
    Resource() : data(new int[100]) {}
    ~Resource() { delete[] data; }

    // Конструктор копіювання
    Resource(const Resource& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Оператор присвоєння
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete[] data;
            data = new int[100];
            std::copy(other.data, other.data + 100, data);
        }
        return *this;
    }

    // Конструктор переміщення (додано в C++11)
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Оператор переміщення (додано в C++11)
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};

//Rule of ThreeПравило трьох (правило п'яти в C++11) вказує на необхідність визначення конструктора копіювання, оператора присвоєння та деструктора, якщо ви вручну реалізуєте один з них.
// У C++11 це правило розширено до "правила п'яти", яке також включає переміщення конструктора та переміщення оператора присвоєння.