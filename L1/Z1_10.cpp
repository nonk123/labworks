/**
 * №10. Координата тела, брошенного под углом к горизонту.
 *
 * Необходимо расчитать координату тела в заданный момент времени при условии,
 * что тело брошено с начальной скоростью V0 и под углом к горизонту a.
 * Сопротивлением воздуха пренебречь.
 */

#include "portability.hpp"

int main() {
    float x0, y0, x, y, g, t, V0, alpha_deg, alpha_rad;

    p_fix_locale();

    /* t = 0 is the starting point; no time travel backwards is allowed.
       Otherwise, the formula should handle any angle and velocity. */
    do {
        cout << "Введите угол a в градусах: "; cin >> alpha_deg;
        cout << "Введите начальную скорость: "; cin >> V0;
        cout << "Введите момент времени: "; cin >> t;
    } while (t < 0.);

    x0 = 0.;
    y0 = 0.;

    g = -9.8;

    alpha_rad = alpha_deg * (M_PI / 180.);

    /* This formula assumes there is no ground below the body. */
    x = x0 + V0*t * cos(alpha_rad);
    y = y0 + V0*t * sin(alpha_rad) + (g*t*t)/2.;

    if (t == 0)
        cout << "Начальные координаты: ";
    else
        cout << "В момент времени " << t << " секунд тело окажется в точке ";

    cout << "(" << x << "; " << y << ")" << endl;

    p_getch();
    return 0;
}
