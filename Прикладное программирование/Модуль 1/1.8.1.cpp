/*���������: ����������� �.�, ������ �1-17, 23.04.2020
������: �������� ������� power, ����������� ���������� ������ ����� � ��������������� ����� �������. ������� power ������ ��������� �� ���� ��� ����� ����� � ���������� ����� ����� (�������� ������ ����). ��� ���������� ������� ������, ��� ������� ����������� ������ ���������� power, ������� ������ �� ������ ������ �� ����� ��� ��������.
���������� � ����������: � ���� ������� ��� ����� ����������� ������ ������� power. �� ������ ���������� ��������������� �������, ���� ��� ��� �����. ������������� ������� main �� �����.
�����������: ���������� cmath (� math.h) ������������ ���������.
��������: ��������� �����, ������ �������
���������������� �� ����� C++
https://stepik.org/course/7*/


// ���������� ������ ������� power, ���
//    x - �����, ������� ����� �������� � �������
//    p - �������, � ������� ����� �������� x
//

int power(int x, unsigned p) {
    int answer = 1;
    for (int i = 0; i < p; i++)
        answer *= x;
    return answer;
}
