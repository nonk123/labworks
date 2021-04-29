/*
 * �4. ���������������� �������� ���������� �������.
 */

#include "common.hpp"

int
main ()
{
  int **A, M, i, j;

  /* ���������� ����� ���������. */
  fix_locale ();

  /* ���� ������� �������. */
  do
    {
      cout << "M = ";
      cin >> M;
    }
  while (M < 2 || M > 15);

  /* ������ ������ ��� �������. */
  A = new int*[M];

  if (A == NULL)
    {
      cout << "������ ������� ������" << endl;
      getch ();
      return 1;
    }

  for (i = 0; i < M; i++)
    {
      A[i] = new int[M];

      if (A[i] == NULL)
        {
          /* ������������ ����� ����������� ������. */
          for (j = 0; j < i; j++)
            {
              if (A[j] != NULL)
                {
                  delete[] A[j];
                  A[j] = NULL;
                }
            }

          delete[] A;
          A = NULL;

          cout << "������ ������� ������" << endl;
          getch ();
          return 1;
        }
    }

  cout << endl << "������� A:" << endl;

  /* ���������� � ����� �������. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < M; j++)
        {
          A[i][j] = random (21);
          cout << setw (3) << A[i][j];
        }

      cout << endl;
    }

  /* ���������������� �������. */
  for (i = 0; i < M; i++)
    for (j = i; j < M; j++)
      {
        int tmp = A[i][j];
        A[i][j] = A[j][i];
        A[j][i] = tmp;
      }

  cout << endl << "����������������� ������� A:" << endl;

  /* ����� ����������������� �������. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < M; j++)
        cout << setw (3) << A[i][j];

      cout << endl;
    }

  /* ������������ ����� ����������� ������. */
  if (A != NULL)
    {
      for (i = 0; i < M; i++)
        {
          if (A[i] != NULL)
            {
              delete[] A[i];
              A[i] = NULL;
            }
        }

      delete[] A[i];
      A[i] = NULL;
    }

  getch ();
  return 0;
}
