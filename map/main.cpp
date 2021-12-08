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
void testCapacityMethods();
void testElementAccess();
void testModifiers();
int main()
{

    // const_iterator_tests();
    // testIterators();
    // EQUAL(testMapConstructors());
    // testCapacityMethods();
    // testElementAccess();
      testModifiers();
    return (0);
            
}




void testModifiers()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond(false);
        // {
        //     time_t start, end, diff;
        //     /*------------------ std::maps ---------------------*/
        //     std::map<int, std::string> m1;
        //     ft::Map<int, std::string> ft_m1;

        //     start = get_time();
        //     for (size_t i = 0; i < 1e6; i++)
        //         m1.insert(std::make_pair(i, "string2"));
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::Maps ---------------------*/
        //     ualarm(diff * 1e3, 0);
        //     for (size_t i = 0; i < 1e6; i++)
        //         ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));

        //     ualarm(0, 0);
        //     /*----------------------------------------------------*/
        //     /*------------------ std::maps ---------------------*/
        //     std::map<int, std::string> m_range;
        //     ft::Map<int, std::string> ft_m_range;

        //     start = get_time();
        //     m_range.insert(m1.begin(), m1.end());
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::Maps ---------------------*/
        //     ualarm(diff * 1e3, 0);
        //     ft_m_range.insert(ft_m1.begin(), ft_m1.end());
        //     ualarm(0, 0);
        //     /*----------------------------------------------------*/
        // }

        // {
        //     time_t start, end, diff;
        //     /*------------------ std::maps ---------------------*/
        //     std::map<int, std::string> m1;
        //     ft::Map<int, std::string> ft_m1;

        //     start = get_time();
        //     m1.insert(std::make_pair(1e9, "string2"));
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::Maps ---------------------*/
        //     ualarm(diff * 1e3, 0);
        //     ft_m1.insert(ft::make_pair<int, std::string>(1e9, "string2"));
        //     ualarm(0, 0);
        //     /*----------------------------------------------------*/
        // }

        std::map<char, int> m;
        ft::Map<char, int> ft_m;

        cond = m.size() == ft_m.size() && m.empty() == ft_m.empty();
      

        // first insert function version (single parameter):
        m.insert(std::pair<char, int>('a', 100));
        m.insert(std::pair<char, int>('z', 200));

        ft_m.insert(ft::pair<char, int>('a', 100));
        ft_m.insert(ft::pair<char, int>('z', 200));

        
    

        cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());
        std::pair<std::map<char, int>::iterator, bool> ret;
        ft::pair<ft::Map<char, int>::iterator, bool> ft_ret;

        ret = m.insert(std::pair<char, int>('z', 500));
        ft_ret = ft_m.insert(ft::pair<char, int>('z', 500));

        cond = cond && ret.second == ft_ret.second;

        // second insert function version (with hint position):
        std::map<char, int>::iterator it = m.begin();
        ft::Map<char, int>::iterator ft_it = ft_m.begin();
        m.insert(it, std::pair<char, int>('b', 300));
        m.insert(it, std::pair<char, int>('c', 400));

        ft_m.insert(ft_it, ft::pair<char, int>('b', 300));
        ft_m.insert(ft_it, ft::pair<char, int>('c', 400));
        std::cout << std::endl;
        ft_m.tree.printTree();

        cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());


        // third insert function version (range insertion):
        std::map<char, int> anothermap;
        ft::Map<char, int> ft_anothermap;
        anothermap.insert(m.begin(), m.find('c'));
        ft_anothermap.insert(ft_m.begin(), ft_m.find('c'));
        ft::Map<char, int>::iterator cccc = ft_m.find('c');

        cond = cond && (anothermap.size() == ft_anothermap.size() && anothermap.empty() == ft_anothermap.empty());
        // std::cout << "==>|>" <<   *(ft_m.find('c')) << std::endl;

        cond = cond && compareMaps(ft_m.begin(), ft_m.end(), m.begin(), m.end()) && compareMaps(ft_anothermap.begin(), ft_anothermap.end(), anothermap.begin(), anothermap.end());
        std::cout << cond << std::endl;
        exit(0);
        EQUAL(cond);
    }

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase method "
              << "] --------------------]\t\t\033[0m";

    {
        bool cond(false);
        // erasing all the elements in the map;
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
            }

            start = get_time();
            m1.erase(m1.begin(), m1.end());
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.erase(ft_m1.begin(), ft_m1.end());
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        std::map<char, int> m;
        ft::Map<char, int> ft_m;
        std::map<char, int>::iterator it;
        ft::Map<char, int>::iterator ft_it;

        // insert some values:
        ft_m['a'] = 10;
        ft_m['b'] = 20;
        ft_m['c'] = 30;
        ft_m['d'] = 40;
        ft_m['e'] = 50;
        ft_m['f'] = 60;

        m['a'] = 10;
        m['b'] = 20;
        m['c'] = 30;
        m['d'] = 40;
        m['e'] = 50;
        m['f'] = 60;

        cond = m.size() == ft_m.size() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('b');
        ft_it = ft_m.find('b');

        cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second);
        m.erase(it);       // erasing by iterator
        ft_m.erase(ft_it); // erasing by iterator

        cond = cond && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        int ret = m.erase('c');       // erasing by key
        int ft_ret = ft_m.erase('c'); // erasing by key

        cond = cond && ret == ft_ret && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('e');
        ft_it = ft_m.find('e');

        cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second) && m.size() == ft_m.size();

        m.erase(it, m.end());          // erasing by range
        ft_m.erase(ft_it, ft_m.end()); // erasing by range

        cond = cond && m.empty() == ft_m.empty() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        /* ---------- Testing some edge cases ---------- */

        std::map<int, std::string> m2;
        ft::Map<int, std::string> ft_m2;

        for (size_t i = 0; i < 1e5; i++)
        {
            m2.insert(std::make_pair(i, "string1"));
            ft_m2.insert(ft::make_pair<int , std::string>(i, "string1"));
        }

        std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
        ft::Map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();

        m2.erase(m2.begin());
        ft_m2.erase(ft_m2.begin());

        cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        m2.erase(it2->first);
        ft_m2.erase(ft_it2->first);

        cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        std::map<int, std::string> m3;
        ft::Map<int, std::string> ft_m3;
        std::vector<int> vec;
        std::vector<int> ft_vec;
        std::random_device randDev;
        std::mt19937 generator(randDev());
        std::uniform_int_distribution<int> distr(0, 1e8);

        for (size_t i = 0; i < 1e6; i++)
        {
            m3.insert(std::make_pair(i, "string1"));
            ft_m3.insert(ft::make_pair<int, std::string>(i, "string1"));
        }

        for (size_t i = 0; i < 1e6; ++i)
        {
            int n = distr(generator);
            int ret1 = m3.erase(n);
            int ret2 = ft_m3.erase(n);

            if (ret1 != ret2)
            {
                cond = false;
                break;
            }
        }

        if (!m3.empty())
        {
            m3.erase(m3.begin(), m3.end());
            m3.erase(m3.begin(), m3.end());
        }
        if (!ft_m3.empty())
        {
            ft_m3.erase(ft_m3.begin(), ft_m3.end());
            ft_m3.erase(ft_m3.begin(), ft_m3.end());
        }
        cond = cond && (m3.size() == ft_m3.size() && compareMaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()));

        EQUAL(cond);
    }

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " swap method "
              << "] --------------------]\t\t\033[0m";

    {
        {
            time_t start, end, diff;

            /* ------------------ a > b ------------------ */
            std::map<int, std::string> m1, m2;
            ft::Map<int, std::string> ft_m1, ft_m2;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
            }

            start = get_time();
            m1.swap(m2);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.swap(ft_m2);
            ualarm(0, 0);
            /*----------------------------------------------------*/

            /* ------------------ a and b are not empty ------------------ */
            for (size_t i = 0; i < 1e4; i++)
            {
                m2.insert(std::make_pair(i, "string2"));
                ft_m2.insert(ft::make_pair<int , std::string>(i, "string2"));
            }

            start = get_time();
            m1.swap(m2);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.swap(ft_m2);
            ualarm(0, 0);
            /*----------------------------------------------------*/

            /* ------------------ a == b ------------------ */
            m1 = m2 = std::map<int, std::string>();
            ft_m1 = ft_m2 = ft::Map<int, std::string>();
            start = get_time();
            m2.swap(m1);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m2.swap(ft_m1);
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        bool cond = false;
        std::map<char, int> foo, bar;
        ft::Map<char, int> ft_foo, ft_bar;

        foo['x'] = 100;
        foo['y'] = 200;

        ft_foo['x'] = 100;
        ft_foo['y'] = 200;

        cond = foo.size() == ft_foo.size() && bar.size() == ft_bar.size();

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        ft_bar['a'] = 11;
        ft_bar['b'] = 22;
        ft_bar['c'] = 33;

        cond = cond && foo.size() == ft_foo.size() && bar.size() == ft_bar.size() && compareMaps(foo.begin(), foo.end(), ft_foo.begin(), ft_foo.end()) && compareMaps(bar.begin(), bar.end(), ft_bar.begin(), ft_bar.end());

        foo.swap(bar);
        ft_foo.swap(ft_bar);

        cond = cond && foo.size() == ft_foo.size() && bar.size() == ft_bar.size() && compareMaps(foo.begin(), foo.end(), ft_foo.begin(), ft_foo.end()) && compareMaps(bar.begin(), bar.end(), ft_bar.begin(), ft_bar.end());

        std::map<std::string, std::string, std::greater<std::string> > m1, m2;
        ft::Map<std::string, std::string, std::greater<std::string> > ft_m1, ft_m2;

        m1["γ"] = "gamma";
        m1["β"] = "beta";
        m1["α"] = "alpha";
        m1["γ"] = "gamma";

        m2["ε"] = "eplsilon";
        m2["δ"] = "delta";
        m2["ε"] = "epsilon";

        ft_m1["γ"] = "gamma";
        ft_m1["β"] = "beta";
        ft_m1["α"] = "alpha";
        ft_m1["γ"] = "gamma";

        ft_m2["ε"] = "eplsilon";
        ft_m2["δ"] = "delta";
        ft_m2["ε"] = "epsilon";

        const std::pair<std::string, std::string> &ref = *(m1.begin());
        const std::map<std::string, std::string, std::greater<std::string> >::iterator iter = std::next(m1.begin());
        const ft::pair<std::string, std::string> &ft_ref = *(ft_m1.begin());
        const ft::Map<std::string, std::string, std::greater<std::string> >::iterator ft_iter = std::next(ft_m1.begin());

        // std::cout << "──────── before swap ────────\n"
        //           << "m1: " << m1 << "m2: " << m2 << "ref: " << ref
        //           << "\niter: " << *iter << '\n';

        cond = cond && ref.first == ft_ref.first && ref.second == ft_ref.second && iter->second == ft_iter->second && iter->first == ft_iter->first && m1.size() == ft_m1.size() && m2.size() && ft_m2.size();

        m1.swap(m2);
        ft_m1.swap(ft_m2);

        // _---------------_ << ──────── after swap ──────── >> _---------------_

        cond = cond && ref.first == ft_ref.first && ref.second == ft_ref.second && iter->second == ft_iter->second && iter->first == ft_iter->first && m1.size() == ft_m1.size() && m2.size() && ft_m2.size();

        EQUAL(cond);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " clear method "
              << "] --------------------]\t\t\033[0m";

    {
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
            }

            start = get_time();
            m1.clear();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.clear();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        bool cond(false);
        std::map<char, int> m;
        ft::Map<char, int> ft_m;

        m['x'] = 100;
        m['y'] = 200;
        m['z'] = 300;

        ft_m['x'] = 100;
        ft_m['y'] = 200;
        ft_m['z'] = 300;

        cond = m.size() == ft_m.size();

        m.clear();
        ft_m.clear();

        cond = cond && m.empty() == ft_m.empty() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        m['a'] = 1101;
        m['b'] = 2202;
        ft_m['a'] = 1101;
        ft_m['b'] = 2202;

        cond = cond && m.size() == ft_m.size() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        m = std::map<char, int>();
        ft_m = ft::Map<char, int>();

        m.clear();
        ft_m.clear();

        cond = cond && m.size() == ft_m.size() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        EQUAL(cond);
    }
}




