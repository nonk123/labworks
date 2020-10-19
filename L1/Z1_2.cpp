/**
 * №2. Сумма чисел от 1 до N.
 *
 * Сколько последовательных N чисел, начиная с 1, нужно сложить, чтобы их сумма
 * была равна 153?
 */

#include "portability.hpp"

int main() {
    unsigned int expected_sum, sum, N;

    p_fix_locale();

    expected_sum = 153;
    sum = 0;
    N = 0;

    while (sum < expected_sum) {
        sum += ++N;
    }

    /* With e.g. =expected_sum = 152=, =sum= will remain 153.
     *
     * This means there /will/ be overflow, unless `expected_sum` is a sum of
     * integers from 1 to N.
     *
     * No check is done for such cases, as per task explanation.
     */

    cout << "Сумма чисел от 1 до " << N << " равна: " << sum << endl;

    p_getch();
    return 0;
}
