/**
 * №4. Окружность с центром в точке (x0, y0).
 */

#include "portability.hpp"

int main() {
    /* Another plain copy; see Z2_3. */

    float x0, y0, r, x, y, percentage;

    unsigned int hit = 0;
    unsigned int missed = 0;

    p_fix_locale();

    for (;;) {
        cout << "x0 = "; cin >> x0;
        cout << "y0 = "; cin >> y0;

        cout << endl << "r = "; cin >> r;

        if (r < 0. && x0 < 0. && y0 < 0.)
            break;

        if (r < 0. || x0 < 0. || y0 < 0.)
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

            /* Pow is the only reasonable choice here. */
            if (pow(x - x0, 2.) + pow(x - x0, 2.) <= r*r) {
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
