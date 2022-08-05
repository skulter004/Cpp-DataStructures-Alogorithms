#include<iostream>
using namespace std;
class A{
    public:
    void check(){
        cout << "everything is fine" << endl;
    }
};

class D {
    public:
    void check(){
        cout << "still working fine" << endl;
    }
};
class C: public A{

};
class B : public A , public D{

};
int main(){
    B obj;
    //resolving ambiguity
    obj.A::check();
    obj.D::check();
}