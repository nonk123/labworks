/*
 * �5. ������������ ���� ������.
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

int
main ()
{
  int **A = NULL, **B = NULL, **R = NULL, M, K, N, i, j, k;

  /* ���������� ����� ���������. */
  fix_locale();

  /* ���� �������� ������. */

  do
    {
      cout << "M = ";
      cin >> M;
    }
  while (M < 1 || M > 15);

  do
    {
      cout << "K = ";
      cin >> K;
    }
  while (K < 1 || K > 15);

  do
    {
      cout << "N = ";
      cin >> N;
    }
  while (N < 1 || N > 15);

  /* ������ ������ ��� ������� A. */
  A = new int*[M];

  if (A == NULL)
    {
      cout << "������ ������� ������" << endl;
      getch ();
      return 1;
    }

  for (i = 0; i < M; i++)
    {
      A[i] = new int[K];

      if (A[i] == NULL)
        {
          free_matrix (A, i);

          cout << "������ ������� ������" << endl;
          getch ();
          return 1;
        }
    }

  /* ������ ������ ��� ������� B. */
  B = new int*[K];

  if (B == NULL)
    {
      free_matrix (A, M);

      cout << "������ ������� ������" << endl;
      getch ();
      return 1;
    }

  for (i = 0; i < K; i++)
    {
      B[i] = new int[N];

      if (B[i] == NULL)
        {
          free_matrix (B, i);
          free_matrix (A, M);

          cout << "������ ������� ������" << endl;
          getch ();
          return 1;
        }
    }

  /* ������ ������ ��� ������� R. */
  R = new int*[M];

  if (R == NULL)
    {
      free_matrix (A, M);
      free_matrix (B, K);

      cout << "������ ������� ������" << endl;
      getch ();
      return 1;
    }

  for (i = 0; i < M; i++)
    {
      R[i] = new int[N];

      if (R[i] == NULL)
        {
          free_matrix (R, i);
          free_matrix (A, M);
          free_matrix (B, K);

          cout << "������ ������� ������" << endl;
          getch ();
          return 1;
        }
    }

  /* ���������� � ����� ������ A � B. */

  cout << endl << "������� A:" << endl;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < K; j++)
        {
          A[i][j] = random (21);
          cout << setw (3) << A[i][j];
        }

      cout << endl;
    }

  cout << endl << "������� B:" << endl;

  for (i = 0; i < K; i++)
    {
      for (j = 0; j < N; j++)
        {
          B[i][j] = random (21);
          cout << setw (3) << B[i][j];
        }

      cout << endl;
    }

  cout << endl << "������������ ���� ���� ������:" << endl;

  /* ���������� ������������ R ������ A � B. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
        {
          R[i][j] = 0;

          for (k = 0; k < K; k++)
            R[i][j] += A[i][k] * B[k][j];

          cout << setw (5) << R[i][j];
        }

      cout << endl;
    }

  /* ������������ ����� ����������� ������. */
  free_matrix (A, M);
  free_matrix (B, K);
  free_matrix (R, M);

  getch ();
  return 0;
}
