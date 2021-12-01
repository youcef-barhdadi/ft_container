
#include "rbtree.hpp"
#include "pair.hpp"
#include "bidirectional_iterator.hpp"


namespace ft {
template<
    class Key,
    class T
    // class Compare = std::less<Key>
    // class Allocator = std::allocator<pair<const Key, T> >
> class map
{

        public :

            typedef  T mapped_type;
           typedef pair< Key, T>   value_type   ;
            //  typedef Allocator allocator_type  ;
             typedef size_t size_type  ;

             typedef      T& reference;
             
             typedef  const T& const_refernce ;

             typedef T *  pointer;
             
             typedef const  T *  const_pointer;

             typedef ft::bidirectional_iterator<RBtree <ft::pair<Key, T> > >    iterator; 
       

            map()
            {
                std::cout << "created " << std::endl;
                tree = new RBtree <pair< Key,T> >();

            }



            void insert ( value_type val)
            {
                    // std::cout <<  val<< std::endl;

                    tree->insert(val);
            }

            //Capacity 


            bool empty()  const {
                return tree->size() == 0;
            }
            size_type size() const
            {
                return  tree->size();
            }   



              iterator begin()
              {
                  return iterator(this->tree);
              }    

        private :
           ft::RBtree <ft::pair< Key,T> > *tree;
};

};