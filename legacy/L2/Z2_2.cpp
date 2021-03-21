/**
 * №2. Прямоугольная мишень в точке (x0, y0).
 */

#include "portability.hpp"

int main() {
    /* Since this is a plain copy of Z2_1, refer to that for explanations. */

    int x0, y0, a, b, x, y;

    unsigned int hit = 0;
    unsigned int missed = 0;

    float percentage;

    p_fix_locale();

    for (;;) {
        cout << "x0 = "; cin >> x0;
        cout << "y0 = "; cin >> y0;

        cout << endl;

        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;

        if (x0 < 0 && y0 < 0 && a <= 0 && b <= 0)
            break;

        if (x0 < 0 || y0 < 0 || a <= 0 || b <= 0)
            continue;

        for (;;) {
            cout << endl;

            cout << "x = "; cin >> x;
            cout << "y = "; cin >> y;

            if (x < 0 && y < 0)
                break;

            if (x < 0 || y < 0)
                continue;

            cout << endl;

            /* Offset to keep the old check. */
            x -= x0;
            y -= y0;

            if (x >= 0 && x <= a && y >= 0 && y <= b) {
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
