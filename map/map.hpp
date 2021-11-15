
# include  <functional>
#include "rbtree.hpp"
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map
{

        public :

            typedef  T mapped_type;
           typedef std::pair<const Key, T>   value_type   ;
            //  typedef Allocator allocator_type  ;
             typedef size_t size_type  ;

             typedef      T& reference;
             
             typedef  const T& const_refernce ;

             typedef T *  pointer;
             
             typedef const  T *  const_pointer;
       

            map()
            {
                std::cout << "created " << std::endl;
            }



            void insert (const value_type& val)
            {
                    std::cout <<  val.second << std::endl;
            }

            //Capacity 


            bool empty()  const {
                return tree->size() == 0;
            }
            size_type size() const
            {
                return  tree->size();
            }
        private :
            RBtree <std::pair<const Key,T> > *tree;

};