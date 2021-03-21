/**
 * №5. Пример использвания инкрементных и декрементных операторов.
 */

#include "portability.hpp"

int main() {
    int n, m, i, j;

    p_fix_locale();

    cout << "> i = "; cin >> i;

    n = i++; /* n = i; i += 1; */

    cout << "n = " << n << endl;
    cout << "i = " << i << endl << endl;

    cout << "> j = "; cin >> j;

    m = ++j; /* j += 1; m = j; */

    cout << "m = " << m << endl;
    cout << "j = " << j << endl << endl;

    /*
     * Essentially the same as:
     * i -= 1;
     * n = i * i;
     * i -= 1;
     */
    n = (--i) * (i--);

    cout << "n = " << n << endl;
    cout << "i = " << i << endl;

    p_getch();
    return 0;
}
