//1st approach is take 1st string and compare it with all of the other string if matches push\
 it into the ans and return TC is O[n*m]

//2nd approach is create a trie push all the elements and taverse until we are getting only 1child node\
and add the character into the ans TC is O[m*n] but SC is also O[m*n]
#include<bits/stdc++.h>
using namespace std;

class trieNode{
  public:
    char data;
    trieNode* children[26];
    int childcount;
    bool isTerminal;
    
    trieNode(char ch){
        data =  ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        childcount = 0;
        isTerminal = false;
    }
};

class Trie{
  public:
    trieNode* root;

    Trie(char ch){
        root = new trieNode(ch);
    }   

  private:
    void insertUTIL(trieNode* root, string word){
        ///base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        //assuming ulowercase word
        int index = word[0] - 'a';
        trieNode* child;

        ///present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new trieNode(word[0]);
            root->childcount++;
            root->children[index] = child;
        }
        //reccursion
        //moved the word by 
        insertUTIL(child, word.substr(1));
    }

  public:
    void insertWord(string word){
        insertUTIL(root, word);
    }
    void  lcp(string str, string &ans){

        for(int i = 0; i < str.length(); i++){
            char ch = str[i];

            if(root->childcount == 1){
                ans.push_back(ch);
                //move ahead
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }

        }

    }
};


string longestCommomPrefix(vector<string> arr, int n){
    Trie* t = new Trie('\0');

    for(int i = 0; i < n; i++){
        t->insertWord(arr[i]);
    }   
    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;
}

int main(){
    vector<string> input = {"coder", "coding", "codes", "code"};
    cout << "Longest common prefix is " << longestCommomPrefix(input, 4) << endl;
}
