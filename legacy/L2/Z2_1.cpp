/**
 * №1. Прямоугольная мишень в точке (0, 0).
 */

#include "portability.hpp"

int main() {
    int a, b, x, y;

    unsigned int hit = 0;
    unsigned int missed = 0;

    float percentage;

    p_fix_locale();

    /* Input mainloop. */
    for (;;) {
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;

        /* Magic value to stop the mainloop. */
        if (a <= 0 && b <= 0)
            break;

        /* Accept positive inputs only. */
        if (a <= 0 || b <= 0)
            continue;

        for (;;) {
            cout << endl;

            cout << "x = "; cin >> x;
            cout << "y = "; cin >> y;

            /* Magic-value and positive input checks. */

            if (x < 0 && y < 0)
                break;

            if (x < 0 || y < 0)
                continue;

            cout << endl;

            /* Point-in-rectangle collision. */
            if (x >= 0 && x <= a && y >= 0 && y <= b) {
                cout << "Попал" << endl;
                hit++;
            } else {
                cout << "Промахнулся" << endl;
                missed++;
            }

            /* Hit count divided by total shots, in percent. */
            percentage = (float) hit / (missed + hit) * 100.;

            cout << "Процент попаданий: " << percentage << "%" << endl;
        }
    }

    p_getch();
    return 0;
}
