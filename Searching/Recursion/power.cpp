#include <iostream>
using namespace std;

// one  more formula for getting power of a num is if expo
// is even then( a^b/2 * a^b/2) if odd a * (a^b/2 * a^b/2)
//power
 int power(int num, int pow)
{
    if (pow == 0)
        return 1;

    return num * power(num, pow - 1);
}

int main(){
    int a=5,b=15;
    cout << "a= " << a << " b= " << b << endl;
}