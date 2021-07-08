/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:18:30 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/07/08 15:21:33 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



template< class T >
class iterator_traits
{
private:
    /* data */
public:

    using difference_type  = std::ptrdiff_t;
    using  T value_type;
    using T* pointer;
    using reference T&;
    

    iterator_traits(/* args */);
    ~iterator_traits();




    
};

iterator_traits::iterator_traits(/* args */)
{
}

iterator_traits::~iterator_traits()
{
}
