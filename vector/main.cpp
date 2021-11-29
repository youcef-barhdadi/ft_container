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



int main(int argc, char **argv)
{  
              time_t start, end, diff;

                   
  {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*
             * test with n greater than vector capacity
             */
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string> v1(10, "string2");
            start = get_time();
            v1.resize(1e6);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string> ft_v1(10, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.resize(1e6);
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*
             *	test with n lesser than capacity and greater than size
             */
            /*------------------ std::vectors ---------------------*/
            v1.resize(20);
            start = get_time();
            v1.resize(1e5);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft_v1.resize(20);
            ualarm(diff * 1e3, 0);
            ft_v1.resize(1e5);
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*
             * test with n lesser than capacity and lesser an size
             */
            /*------------------ std::vectors ---------------------*/
            v1.resize(100);
            start = get_time();
            v1.resize(50);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft_v1.resize(100);
            ualarm(diff * 1e3, 0);
            ft_v1.resize(50);
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*
        //  * Strings to store the results
        //  */
        std::string s1, s2, s3, s4, ft_s1, ft_s2, ft_s3, ft_s4;
        std::string sit1, sit2, sit3, ft_sit1, ft_sit2, ft_sit3; // strings to store the result by iterators
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, z4, ft_z1, ft_z2, ft_z3, ft_z4;
        size_t c1, c2, c3, c4, ft_c1, ft_c2, ft_c3, ft_c4;
        /*
         * iterators to check the iterator validity
         *  it : iterator, eit : iterator to the end
         */
        // std::vector<std::string>::iterator valid_it, valid_eit;
        ft::Vector<std::string>::iterator ft_valid_it, ft_valid_eit;
        /*
         * test with n greater than vector capacity
         */
        /*------------------ std::vectors ---------------------*/
        // std::vector<std::string> v1(10, "string2");
        // v1.resize(1e6, "hello");
        // /*------------------ ft::vectors ---------------------*/
        // ft::Vector<std::string> ft_v1(10, "string2");
        // ft_v1.resize(1e6, "hello");

        // z1 = v1.size();
        // ft_z1 = ft_v1.size();
        // c1 = v1.capacity();
        // ft_c1 = ft_v1.capacity();
        // for (size_t i = 0; i < v1.size(); ++i)
        //     s1 += v1[i];

        // for (ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        //     ft_s1 += *it;
        // /*----------------------------------------------------*/
        // /*
        //  *	test with n lesser than capacity and greater than size
        //  */
        // /*------------------ std::vectors ---------------------*/
        // v1.resize(20);
        // valid_it = v1.begin();
        // valid_eit = v1.end();
        // v1.resize(1e5);
        // /*------------------ ft::vectors ---------------------*/
        // ft_v1.resize(20);
        // ft_valid_it = ft_v1.begin();
        // ft_valid_eit = ft_v1.end();
        // ft_v1.resize(1e5);

        // z2 = v1.size();
        // ft_z2 = ft_v1.size();
        // c2 = v1.capacity();
        // ft_c2 = ft_v1.capacity();
        // for (size_t i = 0; i < v1.size(); ++i)
        //     s2 += v1[i];

        // for (; valid_it != valid_eit; ++valid_it)
        //     sit1 += *valid_it;

        // for (ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        //     ft_s2 += *it;

        // for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
        //     ft_sit1 += *ft_valid_it;
        // /*----------------------------------------------------*/
        // /*
        //  * test with n lesser than capacity and lesser an size
        //  */
        // /*------------------ std::vectors ---------------------*/
        // valid_it = v1.begin();
        // v1.resize(50);
        // /*------------------ ft::vectors ---------------------*/
        // ft_valid_it = ft_v1.begin();
        // ft_v1.resize(50);

        // z3 = v1.size();
        // ft_z3 = ft_v1.size();
        // c3 = v1.capacity();
        // ft_c3 = ft_v1.capacity();
        // for (size_t i = 0; i < v1.size(); ++i)
        //     s3 += v1[i];

        // for (; valid_it != v1.end(); ++valid_it)
        //     sit2 += *valid_it;

        // for (ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        //     ft_s3 += *it;

        // for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
        //     ft_sit2 += *ft_valid_it;
        // /*----------------------------------------------------*/
        // /*
        //  * test with n = 0
        //  */
        // /*------------------ std::vectors ---------------------*/
        // valid_it = v1.begin();
        // v1.resize(0, "string4");
        // /*------------------ ft::vectors ---------------------*/
        // ft_valid_it = ft_v1.begin();
        // ft_v1.resize(0, "string4");

        // z4 = v1.size();
        // ft_z4 = ft_v1.size();
        // c4 = v1.capacity();
        // ft_c4 = ft_v1.capacity();
        // for (size_t i = 0; i < v1.size(); ++i)
        //     s4 += v1[i];

        // for (; valid_it != v1.end(); ++valid_it)
        //     sit3 += *valid_it;

        // for (ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        //     ft_s4 += *it;

        // for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
        //     ft_sit3 += *ft_valid_it;
        // /*----------------------------------------------------*/
        // EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1 && sit1 == ft_sit1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3 && sit2 == ft_sit2) && (s4 == ft_s4 && z4 == ft_z4 && c4 == ft_c4 && sit3 == ft_sit3));
    }
}