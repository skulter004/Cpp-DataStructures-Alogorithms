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
    if(root == NULL || root -> left == NULL){
    ans.push_back(root -> data);
        return;
    }

    
    if(root -> left){
        traverseLeft(root -> left, ans);
    }

    ans.push_back(root -> data);
}

void traverseRight(node* root, vector<int> &ans ){
    if(root == NULL ){
        return ;
    }
    if(root -> right == NULL){
        ans.push_back(root -> data);
    }

    if(root -> right){
    //store answer
        ans.push_back(root -> data);
        traverseRight(root -> right, ans);
    }
    
}

vector<int> topView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    int rootdata = root -> data;

    traverseLeft(root -> left, ans);

    ans.push_back(rootdata);

    //traverse right part
    traverseRight(root -> right, ans);

    return ans;
}

int main(){
    node* root = NULL;
    root =  buildTree(root);

    vector<int> ans = topView(root);

    for(int  i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
}
