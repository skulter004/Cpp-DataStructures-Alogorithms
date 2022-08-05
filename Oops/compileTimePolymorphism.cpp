#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int b;
    void sayHello(){
        cout << "HELLO" << endl;
    }

    //funtion overloaded
    void sayHello(string name){
        cout << "HELLO " << name << endl;
    }

    //operator overload
    void operator+(A &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl;
    }

    void operator() (){
        cout << "hey bracket here " << this->a << endl;
    }
};

int main(){
    A obj1 , obj2;
    obj1.sayHello("shivam");
    
    obj1.a = 3;
    obj2.a = 7;

    obj1 + obj2 ;
    obj1();
}