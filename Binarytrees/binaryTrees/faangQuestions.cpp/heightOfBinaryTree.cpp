#include<iostream>
#include<queue>
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

int height(node* root){
    //base case
    if(root == NULL){
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right) +1;
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout << height(root) << endl;
}