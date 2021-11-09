/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:32:15 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/09 17:33:57 by ybarhdad         ###   ########.fr       */
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


    randomAccessIterator(T* ptr)
    {
        this->_ptr = ptr;
    }

    randomAccessIterator(randomAccessIterator &iter)
    {
        this->_ptr = *this;
    }

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
    

    randomAccessIterator &operator++(int)
    {
        *this++;
        return  *this;
    }

    bool operator==(randomAccessIterator &r)
    {
        if (*this == *r)
            return true;
        return false;
    }
    bool operator!=(randomAccessIterator &r)
    {
        if (*this == *r)
            return false;
        return true;
    }
    
           
    private:
        T *_ptr;
};