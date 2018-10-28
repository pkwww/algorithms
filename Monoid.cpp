#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
class Monoid
{
public:
    Monoid (function<T(T, T)> op, T id) :_op(op), _id(id){};
    virtual ~Monoid () = default;
    T operator() (T a, T b) { return _op(a, b); };
    function<T(T, T)> _op;
    const T _id;
};

template <typename T, typename... Args>
T map(Monoid<T> monoid, T first, Args... args)
{
    return monoid(first, map(monoid, args...));
}

template <typename T>
T map(Monoid<T> monoid, T v)
{
    return monoid(v, monoid._id);
}


int int_add(int a, int b)
{
    return a + b;
}

int main(void)
{
    Monoid<int> monoid{int_add, 0};
    cout << map(monoid, 1, 2, 3, 4, 5, 6, 7) << endl;
    return 0;
}
