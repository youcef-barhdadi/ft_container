#pragma once
#include <iostream>
#include <memory>
#include <iterator>


namespace ft {
template <class T>
class bidirectional_iterator  : public std::iterator<std::bidirectional_iterator_tag, T> 
{
    public:

        typedef typename T::reference reference;
        typedef typename T::pointer pointer;

        bidirectional_iterator() 
        {
            this->_node = nullptr;
        }

        bidirectional_iterator(T *node) 
        {
            this->_node = node;
        }

        reference operator*()
        {
            return _node->value;
        }

        
        pointer operator->()
        {
            return &(_node->value);
        }



        bidirectional_iterator operator++(void)
        {
            T *tmp   = _node->findNextNode(_node);
            if (tmp != nullptr)
                _node = tmp;
            return *this;
        }

        bidirectional_iterator operator++(int)
        {
         bidirectional_iterator copy(this->_node);
            ++(*this);
            return copy;
        }



        
        bidirectional_iterator operator--(void)
        {
            T *tmp   = _node->findPrevious(_node);
            if (tmp != nullptr)
                _node = tmp;
            return *this;
        }

      friend  bool  operator==(const bidirectional_iterator &lhr, const bidirectional_iterator &rhr)
      {
          return (lhr._node) == rhr._node; 
      }


          friend  bool  operator!=(const bidirectional_iterator &lhr, const bidirectional_iterator &rhr)
      {
          return (lhr._node) != rhr._node; 
      }

        bidirectional_iterator operator--(int)
        {
         bidirectional_iterator copy(this->_node);
            --(*this);
            return copy;
        }

        T *_node;

    private:
};

};