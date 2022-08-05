#include<iostream>
using namespace std;

class human{
    public:
    int height;
    int weight;
    int age;

    public:
        int getage(){
            return this-> weight;
        }
        void setweight(int w){
            this->weight = w;
        }

};

//public mode
class male: public human{
    public:
        string color;
    void sleep(){
        cout << "man sleeping" << endl;
    }
};

class female: private human{
    public:
        string color;
    void sleep(){
        cout << "woman sleeping" << endl;
    }  
    
    void setweight(int w){
            this->weight = w;
        }
    int getweight(){
            return this->weight;
        }
};

int main(){

    male male1;
    cout << male1.age << endl;
    cout << male1.weight << endl;
    cout << male1.height << endl;
    cout << male1.color << endl;
    male1.sleep();
    male1.setweight(84);
    cout << male1.weight << endl;

    female f;
    f.sleep();
    f.setweight(99);
    cout << f.getweight() << endl;

    


}
