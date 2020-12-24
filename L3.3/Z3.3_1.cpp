/**
 * №1. Попадание снаряда в цель.
 */

#include "portability.hpp"

int main() {
    double alpha, V0, R, h, p, t1, y, g = 9.8;

    p_fix_locale();

    do {
        cout << "Угол a в градусах: "; cin >> alpha;
        cout << "Скорость вылёта снаряда: "; cin >> V0;
        cout << "Расстояние до цели: "; cin >> R;
        cout << "Высота подъёма мишени: "; cin >> h;
        cout << "Высота цели: "; cin >> p;
    } while (alpha <= 0. || alpha >= 90.
             || V0 <= 0. || R < 0. || h < 0. || p <= 0.);

    /* Convert to radians */
    alpha *= M_PI / 180.;

    /* Collision time. */
    t1 = R / (V0 * cos(alpha));

    /* Find the Y during collision. */
    y = V0 * t1 * sin(alpha) - 0.5 * g * t1*t1;

    cout << endl;

    /* If it's inside the target, the shot hit. */
    if (y - h >= 1E-9 && y - h <= p)
        cout << "Попал!";
    else
        cout << "Промахнулся!";

    cout << endl;

    p_getch();
    return 0;
}
