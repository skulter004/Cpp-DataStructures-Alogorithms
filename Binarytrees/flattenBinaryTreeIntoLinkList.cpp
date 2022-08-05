//tc  O[n] sc O[1]
//we will use morris trsversal to achieve these constraints
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

void flatten(node* root){
    node* curr =root;
    while(curr != NULL){

        if(curr -> left){
            //predecessor
            node* pred = curr -> left;
            while (pred -> right)
                pred = pred -> right;

                pred -> right = curr;
                curr -> right = curr -> left;
                //aternate of the below code
                curr -> left = NULL;
        }
        curr = curr -> right;
    }
    //make the left of tree nodes null;
    // curr = root;
    // while(curr != NULL){
    //     curr -> left = NULL;
    //     curr = curr -> right;
    // }
}
