/**
 * Заполнение массива случайными числами.
 */

#include "portability.hpp"

int main() {
    p_fix_locale();
    p_init_srand();

    int n[10];

    for (int i = 0; i < 10; i++) {
        n[i] = rand() % 10; /* x % 10 = [0; 9] */
        cout << n[i] << "  ";
    }

    cout << endl;

    p_getch();
    return 0;
}
