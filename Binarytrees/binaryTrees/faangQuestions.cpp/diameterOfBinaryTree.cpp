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

// //longest path bewtween two end nodes of tree is called its diameter
// int diameter(node* root){

//     if(root == NULL){
//         return 0;
//     }
//     int op1 = diameter(root -> left) ;
//     int op2 = diameter(root -> right) ;
//     //need to remove the height function call as it is increasing complexity to n^2
//     int op3 = height(root -> left) + height(root -> right) + 1;
//     int ans = max(op1, max(op2, op3)) ;
//     return ans;
// }

pair<int,int> diameterFast(node* root){
    //here we are using first part as diameter and second aprt as the height
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root -> left);
    pair<int,int> right = diameterFast(root -> right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second +1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3)) ;
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

//longest path bewtween two end nodes of tree is called its diameter
int diameter(node* root){

    return diameterFast(root).first;
}


int main(){
    node* root = NULL;
    root =  buildTree(root);

    cout << diameter(root);
}