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
     my_it1 = (my_m.begin());
//      ++my_it;
     ++my_it;
     ++my_it;
     ++my_it;
     ++my_it;
    std::cout << "========{" << (*my_it)   << ",  " << (*my_it1) << "}" << std::endl;
    --my_it;
    std::cout <<  "deincremnt " << (*my_it)  << std::endl;
    --my_it;
        std::cout <<  "deincremnt " << (*my_it)  << std::endl;
    --my_it;
        std::cout <<  "deincremnt " << (*my_it)  << std::endl;
    --my_it;
        std::cout <<  "deincremnt " << (*my_it)  << std::endl;

        while (&(*my_it) != (&*my_m.end()))
        {
                        std::cout <<  "this-> " << (*my_it)  << std::endl;
                        ++my_it;

        }

        std::cout << "Here" << std::endl;
            while (&(*my_it) != (&*my_m.begin()))
        {
                        std::cout <<  "this-> " << (*my_it)  << std::endl;
                        --my_it;

        }
//     --my_it;
  
//      my_m.tree->print();

}