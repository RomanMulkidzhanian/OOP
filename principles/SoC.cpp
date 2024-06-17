class DataAccess {
public:
    std::string getData() const {
        // Отримання даних з бази даних
        return "Data from database";
    }
};

class BusinessLogic {
public:
    void processData(const std::string& data) {
        // Обробка даних
        std::cout << "Processing: " << data << std::endl;
    }
};
//Принцип розділення занепокоєнь (SoC) означає, що різні аспекти програми повинні бути відокремлені один від одного,
// щоб зміни в одному аспекті не впливали на інші. Це дозволяє зменшити складність системи і полегшити її підтримку.