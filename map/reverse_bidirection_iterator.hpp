#pragma once
#include <iostream>
#include <memory>
#include <iterator>
#include "bidirectional_iterator.hpp"


namespace ft {
	template <class Iterator> 
    class reverse_bidirection_iterator {
        public: 
                typedef Iterator	iterator_type;

                typedef typename   Iterator::reference  reference;
                typedef typename   Iterator::pointer  pointer;

                Iterator iter;


                reverse_bidirection_iterator()
                {

                }
                reverse_bidirection_iterator(const Iterator iter)
                {
                    this->iter = iter;
                }
                    
                reference operator*() 
                {
                    return  (*iter);
                }

                pointer operator->()
                {
                    return &(iter);
                }
                        
                reverse_bidirection_iterator operator++(void)
                {
                    ++iter;
                    return *this;
                }


                reverse_bidirection_iterator operator++(int)
                {
                    reverse_bidirection_iterator copy(iter);
                    operator++();
                    return copy;
                }



                reverse_bidirection_iterator operator--(void)
                {   
                    --iter;
                    return *this;
                }

                
                reverse_bidirection_iterator operator--(int)
                {
                    reverse_bidirection_iterator copy(iter);
                    operator--();
                    return copy;
                }




        private:

    };
};