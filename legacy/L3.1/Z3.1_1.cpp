/**
 * №1. sin(x) в N точках.
 */

#include "portability.hpp"

int main() {
    float x1, x2, x, dx;
    int N, i;

    p_fix_locale();

    do {
        cout << "Начало промежутка: "; cin >> x1;
        cout << "Конец  промежутка: "; cin >> x2;
        cout << "Количество  точек: "; cin >> N;
    } while (x2 < x1 || N < 1);

    /* Epicly taken from the epic lecture. */
    dx = (x2 - x1) / (N - 1);

    x = x1;

    cout << endl;

    for (i = 0; i < N; i++) {
        cout << "sin(" << x << ") = " << sin(x) << endl;
        x += dx;
    }

    p_getch();
    return 0;
}
