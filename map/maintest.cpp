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
   std::map<int, std::string> m1;
   ft::Map<int, std::string>  ft_m1;

   for (size_t i = 0; i < 100; i++)
   {
      m1.insert(std::make_pair(i, "string2"));
      ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
   }
   // ft::Map<int, std::string>   ft_m2(ft_m1.rbegin(), ft_m1.rend());

   std::map<int , std::string>::iterator  c  = m1.end();
   // c++;
   // c++;
   c++;
   std::cout << c->first << std::endl; 

   
   // for (ft::Map<int, std::string>::reverse_iterator cit  = ft_m1.rbegin(); cit !=  ft_m1.rend(); ++cit)
   // {
   //    std::cout << *cit << std::endl;
   // }


}