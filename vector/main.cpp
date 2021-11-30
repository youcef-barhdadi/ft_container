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
#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

# include <vector>
#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 3



time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}


int main(void)
{ 

    
        /*-------------------------------------- time limit test -----------------------------------*/
        
            time_t start, end, diff;
            // test 1: test with capacity greater than or equal the size + n (reallocation must'nt happen)
            /*------------------ std::vectors ---------------------*/
            // {
            //     std::vector<std::string> v(100, "hello");
            //     std::vector<std::string> v1(1e6, "string2");
            //     v1.reserve(1e6 + 200);
            //     start = get_time();
            //     v1.insert(v1.begin() + 1e5, v.begin(), v.end());
            //     end = get_time();
            //     diff = end - start;
            //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            //     /*------------------ ft::vectors ---------------------*/
            //     ft::Vector<std::string> ft_v(100, "hello");
            //     ft::Vector<std::string> ft_v1(1e6, "string2");
            //     ft_v1.reserve(1e6 + 200);
            //     ualarm(diff * 1e3, 0);
            //     ft_v1.insert(ft_v1.begin() + 1e5, ft_v.begin(), ft_v.end());
            //     ualarm(0, 0);
            // }
            /*--------------------------------------------------------------------------------------*/
            // test 2: test with capacity lesser than the size + n (reallocation must happen)
            /*------------------ std::vectors ---------------------*/
            {
                ft::Vector<std::string> v(1e5, "hello");
                std::vector<std::string> v1(1e6, "string2");
                start = get_time();
                v1.insert(v1.begin() + 1e5, v.begin(), v.end());
                end = get_time();
                diff = end - start;
                diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::Vector<std::string> ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, v.begin(), v.end());
                ualarm(0, 0);
            }
            /*--------------------------------------------------------------------------------------*/
        

    return (0);
    
}