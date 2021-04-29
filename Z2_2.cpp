/*
 * �2. ������������ ������������� �������.
 *
 * ���� ������� �������� MxN. ���������� ������������ �� �� ���������� ������
 * ����������� ������������ � ��������� ����� ���������:
 *   1. ������ ������� ����������� ������ ����. ������ - ����� �����. ������ -
 *      ��� ������. � �.�.
 *   2. ������ ������� ����������� ����� �������. ������ - ������ ������.
 *      ������ - ��� ������. � �.�.
 */

#include "common.hpp"

/*
 * ������� ������������ ���������� ������������� ������� (�������).
 *
 * ������� ���������:
 *   A - ������ ����� ��������� �������;
 *   M - ����� ����� � ���.
 *
 * ������������ �������� - ��� ����������:
 *   0 - �������� ���������� �������;
 *   1 - ������� �������� M ������ ����.
 *
 * �����������: ������� �.�.
 * ������: 1.0
 * ����: 13.04.21
 */
int
free_matrix (int** A, int M)
{
  int i;

  if (A == NULL)
    return 0;

  if (M < 0)
    return 1;

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

  return 0;
}

/*
 * ������� ������������ ������� �� ���������.
 *
 * ������� ���������:
 *   R - ������, ���������� ����������� ������������ �������;
 *   A - �������, ������� ���������� ��������������;
 *   M, N - ���������� ����� � �������� � ��� ��������������.
 *
 * ������������ �������� - ��� ����������:
 *   0 - �������� ���������� �������;
 *   1 - �� ��������� R �� ��������� ������;
 *   2 - �� ��������� A �� ��������� ������;
 *   3 - ������� �� �������� ���������.
 *
 * ����������:
 *   ����������� ������ �� ��������� R ������ ������� �� M * N ���������.
 *
 * ��������:
 *   ����������� ������������ �������� ����� ������� ��������. ��� �����
 *   ����������� ��� ��������� �����.
 *
 * �����������: ������� �.�.
 * ������: 1.0
 * ����: 13.04.21
 */
int
scan_cols (int* R, int** A, int M, int N)
{
  int i, j, k = 0;

  if (R == NULL)
    return 1;

  if (A == NULL)
    return 2;

  if (M <= 0 || N <= 0)
    return 3;

  for (j = 0; j < N; j++)
    {
      if (j % 2) /* ������� 1, 3, 5, ... */
        {
          for (i = M - 1; i >= 0; i--, k++)
            R[k] = A[i][j];
        }
      else /* ������� 0, 2, 4, ... */
        {
          for (i = 0; i < M; i++, k++)
            R[k] = A[i][j];
        }
    }

  return 0;
}

/*
 * ������� ����������� ������������ �������.
 *
 * ������� ���������:
 *   R - ������, ���������� ����������� ������������ �������;
 *   A - �������, ������� ���������� ��������������;
 *   M, N - ���������� ����� � �������� � ��� ��������������.
 *
 * ������������ �������� - ��� ����������:
 *   0 - �������� ���������� �������;
 *   1 - �� ��������� R �� ��������� ������;
 *   2 - �� ��������� A �� ��������� ������;
 *   3 - ������� �� �������� ���������.
 *
 * ����������:
 *   ����������� ������ �� ��������� R ������ ������� �� M * N ���������.
 *
 * ��������:
 *   ����������� ������������ �������� ����� ������ �������. ��� �����
 *   ����������� ��� ��������� �����.
 *
 * �����������: ������� �.�.
 * ������: 1.0
 * ����: 13.04.21
 */
int
scan_rows (int* R, int** A, int M, int N)
{
  int i, j, k = 0;

  if (R == NULL)
    return 1;

  if (A == NULL)
    return 2;

  if (M <= 0 || N <= 0)
    return 3;

  for (i = 0; i < M; i++)
    {
      if (i % 2) /* ������� 1, 3, 5, ... */
        {
          for (j = N - 1; j >= 0; j--, k++)
            R[k] = A[i][j];
        }
      else /* ������� 0, 2, 4, ... */
        {
          for (j = 0; j < N; j++, k++)
            R[k] = A[i][j];
        }
    }

  return 0;
}

int
main ()
{
  int **A = NULL, *R = NULL;
  int M, N, i, j;

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

  /* ������ ������ ��� �������. */
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

  for (i = 0; i < M; i++)
    {
      A[i] = new int[N];

      if (A[i] == NULL)
        {
          free_matrix (A, i);

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

  cout << endl << "������� A: " << endl;

  randomize ();

  /* ���������� ������� ���������� �������. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
        {
          A[i][j] = random (21);
          cout << setw (3) << A[i][j];
        }

      cout << endl;
    }

  /* ������������ �� ���������. */
  switch (scan_cols (R, A, M, N))
    {
    case 0:
      cout << endl << "��������� ������������ ������� �� ���������:" << endl;

      for (i = 0; i < M * N; i++)
        cout << R[i] << " ";

      cout << endl;
      break;
    case 1:
    case 2:
      cout << endl << "������ ������� ������" << endl;
      break;
    case 3:
      cout << endl << "������� �����" << endl;
      break;
    }

  /* ���������� ������������. */
  switch (scan_rows (R, A, M, N))
    {
    case 0:
      cout << endl << "��������� ����������� ������������ �������:" << endl;

      for (i = 0; i < M * N; i++)
        cout << R[i] << " ";

      break;
    case 1:
    case 2:
      cout << endl << "������ ������� ������" << endl;
      break;
    case 3:
      cout << endl << "������� �����" << endl;
      break;
    }

  /* ������������ ����� ����������� ������. */

  free_matrix (A, M);

  if (R != NULL)
    {
      delete[] R;
      R = NULL;
    }

  getch ();
  return 0;
}
