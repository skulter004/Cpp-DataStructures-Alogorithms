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

Node *insertIntoBST(Node* root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

//predecessor or sucessor means the just smallest or largest elment from the given element \
this can also be solved from the approach of in onorder

//another approach can be first we should find the given node \
ans then apply the approach for min and max vlaue for the left and the right subtree
///tc is O{n} ans sc is O{1}for this one;
pair<int, int> predecessorSucessor(Node* root, int key){
    //find key
    Node* temp = root;
    int pre = -1;
    int suc = -1;

    while(temp->data != key){
        if(temp->data > key){
            //the data can be possible sucessor
            suc = temp->data;
            temp = temp->left;
        }
        else{
            ///this can be a possibl predecessor
            pre = temp->data;
            temp = temp->right;
        }

    }
    //predecessor
    Node* leftTree = temp->left;
    while(leftTree){
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    //sucessor
    Node* rightTree = temp->right;
    while(rightTree){
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int,int> ans = make_pair(pre, suc);
    return ans;
}

int main(){ 
    Node* root = NULL;
    cout <<"Enter data to create BST" << endl;
    takeInput(root);
    int k; cout << "Enter the value for which you want to check " << endl;
    cin >> k;
    pair<int,int> ans =  predecessorSucessor(root, k);
    cout << " predecessor = " << ans.first 
    << " " << "sucessor = " << ans.second << endl;
}