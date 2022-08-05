#include<iostream>
#include<bits/stdc++.h>
/* #include "Hero.cpp" we can use this to include the class created in a new file */
using namespace std;

//creating class
class Hero{    

    //properties
    private: // below entities will become private
    int health;

    
     
    //getter
    public: //now all the entities written below it will become public
    char *name;
    char level;
    //static keyword
    static int time;

    int gethealth(){
        return health;
    }
    int getlevel(){
        return level;
    }

    //setter
    void sethealth(int h){
        health = h;
    }
    void setlevel(char ch){
        level = ch;
    }
    //constructor
     Hero(){
        cout << "constructor called" << endl;
        name =  new char[100];
    } 
    
    //parameterised constructor
    Hero(int health , char level){
        cout << "this -> " << this << endl;
        this ->health = health;
        this -> level = level;
    }
    //copy constructor // deep copy 
    Hero(Hero& temp){
        cout << "copy constructor called" << endl;
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name =ch;
        this->health = temp.health;
        this-> level = temp.level;
    }
    //printting
    void print(){
        cout << "health is " << health << endl;
        cout << "level is " << level << endl;
        cout << "name is " << name << endl;
    }
    //setter
    void setName(char name[]){
        strcpy(this->name, name);
    }
    
    //destructor
    ~Hero(){
        cout << "destructor bhai called" << endl;
    }

    //static function 
    static int random(){
        return time ;
    }
    
};

int Hero :: time = 10;

int main(){
    Hero h1;
    h1.sethealth(9);
    h1.setlevel('D');
    char name[7] = "shivam";
    h1.setName(name);
    h1.print();
    cout << endl;

    //default copy constructor
    Hero h2 (h1); // hero h2 = h1;
    h2.print();

    h1.name[0] = 'G';
    cout << endl;
    h2.print();
    
    cout << endl;

    h2 = h1 ;
    h2.print();
    
    cout << Hero::time << endl;
    
    cout << Hero::random() << endl;
    
    
    
    
    /*
    //static allocation health
    Hero shivam(7 , 'B');
    //dynamic 
    Hero *new1 = new Hero(9 ,'C'); // Hero *new1 = new Hero();
    shivam.level = 'A';
    cout << shivam.getlevel() << endl;
    cout << new1->level << endl;
    new1->setlevel('A'); // (*new1).level  = 'a';
    cout << "level of new1" << (*new1).level <<endl;
    cout << "address of shivam " << &shivam << endl;
    shivam.print();
    Hero mehul(shivam);
    mehul.print();
    */
    return 0;
}