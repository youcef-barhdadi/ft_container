
# include  <functional>
#include <iostream>


enum Color {
    Red =1,
    Black = 2
};

template<
    class T
> 
class  node {

    public :
          node *left;
           node *right;
          node *parent;
        T value;
        Color color;

            node (T value)
            {
                this->left = nullptr;
                this->right = nullptr;
                this->value = value;
                this->color = Red;
            }
  
} ;

template<
    class T
> class RBtree
{

        public :





            void insert(T value)
            {
                _insert(this->root, value);
            }




            void _print(node<T> *n)
            {
                if (n == nullptr)
                {
                    return ;
                }
                _print(n->left);
                std::cout << "[" << n->value <<  "]" << std::endl;
                _print(n->right);
            }
            void print()
            {
                _print(this->root);
            }


        private :

            node<T>  *root;
            // RBtree *parent;
            // RBtree *left;
            // RBtree *right;
            // int color;
            // T value;



            void left_rotaion(node<T> *node)
            {

                node<T> *n = node->left;

                n->left = node;


                node->right = node->left->left;

                node = n;

            }

            void right_rotation(node<T> *node)
            {
                node<T> *B = node->left;
                t->left = node;
                node->right = B;

            }

            node<T>  *_insert(node<T> *_node ,T value)
            {
                    // std::cout << "Hello world" << std::endl;
                    if (_node == nullptr)
                    {
                            _node = new node<T>(value);
                            if (this->root == nullptr)
                            {
                                _node->color = Black;
                                this->root = _node;
                            }
                            return _node;
                    }
                    if (_node->value >= value)
                    {
                       _node->left =   _insert(_node->left, value);
                       _node->left->parent = _node->left;
                    }
                    else {
                        _node->right = _insert(_node->right, value);
                        _node->right->parent = _node->right;
                    }
                    
                    return _node;
        } 

            

    
};