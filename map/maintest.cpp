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

   for (size_t i = 0; i < 100; i++)
   {
      c.insert(i);
   }

      for (size_t i = 30; i < 44; i++)
   {
      c.remove(i);
   }

   // c.remove(34);
   // c.remove(89);
   // c.printTree();
   std::cout << c.size() << std::endl;
    

}