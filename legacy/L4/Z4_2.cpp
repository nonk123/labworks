/**
 * Количество дней с начала года и до введённой даты.
 */

#include "portability.hpp"

int main() {
    p_fix_locale();

    int month, day, days_this_month, total_days;
    int days_per_month[]
        /* JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC */
        = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    do {
        cout << "Введите месяц (от 1 до 12): "; cin >> month;
    } while (month < 1 || month > 12);

    days_this_month = days_per_month[month - 1];

    /* In the original program, the limit was 31 regardless of the month. */
    do {
        cout << "Введите день (от 1 до " << days_this_month << "): ";
        cin >> day;
    } while (day < 1 || day > days_this_month);

    total_days = day;

    for (int i = 0; i < month - 1; i++)
        total_days += days_per_month[i];

    cout << "Общее число дней с начала года: " << total_days << endl;

    p_getch();
    return 0;
}
