/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:26:02 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/11/09 19:20:25 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>
# include <stack>
# include "Vector.hpp"

# include <vector>
// using namespace std;

int main(int argc, char **argv)
{

         ft::Vector<int> v(4, 5);
        ft::Vector<int>::reverse_iterator my_rit2(v.end());
        ft::Vector<int>::const_reverse_iterator c_it, c_ob(v.end());
        c_it = my_rit2;



    return (0);

}