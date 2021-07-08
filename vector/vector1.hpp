/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:52:06 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/07/08 15:08:50 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

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

            class Iterator
            {
                using value_type = T;
                using difference_type = std::ptrdiff_t;
                using pointer = T*;
                using reference  = T&;
                using iterator_category = std::random_access_iterator_tag;
            };

};