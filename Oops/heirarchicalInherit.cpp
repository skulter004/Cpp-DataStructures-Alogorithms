#include<iostream>
using namespace std;

class A {
    public:
    void func1(){
        cout << "function 1 called" << endl;
    }
};

class B : public A{
    public:
    void func2(){
        cout << " function 2 called" << endl;
    }

};

class C: public A{
    public:
    void func3(){
        cout << " function 3 called" << endl;
    }
};

int main(){
    A obj1;
    obj1.func1();

    B obj2;
    obj2.func1();

    C obj3;
    obj3.func1();


}