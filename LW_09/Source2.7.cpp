#include <iostream>
using namespace std;

struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {

    ValueHolder(T value) : data_(value) {};

    ValueHolder* clone() const {
        return new ValueHolder(*this);
    }

    ~ValueHolder() {}

    T data_;
};
class Any
{
public:
    Any() : data_(0) {}

    template < class T >
    Any(T data) : data_(new ValueHolder<T>(data)) {}

    ~Any() {
        delete data_;
    }

    Any(Any const& obj) : data_(obj.data_->clone()) {}
    template <typename T>
    Any& operator=(const T& obj) {
        //        if (this != &obj) {
        delete data_;
        data_ = new ValueHolder<T>(obj);
        //        }
        return *this;
    }

    Any& operator=(const Any& obj) {
        if (this != &obj) {
            delete data_;
            data_ = obj.data_->clone();
        }
        return *this;
    }
    template <typename T>
    T* cast() {
        if (data_) {
            ValueHolder<T>* res = dynamic_cast<ValueHolder<T> *>(data_);
            if (res) {
                return &(res->data_);
            }
        }
        return 0;
    }

    ICloneable* data_;
};
int main()
{
    setlocale(LC_ALL, "RUS");

    Any empty;
    Any i(10);
    cout << "[1] i=" << i.cast<int>() << endl;
    Any copy(i);
    cout << "[2] copy=" << copy.cast<int>() << endl;
    empty = copy;
    cout << "[3] empty=" << empty.cast<int>() << endl;
    empty = 0;
    cout << "[4] empty=" << empty.cast<int>() << endl;
    int* iptr = i.cast<int>();
    cout << "[5] *iptr=" << iptr << endl;
    char* cptr = i.cast<char>();
    cout << "[6] *cptr=" << cptr << endl;
    Any empty2;
    int* p = empty2.cast<int>();
    cout << "[7] *p=" << p << endl;
    Any a = 20;
    cout << "[8] a=" << a.cast<int>() << endl;
    a = 0;
    cout << "[9] a=" << a.cast<int>() << endl;
    a = 'w';
    cout << "[10] a=" << a.cast<char>() << endl;
    return 0;

}
