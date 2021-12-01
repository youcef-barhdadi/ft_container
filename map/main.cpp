// #include "rbtree.hpp"
#include "map.hpp"
#include<utility>
#include "pair.hpp"
#include <map>


#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 4 // the ft::Map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

typedef std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> iter_def;
typedef ft::pair<ft::Map<int, std::string>::iterator, ft::Map<int, std::string>::iterator> ft_iter_def;
typedef std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator> const_iter_def;
// typedef ft::pair<ft::Map<int, std::string>::const_iterator, ft::Map<int, std::string>::const_iterator> ft_const_iter_def;

#define TEST_CASE(fn)                                                                                                             \
    cout << GREEN << "\t======================================================================================" << RESET << endl; \
    cout << endl;                                                                                                                 \
    cout << BLUE << "\t   Running " << #fn << " ... \t\t\t\t\t\t" << RESET << std::endl;                                          \
    fn();                                                                                                                         \
    cout << endl;                                                                                                                 \
    cout << GREEN << "\t======================================================================================" << RESET << endl;
using namespace std;

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}
int main()
{
        std::map<int, char> m;
    std::map<int, char>::iterator it, it1;

    ft::Map<int, char> my_m;
    ft::Map<int, char>::iterator my_it, my_it1, tmp;

    for (int i = 0; i < 10; ++i)
    {
        my_m.insert(ft::make_pair(i, static_cast<char>(i + 97)));
        m.insert(std::make_pair(i, static_cast<char>(i + 97)));
    }

    it = m.begin();
    it1 = ++(m.begin());
    my_it = my_m.begin();
    my_it1 = ++(my_m.begin());
    /*----------------------------------*/
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
              << "] --------------------]\t\t\033[0m";
    {
        ft::Map<int, char>::iterator ob(my_it);
        EQUAL(&(*my_it) == &(*ob));
    }


 
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it == it1) == (my_it == my_it1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it != it1) == (my_it != my_it1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((((*my_it).second = '6') == '6') && ((*my_it).first == ((*my_m.begin()).first)));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*--------------- std::map-------------------- */
        std::map<int, std::string> m;
        ft::Map<int, std::string> my_m;

        for (int i = 0; i < 5; ++i)
        {
            m.insert(std::make_pair(13, "HELLO"));
            my_m.insert(ft::make_pair<int, std::string>(13, "HELLO"));
        }
        // my_m.tree->print();
        ft::Map<int, std::string>::iterator my_it = my_m.begin();
        std::map<int, std::string>::iterator it = m.begin();
        /*---------------------------------------------- */
        EQUAL(it->second.length() == my_it->second.length());
    }
  
       std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;

            std::map<int, std::string> m;
            ft::Map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e5; ++i)
            {
                // m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair<int, std::string>(i, "value"));
            }
            ft_m.tree->print();
            start = get_time();
            // for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
            //     ;
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            for (ft::Map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                ;
            ualarm(0, 0);
        }
    //     bool cond(false);
    //     {
    //         int res(0);
    //         int myints[] = {12, 82, 37, 64, 15};
    //         ft::Map<int, int> m;
    //         for (size_t i = 0; i < 5; ++i)
    //             m.insert(ft::make_pair<int, int>(myints[i], i));
    //         for (ft::Map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    //             res += it->first;
    //         cond = res == 210;
    //     }
    //     // {
    //     //     int res(0), tmp;
    //     //     int myints[] = {12, 82, 37, 64, 15};
    //     //     ft::Map<int, int> m;
    //     //     for (size_t i = 0; i < 5; ++i)
    //     //         m.insert(ft::make_pair<int, std::string>(myints[i], i));
    //     //     ft::Map<int, int>::iterator it = m.begin(), eit = --m.end();
    //     //     tmp = eit->first;
    //     //     m.erase(eit);
    //     //     for (; it != m.end(); ++it)
    //     //         res += it->first;
    //     //     cond = cond && (res == (210 - tmp));
    //     // }
    //     ++my_it; // I incremented here to make sure that the object changes
    //     EQUAL(*my_it == *my_it1);
    }

    
//      my_m.tree->print();

}