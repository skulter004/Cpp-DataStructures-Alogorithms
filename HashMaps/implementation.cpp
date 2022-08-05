#include<bits/stdc++.h>
using namespace std;



int main(){
    
    //unordered map
    //creating map
    unordered_map<string, int> m;
    //insertion
    //1st method
    pair<string,int> p = make_pair("shivam", 3);
    m.insert(p);
    //2nd method
    pair<string,int> p2("shivam",3);
    m.insert(p2);
    //3rd way
    m["singh"] = 2;
    m["shivam"] = 3;

    //searching
    cout << m["shivam"] << endl;
    cout << m.at("shivam") << endl;

    //important
    //cout << m.at("unknownkey") << endl; //gives error is the key is not created
    cout << m["unknownkey"] << endl; //gives zero if the key is not created as it creates a\
     key by itself if it is not already present int map and maps it with "0"

    // size
    cout << m.size() << endl;

    //check presence
    cout << m.count("shivam") << endl;

    //erase
    m.erase("love");

    //printing full map
    //for each loop
    for(auto i:m){
        cout << i.first << endl;
    }

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();//from where to start
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
    //ordered map preservs the sequnce of the valus entered 
    return 0;
}