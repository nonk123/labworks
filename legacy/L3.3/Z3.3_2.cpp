#include "portability.hpp"

int main() {
    double x, n, cos_x, sin_x, fraction, y;
    int i;

    p_fix_locale();

    cout << "Введите x = 0, чтобы выйти." << endl;

    for (;;) {
        cout << endl << "x = "; cin >> x;

        if (x == 0.)
            break;

        /* cos(x). */

        cos_x = 0.;

        i = 0;
        n = 1.;

        do {
            i++;
            cos_x += n;
            n *= -(x*x) / (2*i - 1) / (2*i);
        } while (abs(n) > 1E-9);

        if (abs(cos_x) <= 1E-9) {
            cout << "Функция в точке x не существует." << endl;
            continue;
        }

        /* sin(x). */

        sin_x = 0.;

        i = 0;
        n = x;

        do {
            i++;
            sin_x += n;
            n *= -(x*x) / (2*i + 1) / (2*i);
        } while (abs(n) > 1E-9);

        fraction = (1. + sin_x) / cos_x;

        cout << sin_x << " " << cos_x << endl;

        /* ln(fraction). */

        if (fraction <= 1E-9) {
            cout << "Функция в точке x не существует." << endl;
            continue;
        }

        fraction = (fraction - 1.) / (fraction + 1.);

        y = 0.;

        i = 0;
        n = fraction;

        fraction *= fraction;

        do {
            i++;
            y += 2. * n;
            n *= (fraction * (2*i - 1)) / (2*i + 1);
        } while (abs(n) > 1E-9);

        /* 1. / ln(fraction). */

        if (abs(y) <= 1E-9) {
            cout << "Функция в точке x не существует." << endl;
            continue;
        }

        y = 1. / y;

        cout << "y = " << y << endl;
    }

    p_getch();
    return 0;
}
