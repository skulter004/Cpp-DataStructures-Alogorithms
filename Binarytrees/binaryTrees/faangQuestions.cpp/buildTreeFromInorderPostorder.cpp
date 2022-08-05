#include<bits/stdc++.h>
using namespace std;
//segmentation fault
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

void createMapping(int in[], map<int,int> &nodetoindex, int n ){
    for(int i = 0; i < n; i++){
        nodetoindex[in[i]] = i;
    }
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
node* solve(int in[], int post[], int &index, int inorderStart, int inOrderEnd, int n, map<int,int> &nodetoindex){
    //base case
    if(index < 0 || inorderStart > inOrderEnd){
        return NULL;
    }
    int element = post[index++];
    node* root = new node(element);

    int position = nodetoindex[element];

    //reccursive call
    root -> right = solve(in, post, index, position+1, inOrderEnd, n, nodetoindex);
    root -> left = solve(in, post, index, inorderStart, position-1,n, nodetoindex );

    return root;

}

node* buildTreeBack(int in[] , int post[], int n){
    int postIndex = n -1;
    map<int,int> nodetoindex;
    createMapping(in,nodetoindex,n);
    return solve(in, post, postIndex,0 ,n-1, n, nodetoindex);
     
}

int main(){
    int n =8;
    int in[] = {4,8,2,5,1,6,3,7};
    int pre[] = {8,4,5,2,6,7,3,1};
    node* root = NULL;
    root =  buildTreeBack(in, pre, n);
    levelOrderTraversal(root);
    
}