/**
 * Показ графика продаж.
 */

#include "portability.hpp"

const int DISTRICTS = 4;
const int MONTHS = 3;

int main() {
    p_fix_locale();

    double sales[DISTRICTS][MONTHS];

    for (int district = 0; district < DISTRICTS; district++) {
        cout << "Введите объём продаж для отдела " << district + 1 << endl;

        for (int month = 0; month < MONTHS; month++) {
            cout << "  За месяц " << month + 1 << ": ";
            cin >> sales[district][month];
        }
    }

    cout << endl;

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
