
#pragma
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

        bool isRight;

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



            // void left_rotaion(node<T> *node)
            // {

            //     node<T> *n = node->left;

            //     n->left = node;


            //     node->right = node->left->left;

            //     node = n;

            // }

            // void leftRight(node<T> *n)
            // {
            //     left_rotaion(n->left);
            //     right_rotation(n);


            // }

            // void right_rotation(node<T> *_node)
            // {
            //     node<T> *B = _node->left;
            //     t->left = node;
            //     _node->right = B;

            // }




            void correct(node<T> *n)
            {
             
                return ;
            }
            void check(node<T> *n)
            {
                // std::cout << nullptr == NULL << std::endl;
                  if ( n == this->root )
                  {
                    //   std::cout << "end" << std::endl;
                      return ;
                  }
                //   if ( n->parent != nullptr &&  n->parent->color == Red )
                //   {
                //         // std::cout <<  "ff" << std::endl; 
                //   }
                
                if (n->color == Red && (n->parent->color == Red))
                        correct(n);
                check(n->parent);
                
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
                                _node->parent = nullptr;
                            }
                            return _node;
                    }
                    if (_node->value >= value)
                    {
                        node<T> *temp  =   _insert(_node->left, value);

                        if (_node->left  == nullptr)
                        {
                            _node->left = temp;
                            temp->parent = _node;
                            temp->isRight = false;
                            check(temp);
                        }
                        else {
                            _node->left = temp;
                        }
                    }
                    else {
                        node<T> *temp = _insert(_node->right, value);
                        if (_node->right == nullptr)
                        {
                            _node->right = temp;
                            temp->isRight = true;
                            temp->parent = _node;
                            check(temp);

                        }
                        else {
                            _node->right = temp;
                        }
                        // temp->parent = _node->right;

                    }
                    
                    return _node;
        } 

            

    
};