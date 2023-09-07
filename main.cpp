#include <iostream>
using namespace std;

class Fraction {
private:
    int n;   
    int d;   

public:
    Fraction(int num = 0, int den = 1) : n(num), d(den) {
        if (d == 0) {
            cout << "Ошибка: Знаменатель не может быть равен нулю." << endl;
           
        }
    
    }

    void simplify() {
        int gcd = findGCD(n, d);
        n /= gcd;
        d /= gcd;
    }

    int findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }

    void display() const {
        cout << n << "/" << d;
    }

    void input() {
        cout << "Введите числитель: ";
        cin >> n;
        cout << "Введите знаменатель (не равный нулю): ";
        cin >> d;
        if (d == 0) {
            cout << "Ошибка: Знаменатель не может быть равен нулю." << endl;
        }
       
    }

    Fraction add(const Fraction& other) const {
        int newNumerator = n * other.d + other.n * d;
        int newDenominator = d * other.d;
        Fraction result(newNumerator, newDenominator);
        return result;
    }

    Fraction subtract(const Fraction& other) const {
        int newNumerator = n * other.d - other.n * d;
        int newDenominator = d * other.d;
        Fraction result(newNumerator, newDenominator);
        return result;
    }

    Fraction multiply(const Fraction& other) const {
        int newNumerator = n * other.n;
        int newDenominator = d * other.d;
        Fraction result(newNumerator, newDenominator);
        return result;
    }

    Fraction divide(const Fraction& other) const {
        if (other.n == 0) {
            cout << "Ошибка: Деление на ноль." << endl;
        }
        int newNumerator = n * other.d;
        int newDenominator = d * other.n;
        Fraction result(newNumerator, newDenominator);
        return result;
    }
};

int main() {
    int choice;
    Fraction fraction1;
    Fraction fraction2;
    fraction1.input();
    fraction2.input();

    Fraction result;

    cout << "Выберите операцию:" << endl;
    cout << "1. Сложение" <<"  ";
    cout << "2. Вычитание" << endl;
    cout << "3. Умножение" <<"  ";
    cout << "4. Деление" << endl;
    cin >> choice;


    switch (choice) {
        case 1:
            result = fraction1.add(fraction2);
            cout << "Сумма: ";
            break;
        case 2:
            result = fraction1.subtract(fraction2);
            cout << "Разность: ";
            break;
        case 3:
            result = fraction1.multiply(fraction2);
            cout << "Произведение: ";
            break;
        case 4:
            result = fraction1.divide(fraction2);
            cout << "Частное: ";
            break;
    }

    result.display();
    cout << endl;

    return 0;
}