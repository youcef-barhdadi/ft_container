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

#pragma once
#include <iostream>
#include <memory>
#include <iterator>

namespace ft {







template <class T>
class randomAccessIterator  : public std::iterator<std::random_access_iterator_tag, T>
{
    public :
        typedef   T    value_type ;
        typedef  std::ptrdiff_t  difference_type ;
        typedef T*  pointer ;
        typedef  T&  referenc ;

    randomAccessIterator(void)
    {
        this->_ptr  = nullptr;
    }

    randomAccessIterator(pointer ptr)
    {
        this->_ptr = ptr;
    }

    operator randomAccessIterator<const T> ()
    {
        return randomAccessIterator<const T>(this->base());
    }

    operator randomAccessIterator< const T> () const
    {
        return randomAccessIterator<const T>(this->base());
    }

    randomAccessIterator(const randomAccessIterator& op) 
    {
              _ptr = op.base();
    }

    difference_type operator-(const randomAccessIterator& rhs) const
    {
        return   (this->_ptr-  rhs._ptr);
    }

    pointer base() const
    {
        return  this->_ptr;
    }

    reference operator*  (void) const
    {
        return *_ptr;
    }


    randomAccessIterator& operator++(void)
    {
        this->_ptr++;
        return (*this);
    }

    pointer operator->(void) 
    {
        return &(this->operator*());
    }

     randomAccessIterator &operator=( const  randomAccessIterator     &r)
    {
        if (*this == r)
            return (*this);
        this->_ptr = r.base();
        return (*this);    
    }

    virtual  ~randomAccessIterator() {}
    
    randomAccessIterator operator++(int)
    {
        randomAccessIterator rtn(*this);
        operator++();
        return  (rtn);
    }

    randomAccessIterator & operator--(void)
    {
        this->_ptr--;
        return (*this);
    }

    randomAccessIterator  operator--(int)
    {
        randomAccessIterator  rtn(*this);
        operator--();
        return (rtn);
    }

    randomAccessIterator operator+(difference_type n)  
    {
        randomAccessIterator c;
        c._ptr =  this->_ptr + n ;
        return (c);
    }

    randomAccessIterator operator-(difference_type n)  
    {
        randomAccessIterator c;
        c._ptr =  this->_ptr - n ;
        return (c);
    }

    randomAccessIterator &operator+=(difference_type n)
    {
        this->_ptr +=n;
        return (*this);
    }

    randomAccessIterator& operator-=(difference_type n)
    {
        this->_ptr -= n;
        return (*this);
    }

    reference operator[](difference_type n)
    {
        this->_ptr += n;
        return  (*(this->_ptr));
    }

    friend difference_type operator ==(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template<typename T_L, typename T_R>
    friend difference_type operator==(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    friend   randomAccessIterator operator+( difference_type n, randomAccessIterator& rai) 
    {   
        return  randomAccessIterator(rai.base() + n);
    }

    friend   randomAccessIterator operator-( difference_type n, randomAccessIterator& rai) 
    {   
        return  randomAccessIterator((rai.base() - n));
    }


    
                   T *_ptr;

    private:
};

//  std::ptrdiff_t randomAccessIterator<T>::operator-(randomAccessIterator<T>  left, randomAccessIterator<T>  right) {
//     return left - right  ;
// } 



 



// template <typename T>
// typename randomAccessIterator<T>::difference_type operator ==(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
// {
//     return (lhs.base() == rhs.base());
// }


// template<typename T_L, typename T_R>
// typename randomAccessIterator<T_L>::difference_type operator==(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
// {
//     return (lhs.base() == rhs.base());
// }


template <typename T>
typename randomAccessIterator<T>::difference_type operator !=(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
{
    return (lhs.base() != rhs.base());
}


template<typename T_L, typename T_R>
typename randomAccessIterator<T_L>::difference_type operator!=(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
{
    return (lhs.base() != rhs.base());
}

template <typename T>
typename randomAccessIterator<T>::difference_type operator <(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
{
    return (lhs.base() < rhs.base());
}

template<typename T_L, typename T_R>
typename randomAccessIterator<T_L>::difference_type operator <(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
{
    return (lhs.base() < rhs.base());
}

template <typename T>
typename randomAccessIterator<T>::difference_type operator <=(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
{
    return (lhs.base() <= rhs.base());
}

template<typename T_L, typename T_R>
typename randomAccessIterator<T_L>::difference_type operator <=(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
{
    return (lhs.base() <= rhs.base());
}



template <typename T>
typename randomAccessIterator<T>::difference_type operator >(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
{
    return (lhs.base() > rhs.base());
}

template<typename T_L, typename T_R>
typename randomAccessIterator<T_L>::difference_type operator >(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
{
    return (lhs.base() > rhs.base());
}

template <typename T>
typename randomAccessIterator<T>::difference_type operator >=(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
{
    return (lhs.base() >= rhs.base());
}

template<typename T_L, typename T_R>
typename randomAccessIterator<T_L>::difference_type operator >=(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
{
    return (lhs.base() >= rhs.base());
}








};