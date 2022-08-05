#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> reverse (vector<int> v){
    int sp=0;
    int ep=v.size()-1;
    while(sp<=ep){
        
        swap(v[sp],v[ep]);
        sp++;
        ep--;

    }
    return v;
}

int main () {
   
    vector<int>v;
    
       v.push_back(11);
       v.push_back(5);
       v.push_back(7);
       v.push_back(3);
       v.push_back(4);
    
      
       vector<int>ans= reverse(v);
        for(int i=0; i<ans.size();i++ ){
            cout<<ans[i]<<endl;;
        }
    

return 0;
}
