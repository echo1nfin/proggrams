#include <iostream>
#include <cmath>

using namespace std;

// Функция, представляющая уравнение x = g(x)
double g(double x) {
    return x - sin(x) / (-2.0); // Выберем k=-2
}

// Метод итераций
double iterativeMethod(double x0, int maxIterations, double eps) {
    double currentX = x0;

    for (int i = 0; i < maxIterations; ++i) {
        double nextX = g(currentX);

        if (fabs(nextX - currentX) < eps) {
            // Критерий сходимости достигнут
            return nextX;
        }

        currentX = nextX;
    }

    // Возвращаем текущее приближение, даже если не достигнута сходимость
    return currentX;
}

int main() {
    double a = 1.0;
    double b = 4.0;
    int maxIterations = 1000;
    double eps = 1e-6;

    // Начальное приближение выбираем посередине отрезка
    double x0 = (a + b) / 2.0;

    // Вызываем метод итераций
    double x = iterativeMethod(x0, maxIterations, eps);

    // Выводим результат
    cout << "Корень уравнения y = sin(x) на отрезке [1;4]: " << x << endl;

    return 0;
}
