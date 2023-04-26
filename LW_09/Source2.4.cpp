#include <cstddef>

template <typename T, typename U>
void copy_n(T* array, U* s_array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = (T)s_array[i];
    }
}

int main24() {

    int a[] = { 0, 4, 9, 4, 6 };
    double b[5] = {};
    copy_n(a, b, 5);
    return 0;
}