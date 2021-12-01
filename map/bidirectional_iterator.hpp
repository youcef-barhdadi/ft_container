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
            return _node->root->value;
        }


    private:
        T *_node;
};

};