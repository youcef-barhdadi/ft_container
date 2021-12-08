
#include "rbtree.hpp"
#include "pair.hpp"
#include "bidirectional_iterator.hpp"
#include "reverse_bidirection_iterator.hpp"
#include<iostream>
#include<ctime> // used to work with date and time
// using namespace std;
// int printtime() {
//    time_t t; // t passed as argument in function time()
//    struct tm * tt; // decalring variable for localtime()
//    time (&t); //passing argument to time()
//    tt = localtime(&t);
//    cout << "Current Day, Date and Time is = "<< asctime(tt);
//    return 0;
// }

namespace ft {
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<pair<const Key, T> >
> class Map
{

        public :

            typedef  T mapped_type;
           typedef pair< Key, T>   value_type   ;
           typedef Key   key_type   ;
            //  typedef Allocator allocator_type  ;
             typedef size_t size_type  ;

             typedef      T& reference;
             
             typedef  const T& const_refernce ;

             typedef T *  pointer;
             
             typedef const  T *  const_pointer;

            typedef ft::bidirectional_iterator<node <ft::pair<Key, T> > >    iterator; 
            typedef ft::const_bidirectional_iterator<node <ft::pair< Key, T> > > const_iterator; 
            typedef ft::reverse_bidirection_iterator<iterator>  reverse_iterator;
            typedef ft::reverse_bidirection_iterator<const_iterator>  const_reverse_iterator;
 



            typedef  Compare   key_compare;
            typedef    Allocator   allocator_type;

            explicit Map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
            {

                // this->tree = new RBtree<value_type>();
            
                // alloc.construct(tree,  new RBtree<value_type>());
              
            }

            template <class InputIterator>
            Map (InputIterator first, InputIterator last,
              const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
            {
                while (first != last)
                {
                  std::cout << "insetring "   <<  *(++first)  << *last << std::endl;
                  this->insert(*(++first));
                }
            }

            Map (const Map& x)
            {
                const_iterator c =   x.begin();
                size_t size = x.size();
              
                while (size)
                {
                  this->insert(*c);
                  ++c;
                  size--;
                }
            }



            void insert (const value_type val)
            {
                    tree.insert(val);
            }

            //Capacity 


            bool empty()  const {
                return tree.size() == 0;
            }
            size_t size() const
            {
                return  tree.size();
            }   


//findBigger
              iterator begin()
              {
                  return iterator( tree.findSamllest(this->tree.root), tree.root);
                //   return iterator((this->tree.root));
              }

              reverse_iterator rbegin()
              {
                return reverse_iterator(this->end());
              }

              const_reverse_iterator rbegin() const
              {
                  return  const_reverse_iterator(this->end());
              }

              reverse_iterator rend()
              {
                 return reverse_iterator(this->begin());
              }
              const_reverse_iterator rend() const
              {
                  return const_reverse_iterator(this->begin());
              }

               const_iterator begin() const
              {
                //   std::cout << "root adress is " << this->tree.root << std::endl;
                  return const_iterator( this->tree.findSamllest(tree.root), tree.root);
                //   return iterator((this->tree.root));
              }


            iterator end()
            {
                return iterator(NULL, tree.root);
            } 


              const_iterator end() const 
            {
                return const_iterator(NULL, tree.root);
            }  


            mapped_type& operator[] (const key_type& k)
            {

                 iterator  iter  =  this->find(k);
                if (iter == this->end())
                {
                    this->insert(ft::make_pair(k, mapped_type()));
                }
                iter = this->find(k);
                return  (*iter).second;

            }
             iterator find (const key_type& k)
             {
                   return iterator(this->tree.find( ft::pair<key_type, mapped_type>(k, mapped_type()) ), tree.root);
             }


            void erase (iterator position)
            {
                tree.remove(*position);
            }

            size_type erase (const key_type& k)
            {
                tree.remove(ft::make_pair<Key, T> (k, T()));
            }

              void erase (iterator first, iterator last)
              {
                  while (first != last)
                  {
                    tree.remove(*first);
                    ++first;
                  }
              }

              void clear()
              {
                  erase(this->begin(), this->end());
              }

              void swap (Map& x)
              {

              }

            size_type count (const key_type& k) const
            {
              return 0;
            }

            iterator lower_bound (const key_type& k)
            {
              // return iterator()
            }
            const_iterator lower_bound (const key_type& k) const
            {

            }
            iterator upper_bound (const key_type& k)
            {
              
            }
            const_iterator upper_bound (const key_type& k) const
            {

            }

          pair<const_iterator,const_iterator> equal_range (const key_type& k) const
          {

          }

          pair<iterator,iterator>             equal_range (const key_type& k)
          {

          }

          allocator_type get_allocator() const
          {
            return this->my_alloc;
          }
          key_compare key_comp() const
          {

          }

          // value_compare value_comp() const
          // {

          // }
          size_type max_size() const
          {

          }

      



           ft::RBtree <ft::pair< Key,T> > tree;
        private :
        allocator_type  my_alloc;
};

};