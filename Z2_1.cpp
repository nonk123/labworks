/*
 * �1. ���������� ������������ �������.
 *
 * ���� ������� �������� MxN. ���������� ������������ ���������� ������ ���
 * ��������� ����������� ������������ ��������� ���� �������.
 */

#include "common.hpp"

int
main ()
{
  int **A = NULL, *R = NULL;
  int M, N, i, j, k = 0;

  /* ���������� ����� ���������. */
  fix_locale ();

  /* ���� ������� �������. */

  do
    {
      cout << "M = ";
      cin >> M;
    }
  while (M < 2 || M > 15);

  do
    {
      cout << "N = ";
      cin >> N;
    }
  while (N < 2 || N > 15);

  /* ������ ������ ��� �������������� ������. */
  R = new int[M * N];

  if (R == NULL)
    {
      cout << "������ ������� ������" << endl;
      getch ();
      return 1;
    }

  /* ������ ������ ��� ������ ����� �������. */
  A = new int*[M];

  if (A == NULL)
    {
      if (R != NULL)
        {
          delete[] R;
          R = NULL;
        }

      cout << "������ ������� ������" << endl;
      getch ();
      return 1;
    }

  /* ������ ������ ��� ���� ������ �������. */
  for (i = 0; i < M; i++)
    {
      A[i] = new int[N];

      if (A[i] == NULL)
        {
          /* ������������ ����� ����������� ������. */
          if (A != NULL)
            {
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
            }

          if (R != NULL)
            {
              delete[] R;
              R = NULL;
            }

          cout << "������ ������� ������" << endl;
          getch ();
          return 1;
        }
    }

  randomize ();

  cout << endl << "������� A:" << endl;

  /* ���������� ������� ���������� ������� � ����� � ���������. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
        {
          A[i][j] = random (21);
          cout << setw (3) << A[i][j];
        }

      cout << endl;
    }

  cout << endl << "������ R, ���������� ���������� � �������������:" << endl;

  /* ���������� ������������ ��������� �������. */
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++, k++)
      {
        R[k] = A[i][j];
        cout << R[k] << " ";
      }

  cout << endl;

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

      delete[] A;
      A = NULL;
    }

  if (R != NULL)
    {
      delete[] R;
      R = NULL;
    }

  getch ();
  return 0;
}
