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

// using namespace std;

int main(int argc, char **argv)
{
        // int cc  = ÷1337;
    vector<int> c(5);
    c.push_back(1337);
    c.push_back(1337);
    c.push_back(42);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    c.push_back(53);
    // c.pop_back();

    vector<int>::iterator cc = c.begin();
    c.insert(cc, 1337);
    c.print_all();

    
    

  

    return (0);

}