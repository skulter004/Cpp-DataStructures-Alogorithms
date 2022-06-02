#include <iostream>
int main()
{
  int a=9, b=1, c=3;
  int result1=((a==9)||(b=3));
  std::cout<<"Result1 : "<<result1<<" b : "<<b;
  int result2=((b>c)&&(c=0));
  std::cout<<"\nResult2 : "<<result2<<" c : "<<c;\
}