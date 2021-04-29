#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include <windows.h>

/* random() and randomize() are not defined on university computers. */

#ifndef randomize
#define randomize() (srand (time (NULL)))
#endif /* randomize */

#ifndef random
#define random(X) (rand () % (X))
#endif /* random */

/* Using getch() instead of _getch() produces a lot of warnings. */
#define getch _getch

inline void
fix_locale ()
{
  SetConsoleCP (1251);
  SetConsoleOutputCP (1251);
}

using namespace std;

#endif /* COMMON_HPP */
