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
# include "vector1.hpp"

// # include <vector>
// using namespace std;

int main(int argc, char **argv)
{

        (void) argc;
        (void) argv;
        ft::vector<int>  vec;


        vec.insert(vec.begin(), 1337);


        vec.push_back(42);
        vec.push_back(42);
        vec.push_back(42);
        vec.push_back(42);

        std::cout <<  "size" << vec.size()   << " => max size:" << vec.max_size()  << std::endl ;
        std::cout <<  "capacity" << vec.capacity() << std::endl ;
        vec.pop_back();
        vec.pop_back();
        vec.print_all();



    return (0);

}