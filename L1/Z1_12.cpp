/**
 * №12. Высота орбиты спутника Земли.
 *
 * Пусть известна масса Земли и её радиус. Также известна масса спутника и
 * период его обращения вокруг Земли. Необходимо за данный период найти высоту
 * орбиты спутника, который обращается вокруг Земли.
 */

#include "portability.hpp"

int main() {
    float R, M, G, h, T;

    p_fix_locale();

    /* Straight from the task explanation. */
    R = 6.37 * powf(10., 6.);
    M = 5.96 * powf(10., 24.);

    /* Gravitational constant. */
    G = 6.67 * powf(10., -11.);

    /* Aforementioned mass is not required to solve this.
       But, T, the period, cannot be negative or zero. */
    do {
        cout << "Введите период обращения спутника: "; cin >> T;
    } while (T <= 0.);

    /* The derivation process _should_ make it to the report. */
    h = powf((G * M * T*T) / (4. * M_PI*M_PI), 1. / 3.) - R;

    /* It's rotating so fast it went underground. */
    if (h < 0.)
        cout << "Спутник оказался под землёй." << endl;
    else
        cout << "h = " << h / 1000. << " км" << endl;

    p_getch();
    return 0;
}
