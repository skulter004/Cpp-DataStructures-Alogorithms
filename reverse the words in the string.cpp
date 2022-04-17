#include<iostream>
#include<vector>

using namespace std;
void revstr( string str){
    int s=0;
    int e=str.length()-1;
    while(s<=e){
        swap(str[s],str[e]);
        s++;
        e--;
    }
    cout<<str<<" ";
    return ;
}
void removespaces(string str){
    string str1;
      for(int i=0;i<=str.length();i++){
          if(str[i]==' '||str[i]=='\0'){
              revstr(str1);
              str1="";
          }
          else{
              str1.push_back(str[i]);
          }

       }
        
      return;
}

int main(){
     string str;
     getline(cin,str);
         

    
    removespaces(str);
   
    return 0;
} 
