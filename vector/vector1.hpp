/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:52:06 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/05 19:01:45 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <iterator>
#include "randomAccessIterator.hpp"

template<
    class T,
    class Allocator = std::allocator<T>
> class vector
{
        public:
            typedef T  value_type;
            //  typedef Allocator allocator_type  ;
             typedef size_t size_type  ;

             typedef      T& reference;
             
             typedef  const T& const_refernce ;

             typedef T *  pointer;
             
             typedef const  T *  pointer;




            size_type  size()
            {
                return this->_size;
            }
            size_type capacity()
            {
                return this->capacity;
            }

            bool empty()
            {
                if (this->size() == 0)
                    return  true;
                return false;
            } 

            vector(int size)
            {
                _vec = _myallocator.allocate(size);
                this->_capacity = size;
                this->_size = 0;
                
            }

            randomAccessIterator begin()
            {
                return iterator(_vec);
            }

            randomAccessIterator end()
            {
                return randomAccessIterator(_vec[this->size() - 1]);
            }
            


            T at(size_type n)
            {
                if (size > n)
                    throw ex;
                return this->_vec[n];
            }


            value_type *data()
            {
                return this->_vec;
            }

            const value_type  *date() const
            {
                return this->_vec;
            }


            reference fron()
            {
                return this->at(0);
            }

            reference  back()
            {
                return this->at(this->size() - 1);
            }


            reference operator[](size_type n)
            {
                return this->at(n);
            }
            



            void push_back(const value_type &val)
            {
               this->_push(this->size() - 1, val);
            }

            void pop_back()
            {
                this->_size --;
            }

            iterator insert (iterator position, const value_type& val)
            {
                // 
            }

            private :
                T *_vec;
                size_type  _size;
                size_type _capacity;
                Allocator<T> _myallocator;
                randomAccessIterator *iter;

                void _push(size_type n, const value_type &val)
                {
                        if (this->size() +1 > this->capacity())
                        {
                            // call allocate
                        }
                    this->_vec[n] = val;
                    this->size++;
                }

};