#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;

    public:
    void bark(){
        cout << "barking" << endl;
    }
};

class human {
    public:
    string color;

    public:
    void speak(){
        cout << "speaking" << endl;
    }

};

class hybrid: public Animal , public human{

};

int main(){
    hybrid obj;
    obj.speak();
    obj.bark();
}