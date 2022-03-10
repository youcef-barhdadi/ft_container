#include "map.hpp"
#include "pair.hpp"



int main()
{
     ft::Map<int,  int> *l  = new  ft::Map<int,  int>();


     for (size_t i = 0; i < 1000000; i++)
     {
         (*(l))[i] = i;
     }

     delete l;
    //  l = NULL;
     system("leaks a.out");
    
        

    // l.insert(ft::make_pair(5,4));
}