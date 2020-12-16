/**
 * Показ графика продаж с помощью инициализации массива.
 */

#include "portability.hpp"

const int DISTRICTS = 4;
const int MONTHS = 3;

int main() {
    p_fix_locale();

    double sales[DISTRICTS][MONTHS] = {
        { 1432.07,   234.50,   654.01},
        {  322.00, 13838.32, 17589.88},
        { 9328.34,   934.00,  4492.30},
        {12838.29,  2332.63,    32.93},
    };

    cout << "Месяц        1         2         3" << endl;

    for (int district = 0; district < DISTRICTS; district++) {
        cout << "Отдел " << district + 1;

        for (int month = 0; month < MONTHS; month++) {
            /* Special formatting. */
            cout << setiosflags(ios::fixed)
                 << setiosflags(ios::showpoint)
                 << setprecision(2)
                 << setw(10)
                 << sales[district][month];
        }

        cout << endl;
    }

    p_getch();
    return 0;
}
