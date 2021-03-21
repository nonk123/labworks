/**
 * №5. ln(x) в N точках.
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
    } while (x2 < x1 || x1 <= 0 || N < 1);

    dx = (x2 - x1) / (N - 1);

    x = x1;

    cout << endl;

    for (i = 0; i < N; i++) {
        cout << "ln(" << x << ") = " << log(x) << endl;
        x += dx;
    }

    p_getch();
    return 0;
}
