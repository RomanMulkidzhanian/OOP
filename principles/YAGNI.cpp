class User {
public:
    std::string getName() const {
        return name;
    }
    // Не додавайте метод getAge(), поки він не знадобиться
private:
    std::string name;
};
//Принцип YAGNI каже, що не варто додавати функціональність до програмного забезпечення, поки в ній немає необхідності. Це допомагає уникнути зайвої складності та зайвих витрат часу.
