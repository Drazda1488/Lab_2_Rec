#include <iostream> 
#include <cmath>    

using namespace std; // Используем пространство имен std 

// Рекурсивная функция вычисления факториала
double fact(int n) {
    if (n == 0) return 1; //  факториал 0 равен 1
    if (n == 1) return 1; //  факториал 1 равен 1
    return n * fact(n - 1); // n! = n * (n-1)!
}

// Рекурсивная функция вычисления суммы ряда 
double calc_sum(double x, int n) {
    const double PI = 3.14159265358979323846; // Объявляем и инициализируем переменную Pi значением числа Pi
    const double COS_PI_DEL_4 = cos(PI / 4.0); // Вычисляем cos(π/4) 

    if (n == 0) {
        return 1; // Первый член ряда равен 1
    }
    else {
        return calc_sum(x, n - 1) + (pow(-1, n) * pow(COS_PI_DEL_4, n) * pow(x, n)) / fact(n); // Возвращаем исходную функцию суммы
    }
}

int main() {
    double x;          // Объявляем переменную для значения x
    int n;             // Объявляем переменную для количества членов ряда

    cout << "Введите значение x: "; // Выводим предложение ввода х
    cin >> x;                    // Ввод х
    cout << "Введите количество членов ряда (n): "; // Выводим предложение ввода n
    cin >> n;                    // Ввод n

    if (n < 0) {                // Проверка на отрицательное количество членов ряда
        cout << "Количество членов ряда не может быть отрицательным." << endl; // Cообщение об ошибке
        return 1;              
    }

    double sum = calc_sum(x, n); // Вычисляем сумму ряда
    cout << "Сумма ряда равна: " << sum << endl; // Выводим результат
    return 0;                  
}
