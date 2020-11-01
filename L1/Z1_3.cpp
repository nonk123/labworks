/**
 * №3. Ввод значения переменной с проверкой.
 */

#include "portability.hpp"

int main() {
    unsigned short int age;
    int tmp;

    p_fix_locale();

    cout << "How old art thou, peasant?" << endl;

    /* Well, duh. A person's age is _usually_ in the range of 1..100. */
    do {
        cout << "Give me a straight answer: "; cin >> tmp;
    } while (tmp <= 0 || tmp > 100);

    age = (unsigned short int) tmp;

    cout << "Good. Thy age is " << age << " slave-years." << endl;

    p_getch();
    return 0;
}
