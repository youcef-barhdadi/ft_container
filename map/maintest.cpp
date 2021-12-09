#include "rbtree.hpp"
#include <map>
# include "map.hpp"
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

   ft::RBtree<int> c;
   ft::RBtree<int> c1;

   for (size_t i = 0; i < 100; i++)
   {
      c.insert(i);
   }

      for (size_t i =110; i < 2000; i++)
   {
      c.remove(i);
   }

   c.printTree();
   std::cout << c.size() << std::endl;
    

}