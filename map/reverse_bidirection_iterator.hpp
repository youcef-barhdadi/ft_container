#pragma once
#include <iostream>
#include <memory>
#include <iterator>
#include "bidirectional_iterator.hpp"


namespace ft {
	template <class Iterator> 
    class reverse_iterator {
        public: 
                typedef Iterator	iterator_type;

                typedef typename   Iterator::reference  reference;
                typedef typename   Iterator::pointer  pointer;

                Iterator iter;


                reverse_iterator()
                {

                }
                reverse_iterator(const Iterator  & iter)
                {
                    this->iter = iter;
                }
                    
                reference operator*() 
                {
                    iterator_type  pre = iter;
                    --pre;
                    return  (*pre);
                }

                pointer operator->()
                {
                    iterator_type  pre(iter);
                    --pre;
                    return  &(*pre);
                }
                        
                reverse_iterator operator++(void)
                {
                    --iter;
                    return *this;
                }

                reverse_iterator operator++(int)
                {
                    reverse_iterator copy(iter);
                    operator++();
                    return copy;
                }



                reverse_iterator operator--(void)
                {   
                    ++iter;
                    return *this;
                }

                
                reverse_iterator operator--(int)
                {
                    reverse_iterator copy(iter);
                    operator--();
                    return copy;
                }


                                
                reverse_iterator& operator=(const reverse_iterator  &s)
                {
                    this->iter = s.iter;
                    return  (*this);
                }



                operator  reverse_iterator<const iterator_type>() 
                {
                    return reverse_iterator<const iterator_type>(iter);
                }   
                friend  bool  operator==( reverse_iterator &lhr,  reverse_iterator  &rhr)
                {
                    return lhr.iter == rhr.iter; 
                }


                friend  bool  operator!=(const reverse_iterator &lhr, const reverse_iterator  &rhr)
                {
                    return lhr.iter != rhr.iter; 
                }

                Iterator base()
                {
                    return this->iter;
                }

        private:

    };


    template <class Iterator> 
      class const_reverse_iterator {
        public: 
                typedef Iterator	iterator_type;

                typedef typename   Iterator::reference  reference;
                typedef typename   Iterator::pointer  pointer;

                Iterator iter;


                const_reverse_iterator()
                {

                }
                const_reverse_iterator(const Iterator  & iter)
                {
                    this->iter = iter;
                }
                    
                reference operator*() 
                {
                    iterator_type  pre = iter;
                    --pre;
                    return  (*pre);
                }

                pointer operator->()
                {
                    iterator_type  pre(iter);
                    --pre;
                    return  &(*pre);
                }
                        
                const_reverse_iterator operator++(void)
                {
                    --iter;
                    return *this;
                }


                const_reverse_iterator operator++(int)
                {
                    const_reverse_iterator copy(iter);
                    operator++();
                    return copy;
                }



                const_reverse_iterator operator--(void)
                {   
                    ++iter;
                    return *this;
                }

                
                const_reverse_iterator operator--(int)
                {
                    const_reverse_iterator copy(iter);
                    operator--();
                    return copy;
                }


                                
                const_reverse_iterator& operator=(const const_reverse_iterator  &s)
                {
                    this->iter = s.iter;
                    return  (*this);
                }
                 template <class T> 
                const_reverse_iterator& operator=(const reverse_iterator< T>  &s)
                {
                    this->iter = s.iter;
                    // this->iter.root = s.iter;
                    return  (*this);
                }

                operator  const_reverse_iterator<const const_reverse_iterator>() 
                {
                    return reverse_iterator<const const_reverse_iterator>(iter);
                }   
                friend  bool  operator==( const_reverse_iterator &lhr,  const_reverse_iterator  &rhr)
                {
                    return lhr.iter == rhr.iter; 
                }


                friend  bool  operator!=(const const_reverse_iterator &lhr, const const_reverse_iterator  &rhr)
                {
                    return lhr.iter != rhr.iter; 
                }

                Iterator base()
                {
                    return this->iter;
                }

        private:

    };













};