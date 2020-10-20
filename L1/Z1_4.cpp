/**
 * №4. Координата тела, брошенного под углом к горизонту.
 *
 * Необходимо расчитать координату тела в заданный момент времени при условии,
 * что тело брошено с начальной скоростью V0 и под углом к горизонту a.
 * Сопротивлением воздуха пренебречь.
 */

#include "portability.hpp"

int main() {
    float x, y, g, t, V0, alpha_deg, alpha_rad;

    p_fix_locale();

    /* t = 0 is the starting point; no time travel (backwards) allowed.
       V0 cannot be negative, but 0 is fine: the body simply stays still.
       alpha is between 0 and 180 inclusively (no downward movement). */
    do {
        cout << "Введите угол a в градусах: "; cin >> alpha_deg;
        cout << "Введите начальную скорость: "; cin >> V0;
        cout << "Введите момент времени: "; cin >> t;
    } while (t < 0. || V0 < 0. || alpha_deg > 180. || alpha_deg < 0.);

    g = 9.8;

    alpha_rad = alpha_deg * (M_PI / 180.);

    x = V0*t * cos(alpha_rad);
    y = V0*t * sin(alpha_rad) + (g*t*t)/2.;

    cout << "В момент времени " << t << " секунд тело окажется в точке ";
    cout << "(" << x << "; " << y << ")" << endl;

    p_getch();
    return 0;
}
