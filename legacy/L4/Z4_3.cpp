/**
 * Среднее арифметическое элементов массива.
 */

#include "portability.hpp"

const int SIZE = 6;

int main() {
    p_fix_locale();

    double sales[SIZE];

    cout << "Введите объём продаж за каждый из шести дней:" << endl;

    for (int i = 0; i < SIZE; i++)
        cin >> sales[i];

    double total = 0.;

    for (int i = 0; i < SIZE; i++)
        total += sales[i];

    double average = total / SIZE;

    cout << "Средний объём: " << average << endl;

    p_getch();
    return 0;
}
