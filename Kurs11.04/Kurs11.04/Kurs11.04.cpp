// Kurs11.04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { // задаем функцию
    
    return pow(x, 4) - 16 * x - 64;
}

double df(double x, double h) { // вычисляем производную функции
    return (f(x + h) - f(x - h)) / (2 * h);
}

double newton(double x, double eps, double h) { // алгоритм Ньютона
    int iterations = 0; // счетчик итераций 
    double curr_x = x; // текущее значение
    double prev_x = x + 1; // предыдущее значение
    double prev_f = f(prev_x); // значение функции на предыдущей итерации
    while (abs(curr_x - prev_x) > eps) {// пока не достигнута заданная точность
        prev_x = curr_x; //сохраняем текущее значение
        double curr_f = f(prev_x); // вычисляем значение функции в текущей точке
        double curr_df = df(prev_x, h);// вычисляем значение производной в текущей точке
        if (abs(curr_df) < eps) { // проверка на сходимость
            cout << "Ошибка: производная функции слишком близка к нулю." << endl;
            return prev_x;
        }
        curr_x = prev_x - curr_f / curr_df;  // вычисляем следующее приближение
        double ratio = abs(curr_f - prev_f) / abs(prev_f);
        if (ratio < eps) { // проверка на сходимость
            cout << "Алгоритм сошелся на итерации " << iterations << "." << endl;
            break;
        }
        prev_f = curr_f;
        iterations++;
    }
    cout << "Результат алгоритма Ньютона (итераций: " << iterations << "): ";
    return curr_x;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    double x = 0; // начальное приближение
    double eps = 0; // точность
    double h = 0.0001; // шаг для численного дифференцирования
    double result;
    cout << "Введите начальное приближение: ";
    cin >> x;
    cout << "Введите точность: ";
    cin >> eps;
    if (eps == 0) { // проверка на ноль
        cout << "Ошибка: введена нулевая точность." << endl;

        return 0;
    }
    result = newton(x, eps, h); // вызываем алгоритм Ньютона
    cout << result << endl;
    return 0;
    
}


