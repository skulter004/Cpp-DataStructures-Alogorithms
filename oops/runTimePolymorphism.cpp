#include<iostream>
using namespace std;
class Animal{
    public:
    void speak(){
        cout << "speaking" << endl;
    }
};

class dog: public Animal{
    public:
    //we modifird the implementation of speak here   
    void speak(){
        cout << "barking" << endl;
    }
};

int main(){

    dog d;
    d.speak();

}