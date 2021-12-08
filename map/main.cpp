#include "rbtree.hpp"
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
#define TIME_FAC 20 // the ft::Map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

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

using namespace std;
int printtime() {
   time_t t; // t passed as argument in function time()
   struct tm * tt; // decalring variable for localtime()
   time (&t); //passing argument to time()
   tt = localtime(&t);
   cout << "Current Day, Date and Time is = "<< asctime(tt);
   return 0;
}

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
        // std::cout << "this is good "  << std::endl;
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
    {
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    }
    return true;
}


struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};
bool fncomp(char lhs, char rhs) { return lhs < rhs; }


bool testMapConstructors();
void const_iterator_tests(void);
void testIterators();


int main()
{

    // const_iterator_tests();
    testIterators();
     
    return (0);
            
}






void testIterators()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " begin and end methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        // {
        //     time_t start, end, diff;
        //     /*------------------ std::maps ---------------------*/
        //     std::map<int, std::string> m1;
        //     ft::Map<int, std::string> ft_m1;
        //     for (size_t i = 0; i < 1e6; i++)
        //     {
        //         m1.insert(std::make_pair(i, "string2"));
        //         ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
        //     }

        //     start = get_time();
        //     m1.begin();
        //     m1.end();
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::Maps ---------------------*/
        //     ualarm(diff * 1e3, 0);
        //     ft_m1.begin();
        //     ft_m1.end();
        //     ualarm(0, 0);
        //     /*----------------------------------------------------*/
        // }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::maps ---------------------*/
        // std::map<int, std::string> m1;
        // ft::Map<int, std::string> ft_m1;

        // for (size_t i = 0; i < 10; i++)
        // {
        //     m1.insert(std::make_pair(i, "string2"));
        //     ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
        // }

        // std::map<int, std::string> const m2(m1.begin(), m1.end());
        // ft::Map<int, std::string> const ft_m2(ft_m1.begin(), ft_m1.end());

        // /*-----------------------------------------------------*/
        // /*------------------ ft::Maps ---------------------*/
        // /*----------------------------------------------------*/
        // /*------------------ strings to store the results ----*/
        // std::string res, ft_res, c_res, c_ft_res;
        // /*----------------------------------------------------*/
        // for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
        //     res += it->second;
        // for (std::map<int, std::string>::const_iterator rit = m2.begin(); rit != m2.end(); ++rit) // fill c_res from const m1
        //     c_res += rit->second;

        // for (ft::Map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
        //     ft_res += it->second;
        // for (ft::Map<int, std::string>::const_iterator rit = ft_m2.begin(); rit != ft_m2.end(); ++rit) // fill c_ft_res from const ft_m1
        //     c_ft_res += rit->second;
        
        // int arr[] = {12, 82, 37, 64, 15};
        // ft::Map<int, int> end_test;
        // for(size_t i = 0; i < 5; ++i)
        //     end_test.insert(ft::make_pair<int, int>(arr[i], i));
        // ft::Map<int, int>::iterator eit = end_test.end();
        // eit--;
        // EQUAL(res == ft_res && c_res == c_ft_res && eit->first == 82);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        // {
        //     time_t start, end, diff;
        //     /*------------------ std::maps ---------------------*/
        //     std::map<int, std::string> m1;
        //     ft::Map<int, std::string> ft_m1;
        //     for (size_t i = 0; i < 1e6; i++)
        //     {
        //         m1.insert(std::make_pair(i, "string2"));
        //         ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
        //     }

        //     start = get_time();
        //     m1.rbegin();
        //     m1.rend();
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::Maps ---------------------*/
        //     ualarm(diff * 1e3, 0);
        //     ft_m1.rbegin();
        //     ft_m1.rend();
        //     ualarm(0, 0);
        //     /*----------------------------------------------------*/
        // }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::maps ---------------------*/
        std::map<int, std::string> m1;
        ft::Map<int, std::string> ft_m1;

        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
        }

        // std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
        // ft::Map<int, std::string>  const ft_m2(ft_m1.rbegin(), ft_m1.rend());

        /*-----------------------------------------------------*/
        /*------------------ ft::Maps ---------------------*/
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        // for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
        //     res += it->second;
        // for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
        //     c_res += rit->second;

        // for (ft::Map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
        //     ft_res += it->second;

        // ft_m2.tree.printTree();

        // for (ft::Map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
        // {
        //     // std::cout <<   "=="   << rit->second << std::endl; 
        //     c_ft_res += rit->second;
        // }
    //     int arr[] = {12, 82, 37, 64, 15};
    //     ft::Map<int, int> end_test;
    //     for(size_t i = 0; i < 5; ++i)
    //         end_test.insert(ft::make_pair<int , int>(arr[i], i));
    //     ft::Map<int, int>::reverse_iterator rit = end_test.rend();
    //     rit--;
    //     EQUAL(res == ft_res && c_res == c_ft_res && rit->first == 12);
    }
}








