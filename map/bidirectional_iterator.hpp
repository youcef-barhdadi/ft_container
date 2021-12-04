#pragma once
#include <iostream>
#include <memory>
#include <iterator>
#include "const_bidirection_iterator.hpp"


namespace ft {

template <class T>
class const_bidirectional_iterator  ;
template <class T>
class bidirectional_iterator  : public std::iterator<std::bidirectional_iterator_tag, T> 
{
    public:

        typedef typename T::reference reference;
        typedef typename T::pointer pointer;

        bidirectional_iterator() 
        {
            // this->_node = nullptr;
        }

        bidirectional_iterator(T *node) : _node(node)
        {
            this->_node = node;
        }

        reference operator*() 
        {
             return _node->value;
        }


        // bidirectional_iterator &operator=(const_bidirectional_iterator<T> &n)
        // {
        //     this->_node = n._node;
        //     return (*this);
        // }


        bidirectional_iterator &operator=(const bidirectional_iterator<T> &n)
        {
            if (this == &n)
                return (*this);
            this->_node = n._node;
            return (*this);
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


        T *base()
        {
            return _node;
        }

        T *_node;

    private:
};



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

        const_bidirectional_iterator operator&=(bidirectional_iterator<T> my)
        {
            this->_node = my._node;
            return (*this);
        }

        const_bidirectional_iterator(const const_bidirectional_iterator  &n) : _node(n._node)
        {
            this->_node = n._node;
        }


        const_bidirectional_iterator(const bidirectional_iterator<T>& n) : _node(n._node)
        {
            // this->_node = n._node;
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


        const_bidirectional_iterator operator=(const_bidirectional_iterator b)
        {
            this->_node = b._node;
            return (*this);
        }

        const_bidirectional_iterator operator=(bidirectional_iterator<T> b)
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
