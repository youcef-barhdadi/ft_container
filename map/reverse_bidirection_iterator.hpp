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
                reverse_bidirection_iterator(const Iterator  & iter)
                {
                    // std::cout << "iter" << iter < std::endl;
                    this->iter = iter;
                }
                    
                reference operator*() 
                {
                    iterator_type  pre = iter;
                    pre--;
                    return  (*pre);
                }

                pointer operator->()
                {
                    iterator_type  pre(iter);
                    pre--;
                    return  &(*pre);
                }
                        
                reverse_bidirection_iterator operator++(void)
                {
                    --iter;
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
                    ++iter;
                    return *this;
                }

                
                reverse_bidirection_iterator operator--(int)
                {
                    reverse_bidirection_iterator copy(iter);
                    operator--();
                    return copy;
                }

                friend  bool  operator==( reverse_bidirection_iterator &lhr,  reverse_bidirection_iterator  &rhr)
                {
                    return lhr.iter == rhr.iter; 
                }


                friend  bool  operator!=(const reverse_bidirection_iterator &lhr, const reverse_bidirection_iterator  &rhr)
                {
                    return lhr.iter != rhr.iter; 
                }


        private:

    };
};