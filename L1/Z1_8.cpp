/**
 * №8. Сумма чисел от 1 до N.
 *
 * Сколько последовательных N чисел начиная с 1 нужно сложить, чтобы их сумма
 * была равна заданному числу?
 */

#include "portability.hpp"

int main() {
    unsigned short int E, S, N;
    int tmp;

    p_fix_locale();

    /* Accept positive, short int input only. */
    do {
        cout << "Введите число: "; cin >> tmp;
    } while (tmp <= 0 || tmp > 65535);

    E = (unsigned short int) tmp;

    N = (unsigned short int) ceilf(0.5 * (sqrt(1 + 8*E) - 1.));

    S = N * (1 + N) / 2;

    cout << "Сумма чисел от 1 до " << N << " равна: " << S << endl;

    /* Notify about leftover, i.e. E is not a sum of integers from 1 to N. */
    if (S > E)
        cout << "Что на " << S - E << " больше введённой" << endl;
    else
        cout << "Что соответствует введённой" << endl;

    p_getch();
    return 0;
}
