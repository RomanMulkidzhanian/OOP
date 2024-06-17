#include <iostream>
#include <string>
#include <unordered_map>

// Abstract Expression
class Expression {
public:
    virtual int interpret(const std::unordered_map<std::string, int> &context) = 0;
};

// Terminal Expression
class Number : public Expression {
private:
    int number;
public:
    Number(int number) : number(number) {}
    int interpret(const std::unordered_map<std::string, int> &context) override {
        return number;
    }
};

// Non-Terminal Expression
class Add : public Expression {
private:
    Expression *leftExpression;
    Expression *rightExpression;
public:
    Add(Expression *left, Expression *right) : leftExpression(left), rightExpression(right) {}
    int interpret(const std::unordered_map<std::string, int> &context) override {
        return leftExpression->interpret(context) + rightExpression->interpret(context);
    }
};

int main() {
    Expression *expression = new Add(new Number(5), new Number(10));
    std::unordered_map<std::string, int> context;
    std::cout << "Result: " << expression->interpret(context) << "\n";

    delete expression;
    return 0;
}

//#### Призначення:
//- **Основна мета**: Визначення граматики для мови та інтерпретація речень цієї мови.
//- **Застосування**: Коли потрібно інтерпретувати речення мови з визначеною граматикою.
//- **Характеристики**:
 // - Забезпечує спосіб аналізу та виконання речень мови.
 // - Дозволяє легко розширювати граматику мови.
  //- Включає синтаксичне дерево та метод інтерпретації.