void const_iterator_tests(void)
{
    /*------------ std::map ---------*/
    std::map<int, char> m;
    std::map<int, char>::const_iterator it, it1;

    ft::Map<int, char> my_m;
    ft::Map<int, char>::const_iterator my_it, my_it1, tmp;

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
        ft::Map<int, char>::const_iterator ob(my_it);
        EQUAL(*my_it == *ob);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it == it1) == (my_it == my_it1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it != it1) == (my_it != my_it1));
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

        ft::Map<int, std::string>::iterator my_it = my_m.begin();
        std::map<int, std::string>::iterator it = m.begin();
        /*---------------------------------------------- */
        EQUAL(it->second.length() == my_it->second.length());
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
              << "] --------------------]\t\t\033[0m";
    ++my_it; // I incremented here to make sure that the object changes
    EQUAL(*my_it == *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator "
              << "] --------------------]\t\t\033[0m";
    --my_it; // I decremented here to make sure that the object changes
    EQUAL(*my_it != *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it++;
    EQUAL(*my_it != *tmp && *my_it == *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it--;
    EQUAL(*my_it != *tmp && *my_it == *(my_m.begin()));
}

bool testMapConstructors()
{
    bool cond;
    std::map<char, int> first;
    ft::Map<char, int> m_first;

    for (size_t i = 97; i < 130; i++)
    {
        first[i - 97] = i;
        m_first[i - 97] = i;
   
    }


    std::map<char, int> copy(first);

    ft::Map<char, int> m_copy(m_first);
    cond = first.size() == m_first.size()  &&  compareMaps(first.begin(), first.end(), m_first.begin(), m_first.end());

    std::map<char, int> second(first.begin(), first.end());
    ft::Map<char, int> m_second(m_first.begin(), m_first.end());
    cond = cond && second.size() == m_second.size() && compareMaps(second.begin(), second.end(), m_second.begin(), m_second.end());
    std::map<char, int> third(second);
    ft::Map<char, int> m_third(m_second);
    std::cout << "size ==> " << ( m_third.size()) << std::endl;
    cond = cond && third.size() == m_third.size() && compareMaps(third.begin(), third.end(), m_third.begin(), m_third.end());

    std::map<char, int, classcomp> fourth;  // class as Compare
    ft::Map<char, int, classcomp> m_fourth; // class as Compare

    cond = fourth.size() == m_fourth.size() && cond && compareMaps(fourth.begin(), fourth.end(), m_fourth.begin(), m_fourth.end());

    bool (*fn_pt)(char, char) = fncomp;
    std::map<char, int, bool (*)(char, char)> fifth(fn_pt);  // function pointer as Compare
    ft::Map<char, int, bool (*)(char, char)> m_fifth(fn_pt); // function pointer as Compare

    cond = fifth.size() == m_fifth.size() && cond && compareMaps(fifth.begin(), fifth.end(), m_fifth.begin(), m_fifth.end());

    first = std::map<char, int>();
    m_first = ft::Map<char, int>();

    cond = copy.size() == m_copy.size() && cond && compareMaps(copy.begin(), copy.end(), m_copy.begin(), m_copy.end());

    return cond;
}




// void const_iterator_tests(void)
// {
//     /*------------ std::map ---------*/
//     std::map<int, char> m;
//     std::map<int, char>::const_iterator it, it1;

//     ft::Map<int, char> my_m;
//     ft::Map<int, char>::const_iterator my_it, my_it1, tmp;

//     for (int i = 0; i < 10; ++i)
//     {
//         my_m.insert(ft::make_pair(i, static_cast<char>(i + 97)));
//         m.insert(std::make_pair(i, static_cast<char>(i + 97)));
//     }

//     it = m.begin();
//     it1 = ++(m.begin());
//     my_it = my_m.begin();
//     my_it1 = ++(my_m.begin());
//     /*----------------------------------*/

//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Map<int, char>::const_iterator ob(my_it);
//         EQUAL(*my_it == *ob);
//     }
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
//               << "] --------------------]\t\t\033[0m";
//     EQUAL((it == it1) == (my_it == my_it1));
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
//               << "] --------------------]\t\t\033[0m";
//     EQUAL((it != it1) == (my_it != my_it1));
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*--------------- std::map-------------------- */
//         std::map<int, std::string> m;
//         ft::Map<int, std::string> my_m;

//         for (int i = 0; i < 5; ++i)
//         {
//             m.insert(std::make_pair(13, "HELLO"));
//             my_m.insert(ft::make_pair<int, std::string>(13, "HELLO"));
//         }

//         ft::Map<int, std::string>::iterator my_it = my_m.begin();
//         std::map<int, std::string>::iterator it = m.begin();
//         /*---------------------------------------------- */
//         EQUAL(it->second.length() == my_it->second.length());
//     }
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
//               << "] --------------------]\t\t\033[0m";
//     ++my_it; // I incremented here to make sure that the object changes
//     EQUAL(*my_it == *my_it1);
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator "
//               << "] --------------------]\t\t\033[0m";
//     --my_it; // I decremented here to make sure that the object changes
//     EQUAL(*my_it != *my_it1);
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator "
//               << "] --------------------]\t\t\033[0m";
//     tmp = my_it++;
//     EQUAL(*my_it != *tmp && *my_it == *my_it1);
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator "
//               << "] --------------------]\t\t\033[0m";
//     tmp = my_it--;
//     EQUAL(*my_it != *tmp && *my_it == *(my_m.begin()));

// }