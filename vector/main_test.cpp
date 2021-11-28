#include <iostream>
#include <vector>
using namespace std;



int main()
{

    std::vector<int> c;
        std::cout << c.capacity() << std::endl;
        c.resize(15);
        std::cout << c.capacity() << std::endl;
        c.resize(3);
        std::cout << c.capacity() << std::endl;


        std::vector<int>::iterator cc = c.begin();
        c.insert(cc, 1337);
        c.insert(cc, 5);
        c.insert(cc, 52);
        c.insert(cc, 5662);
        c.insert(cc, 2, 19);

        std::cout <<  c[0]  << " "<< c[1]  << " " << c[2] << " " << c[3] << " " << c[4] << std::endl;

    

}