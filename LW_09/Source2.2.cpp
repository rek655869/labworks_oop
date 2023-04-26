#include <iostream>
#include <cstddef>

using namespace std;
template <typename T>

class Array
{
public:
    Array(size_t size, const T& value = T())
    {
        size_ = size;
        for (size_t i = 0; i != size_; ++i)
            new (data_ + i) T(value);
        for (size_t i = 0; i != size_; ++i)
        {
            cout << i << endl;
        }
    }
    Array()
    {
        size_ = 0;
        data_ = 0;
    }
    Array(const Array& obj)
    {
        size_ = obj.size();
        data_ = (T*) new char[size_ * sizeof(T)];
        for (size_t i = 0; i != size_; ++i)
            new (data_ + i) T(obj[i]);
        for (size_t i = 0; i != size_; ++i)
        {
            cout << i << endl;
        }

    }



    Array& operator=(const Array& obj)
    {
        if (this != &obj)
        {
            mem_free();
            size_ = obj.size();
            data_ = (T*) new char[size_ * sizeof(T)];
            for (size_t i = 0; i != size_; ++i)
                new (data_ + i) T(obj[i]);
        }
        return *this;
    }

    size_t size() const
    {
        return size_;
    }
    T& operator[](size_t i)
    {
        return *(data_ + i);
    }
    const T& operator[](size_t i) const
    {
        return *(data_ + i);
    }
    ~Array()
    {
        mem_free();
    }

    void mem_free()
    {
        for (size_t i = 0; i != size_; ++i)
            data_[i].~T();
        delete[](char*) data_;
    }

private:
    size_t size_;
    T* data_;
};
class Class
{
public:
    Class(int) {}
};

int main()
{
    Array<Class> a(5, 10);
    setlocale(LC_ALL, "RUS");
}
