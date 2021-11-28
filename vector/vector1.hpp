/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:52:06 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/09 20:45:52 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <iterator>
#include "randomAccessIterator.hpp"


namespace ft{

template <class T>
struct is_sample_type : std::integral_constant <
    bool,
    (std::is_floating_point<T>::value || std::is_integral<T>::value)> {};
namespace ft {


    
template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };
}



template<
    class T,
    class Allocator = std::allocator<T>
> class vector
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
            
            typedef  randomAccessIterator<T> const_iterator;




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
            // vector(int size)
            // {
            //     _vec = _myallocator.allocate(size);
            //     this->_capacity = size;
            //     this->_size = 0;

            // }

            explicit vector (const allocator_type& alloc = allocator_type())
            {
                    this->_capacity = 0;
                    this->_size = 0;
            }

            explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
            {
                _vec = _myallocator.allocate(n);
                _end  = _vec;
                this->_capacity = n;
                this->_size = n;
                while (n--)
                {
                    *_end = val;
                    std::cout << val << std::endl;
                    _end++;
                }
                std::cout <<  "size ==>" << _end - _vec << std::endl;
            }

            template <class InputIterator  >
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),  typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
            {
                    size_type  n = last - first;
                    size_type i = 0;
                    this->_vec = _myallocator.allocate(n);
                    this->_capacity = n;
                    this->_size = n;
                    _end = _vec + n;
                    while (n--)
                    {
                        this->_vec[i] = *first;
                        i++;
                    }
            }


            vector (const vector& x)
            {
                    *this = x;
            }
    

            ///*end constructor */

            // overloading oprator 

            vector& operator= (const vector& x)
            {
                
                this->_size = x.size();
                this->_capacity = x.capacity();
                const_iterator first = x.const_begin();
                std::cout << *first << std::endl;
                const_iterator last = x.const_end();
                size_type n = last - first;
                this->_size = n;
                this->_capacity = n;
                this->_vec = _myallocator.allocate(n);
                while (n--)
                {
                    *_vec = *first;
                    first++;  
                }
                return *this;
                
            }



            void resize( size_type count, T value = T() )
            {
                T *vec = _myallocator.allocate(count);
                for (size_type i =0; i < this->size() ; i++ )
                {
                    vec[i] = this->_vec[i];
                }
                for (size_t i =  this->size() ; i < count; i++)
                {
                    vec[i] = value;
                }
                if (this->capacity() != 0)
                    _myallocator.deallocate(this->_vec, this->_capacity);
                this->_capacity = count;
                this->_vec = vec;
                this->_end  = this->_vec + count;
            }

            
            void    reserve(size_type n)
            {
                if (n >  this->capacity())
                {
                        T *vec = _myallocator.allocate(n);
                        for (size_type i = 0; i < this->size() ; i++)
                        {
                            vec[i] = this->_vec[i];
                        }
                        for (size_t i =  this->size() ; i < n; i++)
                        {
                            vec[i] = T();
                        }
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
                size_type i  = 0;
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
                if (this->size() + n >= this->capacity())
                {
                    this->reserve(this->capacity() * 2 + n);
                }
                size_t pos = (position - this->begin());

                for (size_t i =  this->size() + n,  j = this->size(); i > pos; j--, i--)
                {
                        this->_vec[i] = this->_vec[j];
                }
                for (int i = 0; i < n; i++)
                {
                        this->_vec[pos] = val;
                        pos++;
                }
                this->_size += n;
                 this->_end = this->_vec + this->size();

              }
            iterator begin()
            {
                return iterator(this->_vec);
            }

            const_iterator const_begin() const
            {
                return iterator(this->_vec);
            }

           iterator end()
            {
                return iterator(_end);
            }
            
            const_iterator const_end() const
            {
                return iterator(_end);
            }


            T at(size_type n)
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
                return this->_vec[n];
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
                T old;
                T old1;
                

                if (this->_capacity == 0)
                {
                    reserve(4);
                    _myallocator.construct(this->_vec, val);
                    this->_size++;
                    this->_end = this->_vec + this->size();
                    return begin();
                }


                if (this->size() == this->capacity())
                {
                    reserve(this->_size * 2);
                }
                int pos = &(*position) -this->_vec;
                // std::cout <<  "value is [" << val << " " <<  pos << std::endl;
                // old = this->_vec[pos];
                // this->_vec[pos] = val;
                size_type  i =  this->size();
                old = this->_vec[pos];
                while (i != pos)
                { 
                    this->_vec[i] = this->_vec[i - 1];
                    i--;
                }
                this->_vec[pos] = val;

                this->_size++;
                this->_end = this->_vec + this->size();
                return position; 
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
                        this->_vec[i] = this->_vec[j];
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
                for(int i = 0; i < this->size() ; i++)
                {
                    std::cout << this->_vec[i] << std::endl;
                }
                std::cout << "/=============/" << std::endl;

            }



            void    clear()
            {
                 _myallocator.deallocate(this->_vec, this->_capacity);
                 this->_capacity = 0;
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

            iterator erase (iterator first, iterator last)
            {
                if (this->size() == 0)
                    return first;
                size_type len = &(*last) - &(*first);

                size_type pos = &(*first) - this->_vec; 

                for(size_type  i = pos ; i < this->size() ; i++)
                {
                    this->_vec[i] = this->_vec[pos+len + i];
                }
                this->_size -=  len;
                this->_end = this->_vec + len;

            }



            private :
                T *_vec;
                T *_end;
                size_type  _size;
                size_type _capacity;
                allocator_type _myallocator;
                randomAccessIterator<T> *iter;

                void _push(size_type n, const value_type &val)
                {
                        reserve(this->size() + 1);
                        if (n == this->size())
                        {
                            this->_vec[n] = val;
                            this->_size++;
                            return ;
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
};