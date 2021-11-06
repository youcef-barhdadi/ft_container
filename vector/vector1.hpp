/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:52:06 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/06 21:02:39 by ybarhdad         ###   ########.fr       */
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
             
             typedef const  T *  const_pointer;
            typedef Allocator Allocator_type;

            typedef  randomAccessIterator<T> iterator;



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

           iterator end()
            {
                return iterator(&_vec[this->size() - 1]);
            }
            


            T at(size_type n)
            {
                if (this->size() > n)
                    throw "ex";
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
               this->_push(this->size() , val);
            }

            void pop_back()
            {
                this->_size --;
            }

            randomAccessIterator<T> insert (randomAccessIterator<T> position, const value_type& val)
            {
                // 
            }




            void    print_all()
            {
                std::cout << "=============" << std::endl;
                for(int i = 0; i < this->size() ; i++)
                {
                    std::cout << this->_vec[i] << std::endl;
                }
                std::cout << "/=============/" << std::endl;

            }

            private :
                T *_vec;
                size_type  _size;
                size_type _capacity;
                Allocator_type _myallocator;
                randomAccessIterator<T> *iter;

                void _push(size_type n, const value_type &val)
                {

                        if (n == this->size())
                        {
                            this->_vec[n] = val;
                            this->_size++;
                            return ;
                        }

                        if (this->size() +1 > this->_capacity)
                        {
                            // call allocate
                        }
                        
                        for (size_type i = n; i < this->size() ; i++)
                        {
                            value_type t = this->_vec[i + 1];
                            this->_vec[i +1] = this->_vec[i];
                            this->_vec [i + 1] = t;
                            
                        }
                        this->_vec[n] = val;
                        this->_size++;
                }

};