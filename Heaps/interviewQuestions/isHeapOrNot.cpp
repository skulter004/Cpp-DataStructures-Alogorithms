#include<bits/stdc++.h>
using namespace std;
//tree node implementattion
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
//actal code starts from here

//checking for max heap
//we need to check two things complete binary tree and is maxheap
//tc O[n]
int countNodes(node* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1+ countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(node* root, int index, int count){
    if(root == NULL) return true;
    

    if(index >= count) return false;

    else{
        bool left = isCBT(root->left, index*2+1, count);
        bool right = isCBT(root->right, index*2+2, count);
        return(left && right);
    }
} 

bool isMaxOrder(node* root){
    if(root->left == NULL && root->right == NULL) return true;

    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        if(left && right && (root->data > root->left->data) && root->data > root->right->data){
            return true;
        }
        else{
            return false;
        }
    }
}

bool isHeap(node* root){
    int index = 0;
    int totalCount = countNodes(root);
    if(isCBT(root, index, totalCount) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    if(isHeap(root)) cout << "Tree is a max heap" << endl;
    else cout << "Tree is not a heap" << endl;
}