/**
 * №4. cos(x) через dx.
 */

#include "portability.hpp"

int main() {
    float x1, x2, x, dx;
    int N, i;

    p_fix_locale();

    do {
        cout << "Начало промежутка: "; cin >> x1;
        cout << "Конец  промежутка: "; cin >> x2;
        cout << "Шаг: "; cin >> dx;
    } while (x2 < x1 || dx < 0);

    N = (int) ceil((x2 - x1) / dx + 1.);

    x = x1;

    cout << endl;

    for (i = 0; i < N; i++) {
        if (x > x2)
            x = x2;

        cout << "cos(" << x << ") = " << cos(x) << endl;
        x += dx;
    }

    p_getch();
    return 0;
}
