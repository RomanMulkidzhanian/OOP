class BankAccount {
private:
    double balance;
public:
    void deposit(double amount) {
        balance += amount;
    }
    double getBalance() const {
        return balance;
    }
};
//Приховування інформації означає, що внутрішні деталі реалізації
// об'єкта повинні бути приховані від зовнішніх користувачів. Це дозволяє змінювати реалізацію без впливу на код, який використовує цей об'єкт.