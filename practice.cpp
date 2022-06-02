#include <iostream>
using namespace std;
#define max2(a,b) (a>b ? a :b)
void increment( int& c , int& d , int e = 1){
    c++;
    d++;
    cout<<"e= "<<e<<endl;
}

//power
 int power(int num, int pow)
{
    if (pow == 0)
        return 1;

    return num * power(num, pow - 1);
}

//factorial
int fact(int num)
{
    if (num == 0)
        return 1;

    return num * fact(num - 1);
}

//print counting
void counting(int limit){
    if(limit == 0 )
        return ;
    
    cout << limit <<" ";
    
    counting(limit-1);
    return ;
}

//printing fibonacci
void fibnac(int a , int b,int length){
    
    if(length==0)

        return ;

    cout<< a << " " ; 

    fibnac(b,a+b,length-1);

    return ;
}

//leet code 509 return the desired numbered element from the fibonacci series with 0 indexing
int fibindex(int pos){
    if(pos == 0)
        return 0; 
    if(pos == 1)
        return 1;

    return fibindex(pos-2) + fibindex(pos-1); 
    
}
// stair problem  //get the no of ways of getting to the nth numbr of stairs
int stair(int nthstair){
     if(nthstair < 0)
       return 0;
     if(nthstair == 0)
       return 1;

       return stair(nthstair-1) +  stair(nthstair-2);
}
//say digits 
void saydigits(int n , string *arr0){
        if(n==0)
        return ;

        saydigits(n/10 , arr0);
        cout<<arr0[n%10]<<" ";
}

// check sorted array with recusrion
bool issorted(int *arr , int size){
    if(size==0||size==1)
    return 1;
    if(arr[0]>arr[1])
    return 0;

    return issorted(arr +1 , size -1 );
    
}

//sum of array using recursion
int arrsum(int *arr ,int size){
    if(size == 0)
    return 0;

    return arr[0] +  arrsum( arr + 1 , size-1 );
}

// linear search using recursion
bool linesearch(int *arr , int size , int target){
    if(size == 0)
    return false;
    
    if(arr[0]==target)
    return true;

    return linesearch( arr +1 , size -1 , target);
    
}

// binary search using recursion for Bsearch array must be sorted
bool binarysearch(int *arr ,  int size , int s , int e , int target){
     
     int mid = (s+e)/2;
 
     if(s < e) 
         return 0;

     if(arr[mid] == target)
         return 1;

     if(arr[mid]>target)
         return (arr , size , s , mid -1 , target);
    
         return (arr , size , mid +1 , e , target);

}

//reversing a string using recursion
void revString( string &str , int strtIndx , int endIndx ){
    
    if (endIndx < strtIndx ){
        cout << "reverse of the string is " << str << endl;
        return ;
    }

    else{
        swap(str[strtIndx] , str[endIndx]);
    }

    revString(str , strtIndx +1 , endIndx -1 );   
}

//string palindrome using reccursion mostly same as of reversing string
bool checkPal( string str , int strtIndx , int endIndx ){
    
    if (endIndx < strtIndx){
        return 1 ;
    }

    if(str[strtIndx] != str[endIndx]){
        return 0;
    }
    else{
        return checkPal ( str  , strtIndx +1 , endIndx -1);
    }      
}

// one  more formula for getting power of a num is if expo
// is even then( a^b/2 * a^b/2) if odd a * (a^b/2 * a^b/2)
// getting the desired power of a numbr using recursion
int getPower(int num , int expo){
    
    if(expo == 0){
        return 1;
    }

    if(expo == 1){
        return num;
    }

    return num * getPower(num , expo -1);
}

//bubble sort using recursion
void bubbleSort(int *arr , int size ){
    
    if(size == 0 || size == 1){
        return ;
    }
    
    for(int i=0 ; i<size -1; i++){
    if(arr[i] > arr[i+1]){
        swap(arr[i] , arr[i+1]);
    } 
    
    }
        return bubbleSort(arr  , size-1 );
   
}

//selection sort using recursion
void slecSort(int* arr , int itr , int size){
    if(size == 0 || size == 1 || itr == size ){
        return;
    }
     
     for(int i=itr+1 ; i<size ; i++ ){
         if(arr[itr]>arr[i]){
             swap(arr[itr] , arr[i]);
         }
     }

     return slecSort(arr, itr+1 ,size);

}

//insertion sort usign recursion
void insertionSort(int* arr , int itr , int size){
    if(size == 0 || size == 1 || itr == size ){
        return;
    }
    int temp = arr[itr];
    for(int i=itr-1 ; i >=0 ; i--){
        if(arr[i] > arr[itr]){
            arr[i+1] = arr[i];
        }
        else{
            break;
        }
    }
    arr[itr] == temp;
    
    return insertionSort(arr, itr +1 , size);

}

//merge sort using recursion
void mergeSort(int* arr , int size){
    
}
int main(){

    // int a=5,b=15;
    // cout << max2(a,b) << endl;
    // cout << "a= " << a << " b= " << b << endl;
    // increment(a,b);
    // cout << "a= " << a << " b= " << b << endl;
    // cout << "power is = " << power(3, 3) << endl;
    // cout << "factorial is = " << fact(3) << endl;
    // counting(5);
    // fibnac(0,1,10);
    // cout<<endl;
    // cout << fibindex(4) << endl;
    // cout << stair(4) << endl; 
    // string arr0[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    // saydigits(6969 , arr0);
    //     cout<<endl;
    // int arr[] = {1,2,3,4,5,6,7,8};
    
    // int size = sizeof(arr) / sizeof(int);

    // if(issorted( arr , size) )
    //     cout << "sorted" << endl;
    // else
    //     cout << "not sorted" << endl;
    
    // cout << arrsum( arr , size )<<endl;
   
    // cout << "using linear searching " << linesearch(arr , size , 10) <<endl;

    // cout << "using binary searching " << binarysearch(arr , size , 0 , size , 10 ) <<endl;
    
    // string str = "sss";
    
    // string origstring = str ;

    // revString(str , 0 , str.size() -1 );
    
    // if(checkPal(str , 0 , str.size() -1 )){
    //     cout << "string is a valid palindrome " <<endl;
    // } 
    // else{
    //     cout << "string is not a valid palindrome " << endl;
    //  }
    // int num,expo;
    // cout <<"enter the number" << endl;
    // cin >> num;
    
    // cout <<"enter the power for the number" << endl;
    // cin>>expo;

    // cout << getPower(num , expo);
    
    // //bubble sort
    // int arr[] = {5,4,3,2,1};
    // int size = sizeof(arr)/sizeof(int);
    // bubbleSort(arr , size );

    // for(int i=0 ; i<size ; i++ ){
    //     cout << arr[i] << " ";
    // }

    //selection sort
    //  int arr[] = {5,4,3,2,1 , 56, 3, 2 ,0};
    //  int size = sizeof(arr)/sizeof(int);
    //  slecSort(arr , 0 , size );

    //    for(int i=0 ; i<size ; i++ ){
    //        cout << arr[i] << " ";
    //    }

    //insertion sort
    //   int arr[] = {5,4,3,2,1 , 56, 3, 2 ,0};
    //   int size = sizeof(arr)/sizeof(int);
    //   insertionSort(arr , 0 , size );

    //     for(int i=0 ; i<size ; i++ ){
    //        cout << arr[i] << " ";
    //     }
         
           return 0;
}
