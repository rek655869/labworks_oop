#include <iostream>
#include <cstddef>
using namespace std;
template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T());
    Array(const Array& other);
    ~Array();
    Array& operator=(Array other);
    void swap(Array& other);
    size_t size() const;
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;


private:
    size_t size_;
    T* data_;

};
class Class
{
public:
    Class(int) {}
};


template<typename T, typename Cmp>T minimum(Array<T> a, Cmp  less) {
    T min = a[0];
    size_t l = a.size();
    for (size_t i = 1; i < l; ++i)
        if (less(a[i], min))
            min = a[i];

    return min;
}



int main()
{

    Array<int> ints(3);
    Array<int> less(2);
    less[0] = 10;
    less[1] = 2;
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less);
}
