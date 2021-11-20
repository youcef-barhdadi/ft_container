/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:32:15 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/09 20:48:05 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <memory>
#include <iterator>

template <class T>
class randomAccessIterator  : public std::iterator<std::random_access_iterator_tag, T>
{
    public :
        typedef   T    value_type ;
        typedef  std::ptrdiff_t  difference_type ;
        typedef T*  pointer ;
        typedef  T&  reference ;
        // typedef std::iterator_category std::random_access_iterator_tag;



    randomAccessIterator()
    {
    
    }
    difference_type operator-(const randomAccessIterator& rhs) const
    {
        return   (this->_ptr-  rhs._ptr);
    }

    
    randomAccessIterator(T* ptr)
    {
        this->_ptr = ptr;
    }

    // randomAccessIterator(randomAccessIterator &iter)
    // {
    //     this->_ptr = *this;
    // }

    


    T& operator* ()
    {
        return *_ptr;
    }


    randomAccessIterator operator++()
    {
        T old(*this);
        ++*this;
        return old;   
    }

    randomAccessIterator operator=(randomAccessIterator &r)
    {
        r._ptr = this->_ptr;
        return r;    
    }
    
    

    randomAccessIterator &operator++(int)
    {
        // *this++;
        return  *this;
    }

  friend  bool operator==(randomAccessIterator &a  , randomAccessIterator &b)
    {
    if (a._ptr  == b._ptr)
            return true;
        return false;
    }
    bool operator!=(randomAccessIterator &a)
    {
        if (*this == *a)
            return false;
        return true;
    }

    pointer operator->() { return _ptr; }



    randomAccessIterator operator + ( size_t n)
    {
        
        return this->_ptr + n;
    }
    
    // randomAccessIterator operator - (int c)
    // {
    //     randomAccessIterator res(this->_ptr + c);
    // }
        
    //    friend  std::ptrdiff_t operator-(randomAccessIterator<T>  left, randomAccessIterator<T>  right);
    
                   T *_ptr;

    private:
};

//  std::ptrdiff_t randomAccessIterator<T>::operator-(randomAccessIterator<T>  left, randomAccessIterator<T>  right) {
//     return left - right  ;
// } 
