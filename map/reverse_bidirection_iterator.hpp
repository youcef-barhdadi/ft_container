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
                    // std::cout << "iter" << iter < std::endl;
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


                                
                reverse_iterator& operator=(reverse_iterator  &s)
                {
                    this->iter = s.iter;
                    return  (*this);
                }

                // void    operator=(const Iterator &s)
                // {
                //     this->iter = s;
                //     return  (*this);
                // }

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

                operator  const reverse_iterator<const Iterator>()
                {
                    return reverse_iterator<const Iterator>(this->base());
                }

          

    


        private:

    };
};