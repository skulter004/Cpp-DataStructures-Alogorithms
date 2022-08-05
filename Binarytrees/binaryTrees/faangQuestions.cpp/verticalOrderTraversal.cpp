#include<bits/stdc++.h>
using namespace std;

//create vertical lines over each node and\
you will get to know what is vertical order traversal
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

vector<int> verticalOrder(node* root){
    map<int, map<int, vector<int> > > nodes;
    queue<pair<node*, pair<int, int> > > q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()){
        pair<node*, pair<int,int> > temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode -> data);

        if(frontNode -> left != NULL){
            q.push(make_pair(frontNode -> left, make_pair(hd-1 ,lvl +1)));
        }
        if(frontNode -> right ){
            q.push(make_pair(frontNode -> right, make_pair(hd +1, lvl +1)));
        }
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;

}