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

//creates mapping and returns target node
node* createParentMapping(node* root, int target, map<node*,node*> &nodeToParent){

    node* result = NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.front();

        if(front -> data == target){
            result = front;
        }
        if(front -> left){
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }
        if(front -> right){
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }
    }
    return result;
    
}

int burnTree(node* root, map<node*,node*> &nodeToParent){

    map<node*, bool> visited;
    queue<node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()){

        bool flag = 0;
        int size = q.size();

        for(int i = 0; i < size; i++){
            //proccesing neighbouring node
            node* front = q.front();
            q.pop();

            if(front -> left &&  !visited[front -> left]){
                flag = 1;
                q.push(front -> left);
                visited[front -> left] = true;
            }
            if(front -> right &&  !visited[front -> right]){
                flag = 1;
                q.push(front -> right);
                visited[front -> right] = true;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        
        
        }
        cout << ans;
        if(flag == 1){
            ans++;
        }
    }
    return ans;

}

int minTime(node* root, int target){
    //1: create node to parent mapping
    //2: find target node
    //3: burn the tree in min time

    map<node*,node*> nodeToParent;
    node* targetNode = createParentMapping(root, target, nodeToParent);

    int ans =  burnTree(targetNode, nodeToParent);
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    //give target as per the elements of your tree
    
    cout << minTime(root, 8);
    //1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
}