// Погано: складна логіка для визначення простого умовного виразу
if ((x > y && y < z) || (x < y && y > z)) {
    // ...
}

// Краще: простий умовний вираз, який легше зрозуміти
if (x != y && y != z) {
    // ...
}
//Принцип KISS закликає до того, щоб система була як можна простішою, легше зрозумілою та менше схильною до помилок.
// Це означає, що розробники повинні віддавати перевагу простим рішенням перед складними, якщо це можливо.