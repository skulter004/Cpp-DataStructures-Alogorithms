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

//traversing left rtee at first
void traverseLeft(node* root, vector<int> &ans){
    if(root == NULL || root -> left == NULL && root -> right == NULL){
        return;
    }

    ans.push_back(root -> data);
    if(root -> left){
        traverseLeft(root -> left, ans);
    }
    else{
        traverseLeft(root -> right, ans);
    }
}

void traverseLeaf(node* root, vector<int> &ans){
    if(root == NULL){
        return ;
    }
    if(root ->left == NULL && root -> right == NULL){
        //storing the leaf node
        ans.push_back(root -> data);
    }

    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}

void traverseRight(node* root, vector<int> &ans ){
    if(root == NULL || root -> left == NULL && root ->right == NULL){
        return ;
    }

    if(root -> right){
        traverseRight(root -> right, ans);
    }
    else{
        traverseRight(root -> left, ans);
    }
    //store answer
    ans.push_back(root -> data);
}

vector<int> boundry(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root -> data);

    traverseLeft(root -> left, ans);

    //trAVERSE LEAF NODES
    //left subtree
    traverseLeaf(root -> left, ans);
    //right subtree
    traverseLeaf(root -> right, ans);

    //traverse right part
    traverseRight(root -> right, ans);

    return ans;
}

int main(){
    node* root = NULL;
    root =  buildTree(root);

    vector<int> ans = boundry(root);

    for(int  i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}