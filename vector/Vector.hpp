/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:52:06 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/09 20:45:52 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <iostream>
#include <memory>
#include <iterator>
#include "randomAccessIterator.hpp"
#include  "reverse_iterator.hpp"





namespace ft {
template <class T>
struct is_sample_type : std::integral_constant <
    bool,
    (std::is_floating_point<T>::value || std::is_integral<T>::value)> {};

    
template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };




template<
    class T,
    class Allocator = std::allocator<T>
> class Vector
{
        public:
            typedef T  value_type;
             typedef   Allocator   allocator_type ;
             typedef size_t size_type  ;

             typedef      T& reference;
             
             typedef  const T& const_refernce ;

             typedef T *  pointer;
             
             typedef const  T *  const_pointer;
            // typedef Allocator_type Allocator ;

            typedef  randomAccessIterator<T> iterator;
            
            typedef  randomAccessIterator<const T> const_iterator;

            
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<randomAccessIterator<const T> > const_reverse_iterator;



            size_type  size() const
            {
                return this->_size;
            }

            

            size_type capacity() const
            {
                return this->_capacity;
            }

            bool empty() const
            {
                if (this->size() == 0)
                    return  true;
                return false;
            } 
            ///* constrcutr  */

            explicit Vector (const allocator_type& alloc = allocator_type())
            {
                        (void) alloc;
                    this->_capacity = 0;
                    this->_size = 0;
            }

            explicit Vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
            {
                (void) alloc;
                std::cout << "==>" <<  n << std::endl;
                _vec = _myallocator.allocate(n);
                this->_capacity = n;
                this->_size = n;
                size_type i = 0;
                while (i < n)
                {
                  
                    _myallocator.construct(_vec+ i, val);

                    i++;
                }
                this->_end = this->_vec + n;
            }

            template <class InputIterator  >
            Vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),  typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
            {
                (void) alloc;
                    size_type  n = last - first;
                    size_type i = 0;
                    this->_vec = _myallocator.allocate(n);
                    this->_capacity = n;
                    this->_size = n;
                    _end = _vec + n;
                    while (i < n)
                    {
                        this->_vec[i] = *first;
                        i++;
                    }
            }


            Vector (const Vector& x)
            {
                    // *this = x;
                    this->_vec = _myallocator.allocate(x.capacity());

                    for(size_type i = 0; i < x.size() ; i++)
                    {
                        // this->_vec[i] = x.at(i);
                                            _myallocator.construct(_vec+ i, x.at(i));

                    }
                    this->_size =  x.size();
                    this->_end = this->_vec + this->size();
                    this->_capacity  = x.capacity();
            }
    

            ///*end constructor */

            // overloading oprator 

            Vector& operator= (const Vector& x)
            {
                
                std::cout <<  "==>>" << x.size() << std::endl;

                _myallocator.deallocate(this->_vec, x.capacity());
                this->_size = x.size();
                this->_capacity = x.capacity();
                this->_vec = _myallocator.allocate(this->_capacity);
                size_t i = 0;
                while (i < x.size())
                {
                    _myallocator.construct(_vec + i, x.at(i));
                    i++;
                }
                // std::cout << 
                this->_end = this->_vec +  this->size();
                return *this;
            }



            void resize( size_type count, T value = T() )
            {
                reserve(count);
                if (this->size() > count)
                {
                    for (size_type i = count ; (i < this->size()) ; i++ )
                    {
                        _myallocator.destroy((_vec + i));
                    }
                    this->_size = count;
                }
                else {
                    std::cout <<  "[" << value << "]" << std::endl;
                    for (size_type i = this->size();  i < count; i++)
                    {
                        _myallocator.construct(_vec + i,  value);
                    }
                    this->_size = count;
                }
                // this->_size =  count;
                // this->_capacity = count;
                // this->_vec = vec;
                this->_end  = this->_vec + this->size();
            }

            
            void    reserve(size_type n)
            {
                if (n >  this->capacity())
                {
                        T *vec = _myallocator.allocate(n);
                        for (size_type i = 0; i < this->size() ; i++)
                        {
                            _myallocator.construct(vec + i,  this->_vec[i]);

                        }
                        // for (size_t i =  this->size() ; i < n; i++)
                        // {
                        //      _myallocator.construct(vec + i,  T());
                        // }
                        if (this->capacity() != 0)
                            _myallocator.deallocate(this->_vec, this->_capacity);
                        this->_capacity = n;
                        this->_vec = vec;
                        this->_end  = this->_vec + this->size();
                }
            }


            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {
                size_type  n= &(*last) - &(first);
                // size_type i  = 0;
                clear();
                reserve(n);
                this->insert(this->begin(), first, last);
            }

            void assign (size_type n, const value_type& val)
            {
                this->clear();
                resize(n , val);
            }
              void insert (iterator position, size_type n, const value_type& val)
              {
                 size_t pos ;
                 
                if (this->size() == 0)
                    pos  = 0;
                else 
                    pos = pos = (&(*position) - this->_vec);

                if (this->size() + n >= this->capacity())
                {
                    if (this->capacity()  == 0)
                        this->reserve((this->capacity()  + 1) * n );
                    else
                            this->reserve(this->capacity() * 2 < n ? this->capacity() + n :  this->capacity() * 2);
                }
                std::cout << "====>++++++++" << pos  << " " << this->size() << "  ca "  << this->capacity()  << "bbb n" << n << std::endl;
                if (this->size() != 0)
                    for (size_t i =  this->size() + n,  j = this->size(); i > pos ; j--, i--)
                    {
                        _myallocator.construct(_vec  + i,  this->_vec[j]);
                    }
                for (size_t i = 0; i < n; i++)
                {
                        // this->_vec[pos] = val;
                    _myallocator.construct(_vec  + pos,  val);

                        pos++;
                }
                this->_size += n;
                 this->_end = this->_vec + this->size();

              }
            iterator begin() 
            {
                return randomAccessIterator<T>(this->_vec);
            }

            const_iterator begin()  const
            {
                return randomAccessIterator<const T>(this->_vec);
            }

           iterator end()
            {
                return iterator(_end);
            }
            
            const_iterator end() const
            {
                return randomAccessIterator<const T>(_end );
            }


            reverse_iterator rbegin() 
            {
                return reverse_iterator(iterator(this->_end - 1));
            }

            reverse_iterator rend()
            {
                return reverse_iterator (iterator (this->_vec - 1));
            }

            const_reverse_iterator rbegin()  const
            {
                return const_reverse_iterator(const_iterator (this->_end - 1));
            }

            const_reverse_iterator rend() const
            {
                return  const_reverse_iterator (const_iterator(this->_vec - 1));
            }




            reference at(size_type n)
            {
                if (n > this->size() )
                    throw std::out_of_range("");
                return this->_vec[n];
            }

            reference at(size_type n) const
            {
                if (n > this->size() )
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


            reference front()
            {
                return this->at(0);
            }

                        reference front() const
            {
                return this->at(0);
            }

            reference  back()
            {
                return this->at(this->size() - 1);
            }


                  reference  back() const
            {
                return this->at(this->size() - 1);
            }


            reference operator[](size_type n)
            {
                if (n > this->size())
                 throw std::out_of_range("");
                return this->_vec[n];
            }


            reference operator[](size_type n) const
            {
                if (n > this->size())
                     throw std::out_of_range("");
                return this->_vec[n];
            }
            
            void push_back(const value_type &val)
            {
               this->insert(this->end()  , val);
            }

            void pop_back()
            {
                this->_size --;
            }

            randomAccessIterator<T> insert (randomAccessIterator<T> position, const value_type& val)
            {

                 size_type pos = position  -this->begin();
                if (this->_capacity == 0)
                {
                    reserve(1);
                    _myallocator.construct(this->_vec, val);
                    this->_size++;
                    this->_end = this->_vec + this->size();
                    return begin();
                }
                if (this->size() == this->capacity())
                {
                    reserve(this->_size * 2);
                    
                }
                size_type  i =  this->size();

                while (i != pos)
                { 
                     _myallocator.construct(_vec  + i,  this->_vec[i - 1]);
                    i--;
                }
             _myallocator.construct(_vec  + pos,  val);
                this->_size++;
                this->_end = this->_vec + this->size();
                return iterator(_vec + pos); 
            }


            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, 	typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
            {
                size_type  size = &(*last)-&(*first);
                if (this->_size + size > this->_capacity)
                {
                    reserve(this->_capacity *2 + size);
                }
                size_t pos = (position - this->begin());
                for (size_t i =  this->size() + size,  j = this->size(); i > pos; j--, i--)
                {
                        // this->_vec[i] = this->_vec[j];
                 _myallocator.construct(_vec  + i,  this->_vec[j]);

                }
                while (size--)
                {
                    insert(position, *first);
                    ++first;
                    ++position;
                }

            }



            void    print_all()
            {
                std::cout << "=============" << std::endl;
                for(size_type i = 0; i < this->size() ; i++)
                {
                    std::cout << this->_vec[i] << std::endl;
                }
                std::cout << "/=============/" << std::endl;

            }



            void    clear()
            {

                 for(size_type  i = 0; i <this->size() ; i++)
                 {
                     _myallocator.destroy((_vec + i));

                 }
                 this->_size = 0;
            }

            size_type max_size() const 
            {
                // need implemntaion
                return _myallocator.max_size();
            }

            allocator_type get_allocator()
            {
                return _myallocator;
            }



            iterator erase(iterator position)
            {
                size_type pos = &(*position) - this->_vec;
                for(size_type i=  pos ; i < this->size() ; i++)
                {
                    this->_vec[i] = this->_vec[i+1];
                }
                this->_size--;
                this->_end = this->_vec + this->_size;
                return (position);
            }


            void swap (Vector& x)
            {
                if (this == &x)
                    return ;

                size_type size1 = x.size();
                size_type capacity = x.capacity();
                pointer ptr = x.data();
                pointer ptrend = x._end;


                x._vec = this->_vec;
                x._size = this->_size;
                x._capacity = this->_capacity;
                x._end = this->_end;


                this->_size  = size1;
                this->_capacity = capacity;
                this->_vec = ptr;
                this->_end = ptrend;
            }


            iterator erase (iterator first, iterator last)
            {
                if (this->size() == 0)
                    return first;
                size_type len = &(*last) - &(*first);

                size_type pos = &(*first) - this->_vec; 
                std::cout << "to delete "  << len   <<  " pod "  << pos   <<  "size "  << _size<< std::endl;

                for(size_type  i = pos +len ; i < this->size() ; i++)
                {
                    this->_vec[i] = this->_vec[pos+len + i];
                }
                this->_size -=  len;
                this->_end = this->_vec + len;
                return first;
            }


















            

      T *_vec;
                T *_end;size_type  _size;
                size_type _capacity;
            private :
          
                // size_type  _size;
                // size_type _capacity;
                allocator_type _myallocator;
                randomAccessIterator<T> *iter;

                // void _push(size_type n, const value_type &val)
                // {
                //         reserve(this->size() + 1);
                //         if (n == this->size())
                //         {
                //             this->_vec[n] = val;
                //             this->_size++;
                //             return ;
                //         }
                //         for (size_type i = n; i < this->size() ; i++)
                //         {
                //             value_type t = this->_vec[i + 1];
                //             this->_vec[i +1] = this->_vec[i];
                //             this->_vec [i + 1] = t;
                            
                //         }
                //         this->_vec[n] = val;
                //         this->_size++;
                // }
};
};