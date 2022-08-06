#include<iostream>
using namespace std;
void insersort(int arr[],int n){

    int i = 1;

    while(i < n){
        int temp = arr[i];
        int j  = i-1;

        while(j >= 0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else {
               break;
            }

            j--;
        }
        arr[j+1] = temp;
        i++;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i] << " ";
    }
   
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout << "Enter array element " << endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insersort(arr,n);

}
