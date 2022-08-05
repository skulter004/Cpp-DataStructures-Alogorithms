#include<bits/stdc++.h>
using namespace std;

///1st approach merge all arrays into one arraysv  and then sort it tc for this is O[n*k]

//2nd using min heap starting insert 1st element of all arrays into min heap\
then insert top of heap into array and then push the next element of next arrray into the heap again \
repeat this while heap size > 1

//creating a class to keep track of the element belongs to which array
class node{
public:
    int data;
    int i;
    int j;

    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
            
};

//creating own comparator
class compare{
 public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }

};

//tc = klogk 1st part total = n*k log(k)
vector<int> mergekSorted(vector<vector<int>> array, int k){

    priority_queue<node*, vector<node*>, compare> minHeap;

    //step1 inserrt 1st element of all arrays
    for(int  i = 0; i < k; i++){
        node* top = new node(array[i][0], i, 0);
        minHeap.push(top);
    }

    vector<int> ans;
    //step2
    while(minHeap.size() > 0){
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int  i = temp->i; //i  is row index
        int j = temp->j; // j is col index

        if(j +1 < array[i].size()){
            node* next = new node(array[i][j+1], i, j+1 );
            minHeap.push(next);
        }
    }
    return ans;

}
int main(){
    vector<vector<int>> array = {{3,5,9},{1,2,3,8}};
    vector<int> ans = mergekSorted(array, 2);

    for(int i = 0; i < ans.size(); i++){
        cout <<  ans[i] << " ";
    }cout << endl;
}