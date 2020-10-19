/**
 * №1. Решение треугольника по двум сторонам и углу между ними.
 *
 * Необходимо решить треугольник по двум сторонам и углу между ними.
 */

#include "portability.hpp"

#define RAD_TO_DEG (180. / M_PI)
#define DEG_TO_RAD (1. / RAD_TO_DEG)

int main() {
    float a, b, c, A_rad, B_rad, C_rad, A_deg, B_deg, C_deg, S, P;

    p_fix_locale();

    /* FIXME: read from stdin? */
    a = 5.;
    b = 7.;
    C_rad = 82. * DEG_TO_RAD;

    /* Find the third side. */
    c = sqrt(a*a + b*b - 2.*a*b * cos(C_rad));

    /* And solve normally, just like in the lecture. */
    A_rad = acos((b*b + c*c - a*a) / (2.*b*c));
    B_rad = acos((a*a + c*c - b*b) / (2.*a*c));
    /* C_rad is already known. */

    S = 0.5 * a*b * sin(C_rad);
    P = a + b + c;

    /* Convert to degrees because why not. */
    A_deg = A_rad * RAD_TO_DEG;
    B_deg = B_rad * RAD_TO_DEG;
    C_deg = C_rad * RAD_TO_DEG;

    /* Pretty-print the results. */

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl << endl;

    cout << "A = " << A_rad << " рад или " << A_deg << " град" << endl;
    cout << "B = " << B_rad << " рад или " << B_deg << " град" << endl;
    cout << "C = " << C_rad << " рад или " << C_deg << " град" << endl << endl;

    cout << "P = " << P << endl;
    cout << "S = " << S << endl;

    p_getch();
    return 0;
}
