/**
 * A small "library" for ensuring Windows-Linux portability.
 *
 * Generally, you'll only use two functions inside `main`, once:
 *  * p_fix_locale() to, well, fix locale settings on Windows.
 *  * p_getch() to "pause" the program, expecting some input.
 *
 * All header-files enforced by the teacher are included.
 */

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#endif

#include <iostream> /* std::cout and std::cin */
#include <iomanip>  /* std::setiosflags() and Co. */
#include <stdlib.h> /* basic functions */
#include <math.h>   /* self-explanatory */

#include <time.h>   /* time() for srand() */

/* Windows's console I/O library, the main source of incompatibility. */
#ifdef WINDOWS
#include <conio.h>
#endif

/* Forced, too. */
using namespace std;

/**
 * Fix locale settings to display Cyrillic without garbling.
 */
void p_fix_locale() {
#ifdef WINDOWS
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
#else
    /* Default locale settings are fine. */
#endif
}

/**
 * Initialize random seed with srand().
 */
void p_init_srand() {
    srand(time(NULL));
}

/**
 * Pause the program until Return is pressed.
 */
void p_getch() {
#ifdef WINDOWS
    cout << endl << "Нажмите Enter, чтобы выйти";
    getch();
#else
    /* Unneeded on Linux. */
#endif
}
