/*
 * �1. ���������� ������������� �������� � ������� � �������������� ����������.
 *
 * ����� ������������� ������. ���������� ���������� �������� ��� �������������
 * ��������� � �� ������� � �������������� ������� � ��������� �����������
 * ����������.
 */

#include "common.hpp"

int
main ()
{
  int* array = NULL;
  int len, i, max_val, min_val, max_idx, min_idx;

  /* ���������� ����� ���������. */
  fix_locale ();

  do
    {
      cout << "����� ������� (�� ����� 100 ���������): ";
      cin >> len;
    }
  while (len <= 0 || len > 100);

  /* ������ ������ ��� ������. */
  array = new int[len];

  /* �� �����-�� �������� ������ �� ����������. ��������� �� ����� ����������
     ���� ������. */
  if (array == NULL)
    {
      cout << "������ ������� ������" << endl;
      getch ();
      return 1;
    }

  /* ������������� ���������� ��������� �����. */
  randomize ();

  cout << endl << "����������� ������:" << endl;

  /* ���������� � ��������� �������. */
  for (i = 0; i < len; i++)
    {
      /* ���������� ���������� ������� � ��������� [-50; 50]. */
      array[i] = random (101) - 50;

      /* ����� �������� ������ ������ 10 ���������. */
      if (i && !(i % 10))
        cout << endl;
      else if (i)
        cout << " ";

      /* ����� �������� ��������. */
      cout << setw(3) << array[i];
    }

  max_val = min_val = array[0];
  max_idx = min_idx = 0;

  /* ����� ������������� ��������. */
  for (i = 1; i < len; i++)
    {
      /* �������, ������� �� �������� ����� ���������� ��������, � ���� �������
         �� ������ ��������. */
      if (array[i] < min_val)
        {
          min_val = array[i];
          min_idx = i;
        }

      /* ���������� � ����������. */
      if (array[i] > max_val)
        {
          max_val = array[i];
          max_idx = i;
        }
    }

  cout << endl;

  cout << endl << "�������� ������������� ��������: " << max_val;
  cout << endl << "��� ������: " << max_idx << endl;

  cout << endl << "�������� ������������ ��������: " << min_val;
  cout << endl << "��� ������: " << min_idx << endl;

  /* ������������ ����� ����������� ������. */
  if (array != NULL)
    {
      delete[] array;
      array = NULL;
    }

  getch ();
  return 0;
}