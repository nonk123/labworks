/**
 * №9. Перевод температуры.
 *
 * Известно, что перевод шкалы Цельсия в шкалу Фаренгейта осуществляется по
 * некоторой формуле. Необходимо написать программу перевода температуры по
 * Фаренгейту в температуру по Цельсию и обратно.
 */

#include "portability.hpp"

int main() {
    float tF, tC;

    p_fix_locale();

    /* Absolute zero shouldn't be permitted. */
    do {
        cout << "Введите температуру по Фаренгейту: "; cin >> tF;
    } while (tF < -459.67);

    /* Formula straight from the lecture. */
    tC = (5./9.) * (tF - 32.);

    cout << " = " << tC << " градусов Цельсия" << endl;

    /* And back, to see if it's correct. */
    tF = 9.*tC / 5. + 32.;

    cout << " = " << tF << " градусов Фаренгейта (перевод обратно)" << endl;

    p_getch();
    return 0;
}
