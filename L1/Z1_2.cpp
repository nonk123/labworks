/**
 * №2. Сумма чисел от 1 до N.
 *
 * Сколько последовательных N чисел, начиная с 1, нужно сложить, чтобы их сумма
 * была равна заданному числу?
 */

#include "portability.hpp"

int main() {
    unsigned short int expected_sum, sum, N;
    int tmp;

    p_fix_locale();

    /*
     * Accept positive input only.
     *
     * FIXME: entering comically large negative numbers (-99999999999999) starts
     * an infinite loop.
     */
    do {
        cout << "Введите число: "; cin >> tmp;
    } while (tmp < 1);

    expected_sum = (unsigned short int) tmp;
    sum = 0;
    N = 0;

    /* This progression is calculated in a loop because N cannot be factored
       out cleanly from the sum formula (resulting in n^2 + n = 2S). */
    while (sum < expected_sum) {
        sum += ++N;
    }

    cout << "Сумма чисел от 1 до " << N << " равна: " << sum << endl;

    /* Notify about leftover, i.e. =expected_sum= is not a sum of integers
       from 1 to N. */
    if (sum > expected_sum) {
        cout << "Что на " << sum - expected_sum << " больше введённого" << endl;
    } else {
        cout << "Что соответствует введённому" << endl;
    }

    p_getch();
    return 0;
}
