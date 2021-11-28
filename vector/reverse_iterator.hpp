#include "randomAccessIterator.hpp"

namespace ft {
template <class Iterator>
    class reverse_iterator : public ft::randomAccessIterator<
    typename iterator_traits<Iterator>::iterator_category,
    typename iterator_traits<Iterator>::value_type,
    typename iterator_traits<Iterator>::difference_type,
    typename iterator_traits<Iterator>::pointer,
    typename iterator_traits<Iterator>::reference
    >
{




    private:
        randomAccessIterator<T> iter
};

};