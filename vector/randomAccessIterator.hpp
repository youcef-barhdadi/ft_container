/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:32:15 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/06 21:00:00 by ybarhdad         ###   ########.fr       */
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

    T& operator* ()
    {
        return *_ptr;
    }


    
        
    private:
        T *_ptr;
};