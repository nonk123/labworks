/**
 * №6. Две окружности с центрами в точке (x0, y0).
 */

#include "portability.hpp"

int main() {
    /* Another plain copy; see Z2_1. */

    float x0, y0, r1, r2, x, y, l_sqr, percentage;

    unsigned int hit = 0;
    unsigned int missed = 0;

    p_fix_locale();

    for (;;) {
        cout << "x0 = "; cin >> x0;
        cout << "y0 = "; cin >> y0;

        cout << endl;

        cout << "r1 = "; cin >> r1;
        cout << "r2 = "; cin >> r2;

        if (x0 < 0. && y0 < 0. && r1 < 0. && r2 < 0.)
            break;

        if (x0 < 0. || y0 < 0. || r1 < 0. || r2 < 0.)
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

            l_sqr = pow(x - x0, 2.) + pow(y - y0, 2.);

            if (l_sqr >= r1*r1 && l_sqr <= r2*r2) {
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
