#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    // seperator
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // previos level traversed
            cout << endl;
            // still elements in the tree
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node* buildTree(Node* root){
    cout << "enter the data " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    cout << "enter data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

//return the size of the largest bst in binary tree size means no of nodes in the tree
//1st approach go to every node and call the valid bst function but for this solution tc is O[n^2]

//optimised approach is we should check for four things max, min, is bst, size
//first we will create a class for all the four data
class info{
    public:
        int max;
        int min;
        bool isBST;
        int size;    
};

info solve(Node* root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.max =  max(root->data, right.max);
    currNode.min = min(root->data, left.min);

    if(left.isBST && right.isBST && (root->data > left.max && root->data < right.min)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;


}

int largestBST(Node* root){
    int maxSize = 0;;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main(){
    Node* root =NULL;
    root = buildTree(root);
    cout << "Size of largest BST in the tree is " << largestBST(root) << endl;
}