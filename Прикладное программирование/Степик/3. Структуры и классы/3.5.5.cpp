/*
Закрепление материала.
Выполнил Бобнев Алексей
Ссылка: https://stepik.org/lesson/548/step/5?unit=871
19.05.2020
*/

# include <iostream>

using namespace std;

class IntArray
/*
Ключевое слово struct можно заменить на class, тогда поля
и методы по умолчанию будут private.
*/
{
    explicit IntArray(size_t size)
     : size_(size), data_(new int[size])
    {}
    ~IntArray() {delete [] data_;}
    int & get(size_t i) {return data_[i];}
    size_t size() {return size_;}

    void resize(size_t nsize)
    {
        int * ndata = new int[nsize];
        size_t n = nsize > size_ ? size_ : nsize;
        for (size_t i = 0; i != n; ++i)
            ndata[i] = data_[i];
        delete [] data_;
        data_ = ndata;
        size_ = nsize;
    }

    private:
        size_t size_;
        int * data_;

};

int main()
{
    return 0;
}
