/**
 * №6. Решение треугольника по трём сторонам.
 */

#include "portability.hpp"

int main() {
    float a, b, c, A_rad, B_rad, C_rad, A_deg, B_deg, C_deg, S, P;

    p_fix_locale();

    /* No side of a triangle is greater than the sum of two other. */
    do {
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
    } while (a >= b + c || a <= b - c
             || b >= a + c || b <= a - c
             || c >= a + b || c <= a - b);

    /* Mathe-magics. */
    A_rad = acos((b*b + c*c - a*a) / (2.*b*c));
    B_rad = acos((a*a + c*c - b*b) / (2.*a*c));
    C_rad = M_PI - (A_rad + B_rad);

    /* Convert it to degrees. */
    A_deg = 180. * A_rad / M_PI;
    B_deg = 180. * B_rad / M_PI;
    C_deg = 180. * C_rad / M_PI;

    /* Top off with more magic. */
    S = a * b * 0.5*sin(C_rad);
    P = a + b + c;

    /* And "pretty"-print. */
    cout << endl;

    cout << "A = " << A_rad << " радиан (" << A_deg << " градусов)" << endl;
    cout << "B = " << B_rad << " радиан (" << B_deg << " градусов)" << endl;
    cout << "C = " << C_rad << " радиан (" << C_deg << " градусов)" << endl << endl;

    cout << "S = " << S << endl;
    cout << "P = " << P << endl;

    p_getch();
    return 0;
}
