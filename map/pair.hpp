/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:17:45 by ybarhdad          #+#    #+#             */
/*   Updated: 2022/03/08 21:17:45 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>


namespace ft{

	template <class T1, class T2>
    struct pair {
		public:


			typedef T1	first_type;
			typedef T2	second_type;



			first_type	first;
			second_type second;


			pair()  : first() , second()
			{ 
					
				return ;
			}

			template <class U, class V>
			pair(const pair<U, V>& pr): first(pr.first), second(pr.second) {
				return ;
			}


			pair (const first_type& a, const second_type& b): first(a), second(b)
            {
				return ;
			}

			pair&	operator= (const pair& pr)
            {
                if (this == &pr)
                    return (*this);
				this->first = pr.first;
				this->second = pr.second;
				return (*this);
			}

			operator ft::pair<const first_type, second_type>()
			{
				return ft::pair<const first_type, second_type>(first, second);
			}

			// operator const ft::pair<const first_type, second_type>() const
			//  {
			// 	 return ft::pair<const first_type, second_type>(first, second); 
			//  }

	};


	 
	 template <class T1, class T2>
	 ft::pair<T1, T2>	make_pair (T1 x, T2 y) {
		 return (ft::pair<T1,T2>(x,y));
	 }
    template<typename T1, typename T2>
    bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
    template<typename T1, typename T2>
    bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return !(lhs == rhs); }
    template<typename T1, typename T2>
    bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (lhs.first < rhs.first || lhs.second < rhs.second); }
    template<typename T1, typename T2>
    bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return rhs < lhs; }
    template<typename T1, typename T2>
    bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (lhs == rhs || lhs < rhs); }
    template<typename T1, typename T2>
    bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (lhs == rhs || rhs < lhs); }
}