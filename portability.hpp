/**
 * A small "library" for ensuring Windows-Linux portability.
 *
 * Generally, you'll only use two functions inside `main`, once:
 * - `p_fix_locale` to, well, fix locale settings on Windows.
 * - `p_getch` to "pause" the program, expecting some input.
 *
 * All header files enforced by the teacher are included.
 */

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#endif

#include <iostream>
#include <stdlib.h>
#include <math.h>

#ifdef WINDOWS
#include <conio.h>
#else
#include <stdio.h>
#endif

/* Forced, too. */
using namespace std;

/**
 * Fix locale settings to display Cyrillic without garbling.
 *
 * It seems like this is only required on Windows.
 */
void p_fix_locale() {
#ifdef WINDOWS
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
#endif
}

/**
 * Pause the program until Return (or any key on Windows) is pressed.
 */
void p_getch() {
    cout << endl << "Нажмите Enter, чтобы выйти";

#ifdef WINDOWS
    getch();
#else
    getchar();
#endif
}
