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

int findPosition(int in[], int element, int n){
    for(int i = 0; i < n; i++){
        if(in[i] == element)
        return i;
    }
    return -1;
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

node* solve(int in[], int pre[], int &index, int inorderStart, int inOrderEnd, int n){
    //base case
    if(index >= n || inorderStart > inOrderEnd){
        return NULL;
    }
    int element = pre[index++];
    node* root = new node(element);
    int position = findPosition(in, element, n);

    //reccursive call
    root -> left = solve(in, pre, index, inorderStart, position-1,n );
    root -> right = solve(in, pre, index, position+1, inOrderEnd,n );

    return root;

}

node* buildTreeBack(int in[] , int pre[], int n){
    int preIndex = 0;
    return solve(in, pre, preIndex,0 ,n-1, n);
     
}


int main(){
    int n =6;
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    node* root = NULL;
    root =  buildTreeBack(in, pre, n);
    levelOrderTraversal(root);
    
}