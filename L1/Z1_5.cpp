/**
 * №5. Средняя скорость движения тела на всём пути.
 *
 * Расстояние S1 тело преодолело за время t1, а дальшейшее расстояние S1 - за
 * время t2. Найти среднюю скорость движения тела на всём пути.
 */

#include "portability.hpp"

int main() {
    float S1, t1, S2, t2, V_avg;

    p_fix_locale();

    /* Distance and time cannot be negative or zero in this case. */
    do {
        cout << "Введите расстояние S1: "; cin >> S1;
        cout << "Введите время t1: "; cin >> t1;
        cout << "Введите расстояние S2: "; cin >> S2;
        cout << "Введите время t2: "; cin >> t2;
    } while (S1 <= 0. || t1 <= 0. || S2 <= 0. || t2 <= 0.);

    /* Divide the whole distance by the entire time span. */
    V_avg = (S1 + S2) / (t1 + t2);

    cout << endl << "Средняя скорость на всём промежутке пути: " << V_avg << endl;

    p_getch();
    return 0;
}
