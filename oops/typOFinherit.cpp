#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;

    public:
    void speak(){
        cout << "speaking" << endl;
    }
};

//single
class dog : public Animal{

};

// multi level
class labra: public dog{

};


int main(){
    dog d;
    d.speak();
    labra m;
    m.speak();
}