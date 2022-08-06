#include<bits/stdc++.h>
using namespace std;


//SC O[m*n]  TC O[m*n]

class trieNode{
  public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class trie{
  public:
    trieNode* root;

    trie(){
        root = new trieNode('\0');
    }
  private:
    void insertUTIL(trieNode* root, string word){
        ///base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        //assuming uppercase word
        int index = word[0] - 'a';
        trieNode* child;

        ///present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new trieNode(word[0]);
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

    void printSuggestions(trieNode* curr, vector<string> &temp, string prefix){
        
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            trieNode* next = curr->children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str){

        trieNode* prev = root;
        vector<vector<string> > output;
        string prefix  = "";

        for(int i = 0; i < str.length(); i++){
            char  lastCh = str[i];

            prefix.push_back(lastCh);

            //check for last char
            trieNode* curr = prev->children[lastCh - 'a'];

            //if not found
            if(curr == NULL){
                break;
            }

            //if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;

        }
        return output;
    }

};


//question is you will be given a prefix and you have to return all the \
words matching to that prefix
//approach make a trie for all the given string  


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
        trie *t = new trie();

    for(int i = 0; i < contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }    


    return t->getSuggestions(queryStr);
    
}


int main(){
    vector<string> contactList = {"cod", "coding", "codding", "code", "coly"};
    string querry = "coding";
    vector<vector<string>> Suggestions = phoneDirectory(contactList, querry);
    

    for(int  i = 0; i < Suggestions.size(); i++){
        vector<string> temp = Suggestions[i];
        for(int  j = 0; j < temp.size(); j++){
            cout << temp[j] << " ";
        }cout << endl;
    }


}
