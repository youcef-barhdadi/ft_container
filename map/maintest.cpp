#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>  



int main()
{
   int foo[] ={10, 20, 5, 15, 25};
  int bar[]={15,10,20};
   std::sort(foo, foo+5, std::less<int>());



}