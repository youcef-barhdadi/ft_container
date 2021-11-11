
# include  <functional>
#include <iostream>
template<
    class T
> 
class  node {

    public :
          node *left;
           node *right;
          node *parent;
        T value;
        int color;

            node (T value)
            {
                this->left = nullptr;
                this->right = nullptr;
                this->value = value;
                this->color = 1;
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

            node<T>  *_insert(node<T> *_node ,T value)
            {
                    // std::cout << "Hello world" << std::endl;
                    if (_node == nullptr)
                    {
                            _node = new node<T>(value);
                            if (this->root == nullptr)
                            {
                                this->root = _node;
                            }
                            return _node;
                    }
                    if (_node->value >= value)
                    {
                       _node->left =   _insert(_node->left, value);
                    }
                    else {
                        _node->right = _insert(_node->right, value);
                    }
                    
                    return _node;
            } 


        void rebalnced()
        {
            
        }
            

    
};