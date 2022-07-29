#include <iostream>
#include <queue>
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

//searching
bool searchBST(Node* root, int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    if(root->data > x){
        return searchBST(root->left, x);
    }
    else{
        return searchBST(root->right, x);
    }
}

///minimum value
Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

//maximum value
Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

//deletion
Node* deleteFromBST(Node* root, int val){
    
    if(root == NULL) return root;

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        ///right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left && root->right){
            ///inn this case we have 2 options either take max value from left or min value from right
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }

    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }

    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main()
{
    Node* root = NULL;

    cout << "Enter data to create BST " << endl;
    takeInput(root); 

    cout << "Printing BST" << endl;
    levelOrderTraversal(root);

    int x; cout << "enter the element you want to search" << endl;
    cin >> x;

    if(searchBST(root, x)){
        cout << "element is present " << endl;
    }
    else 
        cout << "element is not present " << endl;

    cout << "minimum value of the tree is " << minVal(root)->data << endl;
    

    cout << "maximum value of the tree is " << maxVal(root)->data << endl;

    cout << "Enter the element you want to delete " << endl;
    cin >> x;

    root = deleteFromBST(root, x );
    cout << "Printing BST" << endl;
    levelOrderTraversal(root);

}