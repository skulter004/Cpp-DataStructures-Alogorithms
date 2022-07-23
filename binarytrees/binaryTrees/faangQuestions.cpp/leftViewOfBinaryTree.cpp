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
void solve (node* root, vector<int> &ans, int lvl){
    //base case
    if(root == NULL){
        return;
    }
    // entered in new level
    if(lvl == ans.size()){
        ans.push_back(root -> data);
    }
    solve(root -> left, ans, lvl+1);
    solve(root -> right, ans, lvl+1);

}
vector<int> leftView(node* root){
    vector<int> ans;
    ans.push_back(root -> data);
    //recussive call
    solve(root, ans, 0);
    return ans;
}

int main(){
    node* root = NULL;
    root =  buildTree(root);

    vector<int> ans = leftView(root);

    for(int  i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }   
}

int main(){
    node* root = NULL;
    root =  buildTree(root);

    vector<int> ans = leftView(root);

    for(int  i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}