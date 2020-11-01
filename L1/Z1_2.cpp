/**
 * №2. Программа с одной переменной.
 */

#include "portability.hpp"

int main() {
    /* Two bytes; range: 0..65535. */
    unsigned short int age;

    p_fix_locale();

    /* This might be the best, and only, story I've written in my life.
       Based on the "real" events of "The Town with No Name". */

    cout << "At club Escapade." << endl << endl;

    cout << "- Give me a drink, bartender." << endl;
    cout << "Bartender stares at you and speaks harshly:" << endl;
    cout << "- How old are you, kid?" << endl;
    cout << "- I am "; cin >> age;
    cout << "- " << age << " years old, huh. Well, let's see..." << endl << endl;

    cout << "He fills a glass and passes it across the table." << endl;
    cout << "You hear a loud crack. The glass slid off and broke." << endl;

    p_getch();
    return 0;
}
