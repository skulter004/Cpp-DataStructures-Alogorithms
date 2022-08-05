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

//a target value is givenn we have to find if there exists\
any pair in the tree for which the value equal to the target
// we can use inorder approach as it is sorted for evert tree


void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }
    inorder(root -> left, in);
    in.push_back(root->data);
    inorder(root -> right, in);
}

bool twoSumInBST(Node* root, int target){
    vector<int> inOrderVal;
    //store inordder value
    inorder(root, inOrderVal);
    //use two pointer approach to check if pair exists
    int i = 0, j = inOrderVal.size()-1;

    while(i < j){
        int sum = inOrderVal[i] + inOrderVal[j];
        if(sum == target){
            cout << "The pair values are " << inOrderVal[i] << " And " << inOrderVal[j] << endl;
            return true;
        }

        else if(sum > target) j--;

        else i++;
    }
    return false;
}

int main(){
    Node* root = NULL;
    cout <<"Enter the data to create BST" << endl;
    takeInput(root);
    int target; cout << "Enter the target value" << endl;
    cin >> target;
    if(twoSumInBST(root, target))
        cout <<"Target value pair is present" << endl;
    else
        cout << "Target value pair does not exists" << endl;

}