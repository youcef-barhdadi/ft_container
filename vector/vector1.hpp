/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:52:06 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/05 18:37:49 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <iterator>

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

            iterator begin()
            {
                return iterator(_vec);
            }

            private :
                T *_vec;
                size_type  _size;
                size_type _capacity;
                Allocator<T> _myallocator;
                iterator *iter;

};