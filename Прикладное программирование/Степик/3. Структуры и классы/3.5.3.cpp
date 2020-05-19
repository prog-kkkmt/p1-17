/*
����������� ���������.
�������� ������ �������
������: https://stepik.org/lesson/548/step/3?unit=871
19.05.2020
*/

# include <iostream>

using namespace std;

class IntArray
/*
�������� ����� struct ����� �������� �� class, ����� ����
� ������ �� ��������� ����� private.
*/
{
    explicit IntArray(size_t size)
     : size_(size), data_(new int[size])
    {}
    ~IntArray() {delete [] data_;}
    int & get(size_t i) {return data_[i];}
    size_t size() {return size_;}

    private:
        size_t size_;
        int * data_;

};

int main()
{
    return 0;
}
