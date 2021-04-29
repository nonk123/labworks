/*
 * №1. Построчное сканирование матрицы.
 *
 * Дана матрица размером MxN. Необходимо сформировать одномерный массив как
 * результат построчного сканирования элементов этой матрицы.
 */

#include "common.hpp"

int
main ()
{
  int **A = NULL, *R = NULL;
  int M, N, i, j, k = 0;

  /* Правильный вывод кириллицы. */
  fix_locale ();

  /* Ввод размера матрицы. */

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

  /* Захват памяти под результирующий массив. */
  R = new int[M * N];

  if (R == NULL)
    {
      cout << "Ошибка захвата памяти" << endl;
      getch ();
      return 1;
    }

  /* Захват памяти под массив строк матрицы. */
  A = new int*[M];

  if (A == NULL)
    {
      if (R != NULL)
        {
          delete[] R;
          R = NULL;
        }

      cout << "Ошибка захвата памяти" << endl;
      getch ();
      return 1;
    }

  /* Захват памяти под сами строки матрицы. */
  for (i = 0; i < M; i++)
    {
      A[i] = new int[N];

      if (A[i] == NULL)
        {
          /* Освобождение ранее захваченной памяти. */
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

          cout << "Ошибка захвата памяти" << endl;
          getch ();
          return 1;
        }
    }

  randomize ();

  cout << endl << "Матрица A:" << endl;

  /* Заполнение матрицы случайными числами и вывод её элементов. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
        {
          A[i][j] = random (21);
          cout << setw (3) << A[i][j];
        }

      cout << endl;
    }

  cout << endl << "Массив R, полученный построчным её сканированием:" << endl;

  /* Построчное сканирование элементов матрицы. */
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++, k++)
      {
        R[k] = A[i][j];
        cout << R[k] << " ";
      }

  cout << endl;

  /* Освобождение ранее захваченной памяти. */
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
