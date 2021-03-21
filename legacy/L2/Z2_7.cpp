/**
 * №6. Функции f(x) и g(x).
 */

#include "portability.hpp"

int main() {
    /* Another plain copy; see Z2_1. */

    float a, k, b, x, y, percentage;

    unsigned int hit = 0;
    unsigned int missed = 0;

    p_fix_locale();

    for (;;) {
        cout << "a = "; cin >> a;
        cout << endl;

        cout << "k = "; cin >> k;
        cout << "b = "; cin >> b;

        /* Horizontal lines are not permitted. */

        if (a <= 0. && k <= 0.)
            break;

        if (a <= 0. || k <= 0.)
            continue;

        for (;;) {
            cout << endl;

            cout << "x = "; cin >> x;
            cout << "y = "; cin >> y;

            if (x < 0. && y < 0.)
                break;

            if (x < 0. || y < 0.)
                continue;

            cout << endl;

            if (y >= a*x*x && y <= k*x + b) {
                cout << "Попал" << endl;
                hit++;
            } else {
                cout << "Промахнулся" << endl;
                missed++;
            }

            percentage = (float) hit / (missed + hit) * 100.;

            cout << "Процент попаданий: " << percentage << "%" << endl;
        }
    }

    p_getch();
    return 0;
}
