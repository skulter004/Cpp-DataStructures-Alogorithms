#include <iostream>
#include <queue>
using namespace std;

//driver code for creating a BST 
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

//we can use inorrder approach directly and store the ans in a node
void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }
    inorder(root -> left, in);
    in.push_back(root->data);
    inorder(root -> right, in);
}

Node* flatten(Node* root){
    vector<int> inOrderVal;
    inorder(root, inOrderVal);
    int n = inOrderVal.size();
    //this is the node we have created to store our linkedlist
    Node* newRoot = new Node(inOrderVal[0]);
    Node* curr = newRoot;

    ///ass wee havee storedd 0th value already start from 1
    for(int i = 1; i < n; i++){
        Node* temp = new Node(inOrderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //3rd step pointing the both nodes of the last node of the list to the null
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;

}

// aa driver code just to traverse the node off list
void traverseList(Node* list){
    while(list->right != NULL){
        cout << list->data << " ";
        list = list->right;
    }
}

int main(){
    Node* root = NULL;
    cout <<"Enter the data to create BST" << endl;
    takeInput(root);
    Node* list = flatten(root);
    traverseList(list);
}
