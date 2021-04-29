/*
 * №5. Произведение двух матриц.
 */

#include "common.hpp"

/*
 * Функция освобождения двумерного динамического массива (матрицы).
 *
 * Входные параметры:
 *   A - массив строк некоторой матрицы;
 *   M - число строк в ней.
 *
 * Возвращаемое значение - код завершения:
 *   0 - успешное выполнение функции;
 *   1 - передан параметр M меньше нуля.
 *
 * Разработчик: Судаков С.А.
 * Версия: 1.0
 * Дата: 13.04.21
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

  /* Правильный вывод кириллицы. */
  fix_locale();

  /* Ввод размеров матриц. */

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

  /* Захват памяти под матрицу A. */
  A = new int*[M];

  if (A == NULL)
    {
      cout << "Ошибка захвата памяти" << endl;
      getch ();
      return 1;
    }

  for (i = 0; i < M; i++)
    {
      A[i] = new int[K];

      if (A[i] == NULL)
        {
          free_matrix (A, i);

          cout << "Ошибка захвата памяти" << endl;
          getch ();
          return 1;
        }
    }

  /* Захват памяти под матрицу B. */
  B = new int*[K];

  if (B == NULL)
    {
      free_matrix (A, M);

      cout << "Ошибка захвата памяти" << endl;
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

          cout << "Ошибка захвата памяти" << endl;
          getch ();
          return 1;
        }
    }

  /* Захват памяти под матрицу R. */
  R = new int*[M];

  if (R == NULL)
    {
      free_matrix (A, M);
      free_matrix (B, K);

      cout << "Ошибка захвата памяти" << endl;
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

          cout << "Ошибка захвата памяти" << endl;
          getch ();
          return 1;
        }
    }

  /* Заполнение и вывод матриц A и B. */

  cout << endl << "Матрица A:" << endl;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < K; j++)
        {
          A[i][j] = random (21);
          cout << setw (3) << A[i][j];
        }

      cout << endl;
    }

  cout << endl << "Матрица B:" << endl;

  for (i = 0; i < K; i++)
    {
      for (j = 0; j < N; j++)
        {
          B[i][j] = random (21);
          cout << setw (3) << B[i][j];
        }

      cout << endl;
    }

  cout << endl << "Произведение этих двух матриц:" << endl;

  /* Нахождение произведения R матриц A и B. */
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

  /* Освобождение ранее захваченной памяти. */
  free_matrix (A, M);
  free_matrix (B, K);
  free_matrix (R, M);

  getch ();
  return 0;
}
