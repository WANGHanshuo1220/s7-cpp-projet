#include <iostream>

using namespace std;

class  my_class
{
    public:
    my_class(int _a) {a = _a;}
    my_class(my_class &t) {a = t.a;}

    int a;
};

int main()
{
    my_class a1(3);
    cout << a1.a << endl;

    my_class* pa;
    pa = new my_class(1);
    cout << pa->a << endl;

    return 0;
}