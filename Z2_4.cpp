/*
 * №4. Транспонирование заданной квадратной матрицы.
 */

#include "common.hpp"

int
main ()
{
  int **A, M, i, j;

  /* Правильный вывод кириллицы. */
  fix_locale ();

  /* Ввод размера матрицы. */
  do
    {
      cout << "M = ";
      cin >> M;
    }
  while (M < 2 || M > 15);

  /* Захват памяти под матрицу. */
  A = new int*[M];

  if (A == NULL)
    {
      cout << "Ошибка захвата памяти" << endl;
      getch ();
      return 1;
    }

  for (i = 0; i < M; i++)
    {
      A[i] = new int[M];

      if (A[i] == NULL)
        {
          /* Освобождение ранее захваченной памяти. */
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

          cout << "Ошибка захвата памяти" << endl;
          getch ();
          return 1;
        }
    }

  cout << endl << "Матрица A:" << endl;

  /* Заполнение и вывод матрицы. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < M; j++)
        {
          A[i][j] = random (21);
          cout << setw (3) << A[i][j];
        }

      cout << endl;
    }

  /* Транспонирование матрицы. */
  for (i = 0; i < M; i++)
    for (j = i; j < M; j++)
      {
        int tmp = A[i][j];
        A[i][j] = A[j][i];
        A[j][i] = tmp;
      }

  cout << endl << "Транспонированная матрица A:" << endl;

  /* Вывод транспонированной матрицы. */
  for (i = 0; i < M; i++)
    {
      for (j = 0; j < M; j++)
        cout << setw (3) << A[i][j];

      cout << endl;
    }

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

      delete[] A[i];
      A[i] = NULL;
    }

  getch ();
  return 0;
}
