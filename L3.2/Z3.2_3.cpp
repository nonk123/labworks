/**
 * №3. Разложение ln(x) в ряд Тейлора.
 */

#include "portability.hpp"

int main() {
    double x, n, fraction, expected;
    double y = 0.;

    int i = 0;

    p_fix_locale();

    do {
        cout << "Введите x: "; cin >> x;
    } while (x <= 0);

    expected = log(x);

    /* Used everywhere in the formula. */
    fraction = (x - 1.) / (x + 1.);

    n = fraction;

    /* Square the fraction for further use. */
    fraction *= fraction;

    do {
        i++;
        y += 2. * n;
        n *= (fraction * (2*i - 1)) / (2*i + 1);
    } while (abs(n) > 1E-9 && abs(y - expected) > 1E-9);

    cout << "ln(" << x << ") = " << y << endl;
    cout << "Количество элементов разложения: " << i << endl;

    p_getch();
    return 0;
}
