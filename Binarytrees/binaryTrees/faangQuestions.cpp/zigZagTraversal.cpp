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

vector<int> zigZagTraversal(node* root){
    
    vector<int> result;
    
    if(root == NULL){
        return result ;
    }

    queue<node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);

        for(int i = 0; i < size; i++){
            node* frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight ? i : size-i-1;
            temp[index] = frontNode -> data;

            if(frontNode -> left){
                q.push(frontNode -> left);
            }
            if(frontNode -> right){
                q.push(frontNode -> right);
            }

        }
        //direction change
        leftToRight = !leftToRight;

        for(auto i : temp){
            result.push_back(i);
        }
    }   
    return result;
}

int main(){
    
    node* root = NULL;
    root =  buildTree(root);

    vector<int> ans = zigZagTraversal(root);

    for(int  i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}