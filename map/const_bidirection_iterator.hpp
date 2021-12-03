#pragma once
#include <iostream>
#include <memory>
#include <iterator>
#include "bidirectional_iterator.hpp"

namespace ft {
template <class T>
class const_bidirectional_iterator  : public std::iterator<std::bidirectional_iterator_tag, T> 
{
    public:

        typedef typename T::reference reference;
        typedef typename T::pointer pointer;

        const_bidirectional_iterator() 
        {
            this->_node = nullptr;
        }

        const_bidirectional_iterator(T *node) 
        {
            this->_node = node;
        }

        const_bidirectional_iterator(const_bidirectional_iterator  &n) 
        {
            this->_node = n._node;
        }


        const_bidirectional_iterator(bidirectional_iterator<T>  &n) 
        {
            this->_node = n._node;
        }


        reference operator*() const
        {
            return _node->value;
        }

 

        pointer operator->()
        {
            return &(_node->value);
        }
        
        const_bidirectional_iterator operator++(void)
        {
            T *tmp   = _node->findNextNode(_node);
            if (tmp != nullptr)
                _node = tmp;
            return *this;
        }

        const_bidirectional_iterator operator++(int)
        {
            const_bidirectional_iterator copy(this->_node);
            ++(*this);
            return copy;
        }
        
        const_bidirectional_iterator operator--(void)
        {
            T *tmp   = _node->findPrevious(_node);
            if (tmp != nullptr)
                _node = tmp;
            return *this;
        }


        const_bidirectional_iterator operator=(const_bidirectional_iterator &b)
        {
            this->_node = b._node;
            return (*this);
        }

      friend  bool  operator==(const const_bidirectional_iterator &lhr, const const_bidirectional_iterator &rhr)
      {
          return (lhr._node) == rhr._node; 
      }

        friend  bool  operator!=(const const_bidirectional_iterator &lhr, const const_bidirectional_iterator &rhr)
        {
            return (lhr._node) != rhr._node; 
        }

        const_bidirectional_iterator operator--(int)
        {
         const_bidirectional_iterator copy(this->_node);
            --(*this);
            return copy;
        }


        T *base()
        {
            return _node;
        }

        operator  const_bidirectional_iterator<const T> () 
        {
                return const_bidirectional_iterator<const T>(_node);
        }

        operator  const_bidirectional_iterator<const T> () const
        {
                return const_bidirectional_iterator<const T>(_node);
        }

        T *_node;

    private:
};

};