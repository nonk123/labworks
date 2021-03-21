/**
 * №10. Координата тела, брошенного под углом к горизонту.
 *
 * Необходимо расчитать координату тела в заданный момент времени при условии,
 * что тело брошено с начальной скоростью V0 и под углом к горизонту a.
 * Сопротивлением воздуха пренебречь.
 */

#include "portability.hpp"

int main() {
    float x, y, t, V0, alpha;

    float x0 = 0.;
    float y0 = 0.;

    float g = -9.8;

    p_fix_locale();

    /* t = 0 is the starting point; no time travel backwards is allowed.
       Otherwise, the formula should handle any angle and velocity. */
    do {
        cout << "Введите угол a в градусах: "; cin >> alpha;
        cout << "Введите начальную скорость: "; cin >> V0;
        cout << "Введите момент времени: "; cin >> t;
    } while (V0 <= 0. || t < 0. || alpha < 0. || alpha > 360.);

    /* Convert to radians. */
    alpha *= (M_PI / 180.);

    /* This formula assumes there is no ground below the body. */
    x = x0 + V0*t * cos(alpha);
    y = y0 + V0*t * sin(alpha) - 0.5*g*t*t;

    if (t == 0)
        cout << "Начальные координаты: ";
    else
        cout << "В момент времени " << t << " секунд тело окажется в точке ";

    cout << "(" << x << "; " << y << ")" << endl;

    p_getch();
    return 0;
}
