#include "rbtree.hpp"
#include <map>
using namespace std;
int printtime() {
   time_t t; // t passed as argument in function time()
   struct tm * tt; // decalring variable for localtime()
   time (&t); //passing argument to time()
   tt = localtime(&t);
   cout << "Current Day, Date and Time is = "<< asctime(tt);
   return 0;
}
int main()
{
    ft::RBtree<int> list;
    size_t size = 1.9e5;
printtime();

    map<int, int> ma;
    for (size_t i = 0; i < size; i++)
    {
        // std::cout << i << std::endl;
            ma.insert( make_pair(i,i));
            if (i % 2 == 0)
                list.insert(i);
            else 
               list.insert(size - i);
    }
    printtime();
    // list.print();
    
}