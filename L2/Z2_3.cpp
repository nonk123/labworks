/**
 * №3. Окружность с центром в начале координат.
 */

#include "portability.hpp"

int main() {
    /* Slightly modified copy of Z2_1. */

    float r, x, y, percentage;

    unsigned int hit = 0;
    unsigned int missed = 0;

    p_fix_locale();

    for (;;) {
        cout << "r = "; cin >> r;

        if (r < 0.)
            break;

        /* There's only one input you can get wrong. */

        for (;;) {
            cout << endl;

            cout << "x = "; cin >> x;
            cout << "y = "; cin >> y;

            if (x < 0. && y < 0.)
                break;

            if (x < 0. || y < 0.)
                continue;

            cout << endl;

            /* Avoid sqrt and its ugliness. */
            if (x*x + y*y <= r*r) {
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
