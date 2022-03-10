#pragma once
#include <iostream>
#include <memory>
#include <iterator>
#include "rbtree.hpp"
namespace ft
{

    template <class T>
    class const_bidirectional_iterator;
    template <class T>
    class bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        // #ifdef MAP
        typedef  T& reference;
        typedef  T* pointer;



        operator bidirectional_iterator<T>  () const 
        {
                return bidirectional_iterator<const T>(this->_node, this->root);
        } 

        bidirectional_iterator()
        {
            // this->_node = NULL;
        }
    //const pair
       
        bidirectional_iterator(ft::node<T> *node,  ft::node<T> ** root) : root(root)
        {
            this->_node = node;
        }
        //  bidirectional_iterator(ft::node<const T> *node, ft::node<const T> **root) : root(root)
        // {
        //     this->_node = node;
        // }

        
           operator const_bidirectional_iterator<const T> ()
            {
                     return const_bidirectional_iterator<const T>((node <const T> *)this->_node, (node <const T> *const *)this->root);
            } 



        // bidirectional_iterator(ft::node<const T> *node, ft::node<const T> **root) : root(root)
        // {
        //     this->_node = node;
        // }

        bidirectional_iterator(const bidirectional_iterator &n)
        {
            this->_node = n._node;
            this->root = n.root;
        }

        reference operator*()
        {
            return _node->value;
        }

        // bidirectional_iterator &operator=(const_bidirectional_iterator<T> &n)
        // {
        //     this->_node = n._node;
        //     this->root = root;
        //     return (*this);
        // }

        bidirectional_iterator &operator=(const bidirectional_iterator<T> &n)
        {
            // if (this == &n)
            //     return (*this);
            this->_node = n._node;
            this->root = n.root;
            return (*this);
        }

        pointer operator->()
        {
            return &(_node->value);
        }
                pointer operator->() const
        {
            return &(_node->value);
        }

        bidirectional_iterator operator++(void)
        {
            ft::node<T> *tmp = _node->findNextNode(_node);
            _node = tmp;
            return *this;
        }

        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator copy(this->_node, root);
            ++(*this);
            return copy;
        }

        bidirectional_iterator operator--(void)
        {
            ft::node<T> *tmp;

            if (_node != NULL && *(this->_node) == *((*root)->findSmallest(*root)))
                return (*this);
            if (_node == NULL)
            {
                tmp = (*root)->findBigger(*root);
            }
            else
                tmp = _node->findPrevious(_node);
            _node = tmp;
            return *this;
        }

        friend bool operator==(const bidirectional_iterator &lhr, const bidirectional_iterator &rhr)
        {
            if (lhr._node == NULL && rhr._node == NULL)
                return (true);
            if (lhr._node == NULL || rhr._node == NULL)
                return (false);
            return (lhr._node) == rhr._node;
        }

        friend bool operator!=(const bidirectional_iterator &lhr, const bidirectional_iterator &rhr)
        {
            return !(lhr == rhr);
        }

        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator copy(*this);
            operator--();
            return copy;
        }

        T *base()
        {
            return _node;
        }

        // operator  const_bidirectional_iterator<T> ()
        // {
        //     return const_bidirectional_iterator<T>(this->_node,*(this->root));
        // }

       ft::node<T> *_node;
        ft::node<T>  **root;
    private:
    };

    template <class T>
    class const_bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
          typedef  T& reference;
        typedef  T* pointer;

            const_bidirectional_iterator()
            {
                this->_node = NULL;
            }



         

        //  template <typename T2>
        const_bidirectional_iterator(ft::node<T> *node, ft::node<T> *const*root) :root(root)
        {
            this->_node = node;
            // this->root = root;
        }

        const_bidirectional_iterator(const const_bidirectional_iterator &n)
        {
            this->_node = n._node;
            this->root = n.root;
        }

        const_bidirectional_iterator(const bidirectional_iterator<T> &n) : root(n.root)
        {
            this->_node = n._node;
            // this->root = n.root;
        }

        // const_bidirectional_iterator(const bidirectional_iterator<const T> &n)
        // {
        //     this->_node = n._node;
        //     this->root = n.root;
        // }

        const_bidirectional_iterator operator&=(bidirectional_iterator<T> my)
        {
            this->_node = my._node;
            return (*this);
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
            node<T> *tmp = _node->findNextNode(_node);
            _node = tmp;
            return *this;
        }

        const_bidirectional_iterator operator++(int)
        {
            const_bidirectional_iterator copy(this->_node, this->root);
            ++(*this);
            return copy;
        }

        const_bidirectional_iterator operator--(void)
        {
             ft::node<T> *tmp;

            if (_node != NULL && *(this->_node) == *((*root)->findSmallest(*root)))
                return (*this);
            if (_node == NULL)
                tmp = (*root)->findBigger(*root);
            else
                tmp = _node->findPrevious(_node);
            _node = tmp;
            return *this;
        }

        const_bidirectional_iterator operator=(const_bidirectional_iterator b)
        {
            this->_node = b._node;
            this->root = b.root;
            return (*this);
        }


        template <typename T1>
        const_bidirectional_iterator operator=(const bidirectional_iterator<T1> b)
        {
            this->_node = (ft::node<const T1 > *const) b._node;
            this->root = (ft::node<const T1 > *const*)b.root;
            return (*this);
        }

        friend bool operator==(const const_bidirectional_iterator &lhr, const const_bidirectional_iterator &rhr)
        {
            return (lhr._node) == rhr._node;
        }

        friend bool operator!=(const const_bidirectional_iterator &lhr, const const_bidirectional_iterator &rhr)
        {
            return lhr._node != rhr._node;
        }

        const_bidirectional_iterator operator--(int)
        {
            const_bidirectional_iterator copy(this->_node, this->root);
            operator--();
            return copy;
        }


        operator  bidirectional_iterator<T>()
        {
            return bidirectional_iterator<T>(this->_node, this->root);
        }

        ft::node<T> *base()
        {
            return _node;
        }

       ft::node<T>   * _node;
        ft::node<T> *const*   root;

    private:
    };

};
