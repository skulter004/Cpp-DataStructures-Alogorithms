#include<bits/stdc++.h>
using namespace std;

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
        int index = word[0] - 'A';
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

  private:
    //searching
    bool searchUTIL(trieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'A';

        trieNode* child;
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }
        return searchUTIL(child, word.substr(1));
    }

    //deletion
    void deleteUTIL(trieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return ;
        }
        int index = word[0] - 'A';

        trieNode* child;
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            cout << "Word not already present" << endl;
        }
        deleteUTIL(child, word.substr(1));
    }

  public:
    //searching
    bool searchWord(string word){
        return searchUTIL(root, word);
    }
    //deletion
    void Delete(string word){
        deleteUTIL(root, word);
    }
};

int main(){
    trie* t = new trie();
    t ->insertWord("ABCD");
    t ->insertWord("TIME");

    cout << "present or not " << t->searchWord("TIME") << endl;
    t ->Delete("TIME");
    
    cout << "present or not " << t->searchWord("TIME") << endl;
}