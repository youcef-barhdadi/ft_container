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

      ft::Map<int, int> c;

      c.insert(ft::make_pair(1,2));
      c.insert(ft::make_pair(2,2));
      c.insert(ft::make_pair(-5,2));
      c.insert(ft::make_pair(0,2));

      c.tree.printTree();

      

      // c[1];

}