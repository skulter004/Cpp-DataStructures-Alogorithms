//task is to return the smallest range from which atleast 1 element present in eachlist
//brute approach is take each element from  l list compare it with other lists and get \
all the ranges and then find the minimum amongst them on basis of their diffrence\
tc is O[n^2 * k^2]

//2nd approach is store all the head pointers of the list in the array and get the min\
and max from that array this is one range now, and now to get the smallest range\
we can do is should increase the min value of range or decrease the max value of the range\
but we cannot decrease max value as the list is already sorted in ascending order so we can \
only increase min TC is O[n * k^2]

//3rrd approach is using heap create min heap of k size inert starting element of all lists \
and keep the track of max element

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;
    node(int datan, int rows, int cols){
        data = datan;
        row = rows;
        col = cols;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> a, int k /*no of list/array*/, int len){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    for(int i = 0; i < k; i++){
        int element  = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi,element);
        minHeap.push(new node(element, i, 0));
    }
    int start = mini;
    int end = maxi;
    while(!minHeap.empty())
    {
        node* temp = minHeap.top();
        minHeap.pop();
        
        mini = temp->data;
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }
        if(temp->col +1 < len){
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1], temp->row, temp->col+1));
        }
        else{break;}
    }
    return (end-start+1);
}

int main(){
    vector<vector<int>> arr = {{2,4,5},{5,6,7},{9,10,11}};
    cout << "The smallest range is " << kSorted(arr, 3, 3);
    
}
