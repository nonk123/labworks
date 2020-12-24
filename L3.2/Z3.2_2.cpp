/**
 * №2. Разложение cos(x) в ряд Маклорена.
 */

#include "portability.hpp"

int main() {
    double x, n, expected;
    double y = 0.;

    int i = 0;

    p_fix_locale();

    cout << "x = "; cin >> x;

    expected = cos(x);

    /* q_0 = 1 */
    n = 1;

    do {
        i++;
        y += n;
        /* q_n = q_{n - 1} * c */
        n *= -(x*x) / (2*i - 1) / (2*i);
    } while (abs(n) > 1E-9 && abs(y - expected) > 1E-9);

    cout << "cos(" << x << ") = " << y << endl;
    cout << "Количество элементов разложения: " << i << endl;

    p_getch();
    return 0;
}
