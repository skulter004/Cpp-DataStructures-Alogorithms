#include<iostream>
#include<queue>
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

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    //seperator
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previos level traversed
            cout << endl;
            //still elements in the tree
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
    } 
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(node* root){
    if(root == NULL){
        return ;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root){
    if(root == NULL){
        return ;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << "enter data for root " << endl;
    int data;
    cin >> data;
    root  = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "enter left node for " << temp -> data << endl;
        int leftdata;
        cin >> leftdata;
        if(leftdata != -1){
            temp -> left = new node(leftdata);
            q.push(temp -> left);
        }

        cout << "enter right node for " << temp -> data << endl;
        int rightdata;
        cin >> rightdata;
        if(rightdata != -1){
            temp -> right = new node(rightdata);
            q.push(temp -> right);
        }

    }
}

int main(){
    node* root = NULL;

    buildFromLevelOrder(root);

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);
    // //creating a tree
    // root = buildTree(root);
    // //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout << "level order traversal " << endl;
    // levelOrderTraversal(root);
    // cout << "in order traversal " << endl;
    // inorder(root);
    // cout << endl;
    // cout << "pre order traversal " << endl;
    // preorder(root);
    // cout << endl; cout << "post order traversal " << endl;
    // postorder(root);
    // cout << endl;
    

}