#include <iostream>
using namespace std;

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
    T data_;

    ValueHolder(T value) : data_(value) {};
    ValueHolder* clone() const 
    {
        return new ValueHolder(*this);
    }
    ~ValueHolder() {}
};

int main23() {
    ValueHolder<int>* a = new ValueHolder<int>(651);
    ValueHolder<int>* b = a->clone();
    cout << a->data_ << " " << b->data_ << " " << endl;
    return 0;
}