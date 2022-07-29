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

//one approaach is that the take input funtion can be called for earch\
elementt of the preorder but for thhicc the tc will be O[n^2]

//2nd approach sort the preorder we will get the inorrder and we \
have already written the code for tree from pre and in order
//but still tc O[nlogn]

//best approach is the validate bst method we use to check if the \
element of pre order lies between the range of the nodes thn we can insert it

//we can also slve it without using the min integer
Node* solve(vector<int> &preOrder, int min, int max, int &i){
    if(i >= preOrder.size()) return NULL;

    if(preOrder[i] < min || preOrder[i] > max) return NULL;

    Node* root = new Node(preOrder[i++]);
    root->left = solve(preOrder, min, root->data, i);
    root->right = solve(preOrder, root->data, max, i);

    return root;
}

Node* preOrderToBST(vector<int> preOrder){
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(preOrder, min, max, i);
}

int main(){

    vector<int> preOrder = {20, 10, 5, 15, 13, 35, 30, 42};

    Node* root = preOrderToBST(preOrder);
    levelOrderTraversal(root);
}