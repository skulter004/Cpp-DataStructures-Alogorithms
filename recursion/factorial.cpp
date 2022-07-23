#include <iostream>
using namespace std;

//factorial
int fact(int num)
{
    if (num == 0)
        return 1;

    return num * fact(num - 1);
}

int main(){

    cout << "factorial is = " << fact(3) << endl;
}