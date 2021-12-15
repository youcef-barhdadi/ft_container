#include "rbtree.hpp"
#include <map>
# include "map.hpp"
#include <string>


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


using namespace std;
int printtime() {
   time_t t; // t passed as argument in function time()
   struct tm * tt; // decalring variable for localtime()
   time (&t); //passing argument to time()
   tt = localtime(&t);
   cout << "Current Day, Date and Time is = "<< asctime(tt);
   return 0;
   
}

#define TIME_FAC 10// the ft::Map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}
int main()
{

  {
      ft::Map<int, int> c;

      for (size_t i = 0; i < 1e4; i++)
      {
        c.insert(ft::make_pair(i ,i));
      }

      for (size_t i = 0; i < 1e4; i++)
      {
        c.erase(i);
      }
      
      system("leaks a.out");
      
  }
      return (0);
}