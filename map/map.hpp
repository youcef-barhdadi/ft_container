
# include  <functional>

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map
{

        public :
           typedef T  value_type;
            //  typedef Allocator allocator_type  ;
             typedef size_t size_type  ;

             typedef      T& reference;
             
             typedef  const T& const_refernce ;

             typedef T *  pointer;
             
             typedef const  T *  const_pointer;
            typedef Allocator Allocator_type;

            typedef  randomAccessIterator<T> iterator;







            //Capacity 


            bool empty()  const {
                return false;
            }
            size_type size() const
            {
                return 1;
            }
        private :


};