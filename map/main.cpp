// #include "rbtree.hpp"
#include "map.hpp"
#include<utility>
#include "pair.hpp"

int main()
{
        // RBtree<int> *t = new RBtree<int>();
      
                    // std::cout << "Hi" << std::endl;

        map<int, int> l;
        l.insert(pair<int, int>(4,55));
        l.insert(pair<int, int>(12,515));
        l.insert(pair<int, int>(0,515));
        l.tree->print();

        // t->insert(1);
        // t->insert(2);
        // t->insert(3);
        // t->insert(4);
        // t->insert(4);
        // t->insert(2);
        // t->insert(5);
        // t->insert(-1);
        // t->insert(0);
        // t->insert(9);
        // t->insert(24);
        // t->insert(14);
        // t->insert(99);

        // t->print();
        // std::cout << t->exist(99) <<   std::endl;

        // std::cout <<   "|" << t->root->value << std::endl << std::endl;
        // std::cout  << t->root->left->value  <<  std::endl << std::endl;
        // std::cout  << t->root->left->left->value  <<  std::endl << std::endl;

        // std::cout   << t->root->right->value   << std::endl << std::endl;
        // std::cout << t->root->right->left->value << std::endl << std::endl;
        // std::cout << t->root->right->right->value << std::endl << std::endl;
        // std::cout << t->root->left->right  << "|" <<  t->root->left->right->value << std::endl << std::endl;
                    // std::cout << "Hi" << std::endl;
        //      map<int, int >s;
        //      s.insert(std::pair<int,int>(20,100));

}