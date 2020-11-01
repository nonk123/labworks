/**
 * №4. Расчёт высоты подъёма тела.
 */

#include "portability.hpp"

int main() {
    double h;

    double g = 9.8;
    double V = 10.;
    double t = 1.;

    p_fix_locale();

    h = V*t - 0.5*g*t*t;

    cout << "Thou hast ascended to " << h << " meters." << endl;

    p_getch();
    return 0;
}
