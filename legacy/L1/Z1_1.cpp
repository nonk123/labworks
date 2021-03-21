/**
 * №1. Вывод текста приветствия.
 */

#include "portability.hpp"

int main() {
    p_fix_locale();

    cout << "Hello, world!" << endl;

    p_getch();
    return 0;
}
