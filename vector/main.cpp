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
        // int cc  = ÷1337;
  


    
vector<int> first;                                // empty vector of ints
vector<int> second (4,100);                       // four ints with value 100
// std::cout <<
 vector<int> third (second.begin(),second.end());  // iterating through secon

second.insert(second.begin(), 44);
// vector<int> fourth (third);                       // a copy of third
// std::cout << fourth.size() << std::endl;

    std::cout << second.at(0) << std::endl;

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
// vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//  cout << "The contents of fifth are:";
//   for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     cout << ' ' << *it;
//   std::cout << '\n';

    // std::vector<int> v(4,5);

    // int  c= v.end() - v.begin();

    // std::cout << c << std::endl;


  

    return (0);

}