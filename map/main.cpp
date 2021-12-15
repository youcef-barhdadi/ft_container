
# include "map.hpp"


int main()
{

    ft::map<int, int> c;
    ft::map<std::string, int> strmap;

    for (size_t i = 0; i < 1000; i++)
    {
        c.insert(ft::make_pair(i, i));
    }

    for (ft::map<int, int>::iterator  it = c.begin(); it  != c.end(); ++it)
    {
        std::cout << it->first << std::endl;
    }

    std::cout <<  "size " << c.size() << std::endl ;
    std::cout <<  "size " <<  strmap.size() << std::endl ;
    

    c.erase(c.begin(), c.end());
    system("leaks a.out");


    
    
}