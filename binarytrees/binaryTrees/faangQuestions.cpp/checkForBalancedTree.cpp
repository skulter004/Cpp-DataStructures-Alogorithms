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

// bool isBalanced(node* root){
//     if(root == NULL){
//         return true;
//     }

//     bool left = isBalanced(root -> left);
//     bool right = isBalanced(root -> right);
//     //again O[n^2] due to height call
//     bool diff = abs(height(root -> left) - height(root -> right)) <= 1;
//     if(left && right &&  diff){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

pair<bool,int> isBalancedFast(node* root){
    //first for boolean second for height
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalancedFast(root -> left);
    pair<bool,int> right = isBalancedFast(root -> right);
    
    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second, right.second) +1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
         ans.first = false;
    }
    return ans;
}

bool isBalanced(node* root){

    return isBalancedFast(root).first;
}


int main(){
    node* root = NULL;
    root =  buildTree(root);

    if(isBalanced(root))
        cout << "tree is balanced" << endl;
    else
        cout << "tree is not balanced " << endl;
}