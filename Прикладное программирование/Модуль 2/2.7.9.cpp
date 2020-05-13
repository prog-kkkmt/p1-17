/*�������� �������, ������� ��������� �� ���� ������������� ������� MM (������� �������, ������
��������� ������������� ������) ������� rows*cols, � ���������� ����������������� ������� M^T
(���� ��������� ������������� ������) ������� cols*rows. ���� � M �� ����������� i-�� ������
� j-��� ������� ������ ����� x, �� �� �����������  j-�� ������ � i-��� ������� � ������� M^T
���� ����� ������ ����� x, ��� ������� ������� M^T[j][i] = M[i][j]
��������: ���������� ���������
��������: Stepik Computer Science Center (CS �����)
���������������� �� ����� C++
2.7.9 https://stepik.org/lesson/543/step/9
13.05.2020
*/
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    unsigned a = cols, b = rows;
    int ** m_New = new int *[a];
    m_New[0] = new int [a * b];
    for(unsigned i = 1; i != a; ++i)
        m_New[i] = m_New[i - 1] + b;

    for(unsigned i = 0; i < a; i++)
        for(unsigned j = 0; j < b; j++)
            m_New[i][j] = m[j][i];
    return m_New;
}
