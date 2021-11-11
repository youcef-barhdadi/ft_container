#include "rbtree.hpp"


int main()
{
        RBtree<int> *t = new RBtree<int>();
                    // std::cout << "Hi" << std::endl;

        // t->inset(1337);
        // t->inset(1);
        // t->inset(55);
        // t->print();
                    // std::cout << "Hi" << std::endl;
                t->insert(1337);
                t->insert(42);
                t->insert(1);
                t->insert(2);
                t->insert(-9);
                t->insert(422);
                t->print();


}