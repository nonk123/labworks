/*
 * �3. ��������� ������������ ���� N-������ ��������.
 *
 * ���������� �������� �������, ������� ������� ��������� ������������ ����
 * N-������ ��������.
 */

#include "common.hpp"

/*
 * ������� ���������� ���������� ������������ ���� ��������.
 *
 * ������� ���������:
 *   A - ��������� �� ������� ������, � ������� ����������� �������� �������
 *       �������.
 *   B - ��������� �� ������� ������, � ������� ����������� �������� �������
 *       �������.
 *   N - ����������� ���� ��������.
 *
 * �������� ���������:
 *   err - ��� ������:
 *     0 - �������� ���������� �������;
 *     1 - �� ��������� A �� ��������� ������;
 *     2 - �� ��������� B �� ��������� ������;
 *     3 - ������� �� �������� ���������.
 *
 * ������������ ��������:
 *   ������� ��������� ������������.
 *
 * ��������:
 *   ������������ �������������� ����������� ���������� ������������ N-������
 *   ��������: ��� ����� ������������ ��������������� ��������� ��������.
 *
 * �����������: ������� �.�.
 * ������: 1.0
 * ����: 25.03.21
 */
int
dot_product (int* A, int* B, int N, int* err)
{
  int i, dot = 0;

  if (A == NULL)
    {
      *err = 1;
      return dot;
    }

  if (B == NULL)
    {
      *err = 2;
      return dot;
    }

  if (N <= 0)
    {
      *err = 3;
      return dot;
    }

  for (i = 0; i < N; i++)
    dot += A[i] * B[i];

  *err = 0;
  return dot;
}

int
main ()
{
  int *A = NULL, *B = NULL, N, i, dot, err;

  /* ���������� ����� ���������. */
  fix_locale ();

  do
    {
      cout << "����������� �������� (�� ����� 20): "; cin >> N;
    }
  while (N <= 0 || N > 20);

  A = new int[N];

  if (A == NULL)
    {
      cout << "������ ������� ������ ��� ������ A" << endl;
      getch ();
      return 1;
    }

  B = new int[N];

  if (B == NULL)
    {
      /* ������������ ��� ����������� ������. */
      if (A != NULL)
        {
          delete[] A;
          A = NULL;
        }

      cout << "������ ������� ������ ��� ������ B" << endl;
      getch ();
      return 1;
    }

  /* ������������� ���������� ��������� �����. */
  randomize ();

  cout << endl << "  A       B  " << endl;

  /* ���������� � "��������" ����� �������� �� �����. */
  for (i = 0; i < N; i++)
    {
      /* ��������� ��������� ����� � ��������� [-10; 10]. */
      A[i] = random (21) - 10;
      B[i] = random (21) - 10;

      cout << "|" << setw (3) << A[i] << "|   |" << setw(3) << B[i] << "|" << endl;
    }

  /* ���������� ���������� ������������. */
  dot = dot_product (A, B, N, &err);

  /* ����� ��������� �� ������. */
  switch (err)
    {
    case 0:
      cout << endl << "A . B = " << dot << endl;
      break;
    case 1:
      cout << endl << "������ ������� ������ ��� ������ A" << endl;
      break;
    case 2:
      cout << endl << "������ ������� ������ ��� ������ B" << endl;
      break;
    case 3:
      cout << endl << "������� �� �������� ���������" << endl;
      break;
    }

  /* ������������ ����� ����������� ������. */

  if (A != NULL)
    {
      delete[] A;
      A = NULL;
    }

  if (B != NULL)
    {
      delete[] B;
      B = NULL;
    }

  getch ();
  return err;
}
