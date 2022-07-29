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

//approach is we can get the inorder for both then merge them into one\
the w'll create a BSt from the extracted inorder

//2nd approach is using inplace by converting the inplace nodes \
next is convert the convertt them into a link list and then merge them\
and convert them into a bst //try this approach by yourself three steps are\
convert BSt to ll merge 2 sorted ll(inplace) sorted ll to BST
//storing inorder
void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }
    inorder(root -> left, in);
    in.push_back(root->data);
    inorder(root -> right, in);
}

vector<int> mergeArrays(vector<int> bst1, vector<int> bst2){
    vector<int> ans(bst1.size() + bst2.size());

    int i = 0, j = 0,  k = 0  ;

    while(i < bst1.size() && j < bst2.size()){
        if(bst1[i] < bst2[j]){
            ans[k++] = bst1[i];
            i++;
        }
        else{
            ans[k++] = bst2[j];
            j++;
        }
    }

    while(i < bst1.size()){
        ans[k++] = bst1[i++];
    }

    while(j < bst2.size()){
        ans[k++] = bst2[j++];
    }
    return ans;
}
Node* inOrderToBST(int s, int e, vector<int> &inOrderVal){
    //base
    if(s > e) return NULL;

    int mid = (s+e)/2;
    Node* root = new Node(inOrderVal[mid]);
    root->left = inOrderToBST(s, mid-1, inOrderVal);
    root->right = inOrderToBST(mid+1, e, inOrderVal);
    return root;

}

Node* merge2BST(Node* root1, Node* root2){
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    vector<int> mergeArray =  mergeArrays(bst1, bst2);
    return inOrderToBST(0, mergeArray.size()-1, mergeArray);
}

int main(){
    Node* root1 = NULL;
    cout <<"Enter the data to create 1st BST" << endl;
    takeInput(root1);
    
    Node* root2 = NULL;
    cout <<"Enter the data to create 2nd BST" << endl;
    takeInput(root2);
    Node* newTree = merge2BST(root1, root2);
    levelOrderTraversal(newTree);
}