void testElementAccess()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator [] "
              << "] --------------------]\t\t\033[0m";
    {
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;

            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
            }
            start = get_time();
            m1[1e6] = "string";
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[1e6] = "string";
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            start = get_time();
            m1[1e6 - 100] = "string";
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[1e6 - 100] = "string";
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            start = get_time();
            m1[1e6 - 100] = m1[1e5];
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[1e6 - 100] = ft_m1[1e5];
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        std::map<char, std::string> m;
        ft::Map<char, std::string> ft_m;

        m['a'] = "an element";
        m['b'] = "another element";
        m['c'] = m['b'];
        m['a'] = "test";

        ft_m['a'] = "an element";
        ft_m['b'] = "another element";
        ft_m['c'] = ft_m['b'];
        ft_m['a'] = "test";

        EQUAL(m['a'] == ft_m['a'] && m['b'] == ft_m['b'] && m['c'] == ft_m['c'] && m.size() == ft_m.size());
    }
}






void testIterators()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " begin and end methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
            }

            start = get_time();
            m1.begin();
            m1.end();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.begin();
            ft_m1.end();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::maps ---------------------*/
        std::map<int, std::string> m1;
        ft::Map<int, std::string> ft_m1;

        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
        }

        std::map<int, std::string> const m2(m1.begin(), m1.end());
        ft::Map<int, std::string> const ft_m2(ft_m1.begin(), ft_m1.end());

        /*-----------------------------------------------------*/
        /*------------------ ft::Maps ---------------------*/
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;
        for (std::map<int, std::string>::const_iterator rit = m2.begin(); rit != m2.end(); ++rit) // fill c_res from const m1
            c_res += rit->second;

        for (ft::Map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;
        for (ft::Map<int, std::string>::const_iterator rit = ft_m2.begin(); rit != ft_m2.end(); ++rit) // fill c_ft_res from const ft_m1
            c_ft_res += rit->second;
        
        int arr[] = {12, 82, 37, 64, 15};
        ft::Map<int, int> end_test;
        for(size_t i = 0; i < 5; ++i)
            end_test.insert(ft::make_pair<int, int>(arr[i], i));
        ft::Map<int, int>::iterator eit = end_test.end();
        eit--;
        EQUAL(res == ft_res && c_res == c_ft_res && eit->first == 82);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
            }

            start = get_time();
            m1.rbegin();
            m1.rend();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.rbegin();
            ft_m1.rend();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::maps ---------------------*/
        std::map<int, std::string> m1;
        ft::Map<int, std::string> ft_m1;

        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
        }

        std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
        ft::Map<int, std::string>  const ft_m2(ft_m1.rbegin(), ft_m1.rend());

        /*-----------------------------------------------------*/
        /*------------------ ft::Maps ---------------------*/
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
            res += it->second;
        for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
            c_res += rit->second;

        for (ft::Map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;


        for (ft::Map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
        {
            c_ft_res += rit->second;
        }

        int arr[] = {12, 82, 37, 64, 15};
        ft::Map<int, int> end_test;
        for(size_t i = 0; i < 5; ++i)
            end_test.insert(ft::make_pair<int , int>(arr[i], i));
        ft::Map<int, int>::reverse_iterator rit = end_test.rend();
        rit--;
        EQUAL(res == ft_res && c_res == c_ft_res && rit->first == 12);
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




void testCapacityMethods()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " size method "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
            }

            start = get_time();
            m1.size();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::maps ---------------------*/
        std::map<int, std::string> m1; // fill constructor
        ft::Map<int, std::string> ft_m1;
        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair<int, std::string>(i, "string2"));
        }

        std::map<int, std::string> m2;                         // empty constructor
        std::map<int, std::string> m3(m1.begin(), m1.end());   // range constructor with normal iterators
        std::map<int, std::string> m4(m3);                     // copy constructor
        std::map<int, std::string> m5(m1.rbegin(), m1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::Maps ---------------------*/
        ft::Map<int, std::string> ft_m2;
        ft::Map<int, std::string> ft_m3(ft_m1.begin(), ft_m1.end());
        ft::Map<int, std::string> ft_m4(ft_m1);
        ft::Map<int, std::string> ft_m5(ft_m1.rbegin(), ft_m1.rend());
        /*----------------------------------------------------*/
        EQUAL(m1.size() == ft_m1.size() && m2.size() == ft_m2.size() && m3.size() == ft_m3.size() && m5.size() == ft_m5.size() && m4.size() == ft_m4.size());
    }

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " empty method "
              << "] --------------------]\t\t\033[0m";
    {
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::Map<int, std::string> ft_m1;
        ft::Map<int, std::string> ft_m2;
        m1[0] = "stringsrtring";
        ft_m1[0] = "stringsrtring";
        EQUAL(m1.empty() == ft_m1.empty() && m2.empty() == ft_m2.empty());
    }
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