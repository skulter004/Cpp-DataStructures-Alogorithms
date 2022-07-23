#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;
    
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node* buildTree(node* root){
    cout << "enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout << "enter data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

//for every node the left sub tree sum and the right subtree sum is equal to to root node \
then it is known as sum tree

pair<bool,int> isSumTreeFast(node* root){
    if(root == NULL){
        pair<bool,int> p  = make_pair(true,0);
        return p;
    }
    if(root -> left == NULL && root -> right == NULL){
        pair<bool,int> p  = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTreeFast(root -> left);
    pair<bool,int> rightAns = isSumTreeFast(root -> right);

    bool left = leftAns.first;
    bool righ = rightAns.first;

    bool condtn = root -> data == leftAns.second + rightAns.second;
    pair<bool,int> ans;
    if(left && right && condtn){
        ans.first = true;
        ans.second = 2 *root->data;
    }
    else{
        ans.first = false;
    }
    return ans ;
}

bool isSumTree(node* root){

    return isSumTreeFast(root).first;
}

int main(){
    node* root = NULL;
    root =  buildTree(root);

    if(isSumTree(root))
        cout << "tree is sum tree" << endl;
    else
        cout << "tree is not a sum tree " << endl;

    
}