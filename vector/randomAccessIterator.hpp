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

namespace ft {
template <class T>
class randomAccessIterator  : public std::iterator<std::random_access_iterator_tag, T>
{
    public :
        typedef   T    value_type ;
        typedef  std::ptrdiff_t  difference_type ;
        typedef T*  pointer ;
        typedef  T&  reference ;
        // typedef std::iterator_category std::random_access_iterator_tag;



    randomAccessIterator(void)
    {
            this->_ptr  = nullptr;
    }

    randomAccessIterator(pointer ptr)
    {
        this->_ptr = ptr;
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

    randomAccessIterator &operator=(randomAccessIterator &r)
    {
        if (this == r)
            return (*this);
        r._ptr = this->base();
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

    randomAccessIterator & operator--(int)
    {
        randomAccessIterator  rtn(*this);
        operator--();
        return (rtn);
    }

    randomAccessIterator operator+(difference_type n) const
    {
        this->_ptr =+ n;
        return (*this);
    }

    randomAccessIterator operator-(difference_type n) const
    {
        
        this->_ptr =-n;
        return (*this);
    }

    randomAccessIterator& operator+=(difference_type n)
    {
        this->_ptr +=  n;
        return (*this);
    }

    randomAccessIterator& operator-=(difference_type n)
    {
        this->_ptr -= n;

        return (*this);
    }

    reference operator[](difference_type n)
    {
        return  (*(operator+(n)));
    }

    // bool operator==(randomAccessIterator &a)
    // {
    // if (this->_ptr  == a._ptr)
    //         return true;
    //     return false;
    // }
    // bool operator!=(randomAccessIterator &a)
    // {
    //     if (*this == *a)
    //         return false;
    //     return true;
    // }




    // pointer operator->() { return _ptr; }

    // randomAccessIterator operator-(difference_type n) const { return (_ptr - n); }

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



 



template <typename T>
typename randomAccessIterator<T>::difference_type operator ==(const randomAccessIterator<T> lhs, const randomAccessIterator<T> rhs)
{
    return (lhs.base() == rhs.base());
}


template<typename T_L, typename T_R>
typename randomAccessIterator<T_L>::difference_type operator==(const randomAccessIterator<T_L> lhs,  const randomAccessIterator<T_R> rhs)
{
    return (lhs.base() == rhs.base());
}


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