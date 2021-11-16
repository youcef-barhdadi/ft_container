
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
                node<T> *t =    _insert(this->root, value);
                if (this->last != nullptr)
                {
                    check(this->last);
                    last = nullptr;
                }
            }




            void _print(node<T> *n)
            {
                if (n == nullptr)
                {
                    return ;
                }

                _print(n->left);
                std::cout << "[" << n->value  <<  " , is root " << (n == this->root) << ( n->isRight ? " is right" : " is left ") <<  "]" << std::endl;
                _print(n->right);
            }
            void print()
            {
                _print(this->root);
            }

            size_t size()
            {
                if (this->root == nullptr)
                    return  0;
                return 1;
            }
            node<T>  *root;
            


        private :
                node<T> *last;
           

            void rightRotate(node<T> *n)
            {
                std::cout <<  n->value <<"right rotate"  << std::endl;
                if (n == nullptr)
                        return ;

                node<T> *temp = n->left;

                n->left =  temp->right;

                if (n->left != nullptr)
                {
                    n->left->isRight = false;
                    n->left->parent = n;
                } 
                if (n->parent == nullptr)
                {
                    this->root = temp;
                    temp->parent = nullptr;
                }
                else {
                    temp->parent = n->parent;
                    if (n->isRight == true)
                    {
                        temp->isRight = true;
                        temp->parent->right = temp;
                    }
                    else {
                        temp->isRight = false;
                        temp->parent->right = temp;
                    }
                }
                temp->right = n;
                n->isRight = true;
                n->parent = temp;
            }


            void leftRoutate(node<T> *n)
            {                                
                std::cout << "=====left rotate"  <<  n->right->value << std::endl;
                if (n == nullptr)
                    return ;                    
                node<T> *temp = n->right;
                if (temp == nullptr)
                    return ;
                n->right = temp->left;
      
                if (n->right != nullptr)
                {
                    n->right->parent = n;
                    n->right->isRight = true;
                }
                if (n->parent == nullptr)
                {
                    this->root = temp;
                    temp->parent = nullptr;
                }
                else {
                    temp->parent = n->parent;
                    if (n->isRight == false)
                    {
                        temp->isRight = false;
                        temp->parent->left =temp;
                    }else {
                         temp->isRight = true;
                        temp->parent->right = temp;
                    }
                }
                temp->left = n;
                n->isRight  = false;
                n->parent = temp;
            }


            void leftRightRotate(node<T> *n)
            {
                std::cout << "left right rotate" << std::endl;
                if (n == nullptr)
                    return ;
                leftRoutate(n->parent);

                rightRotate(n);
            }
         void    rightleftRotate (node<T> *n)
            {
                std::cout << "right left rotate" << std::endl;
                rightRotate(n->parent);
                leftRoutate(n);
            }

            void rotrate(node<T> *n)
            {
                if (n->isRight == false)
                {
                    if (n->parent->isRight == false)
                    {              
                        rightRotate(n->parent->parent);
                        n->color =Red;
                        n->parent->color = Black;
                        if (n->parent->right != nullptr)
                                n->parent->right->color = Red;
                        return ;
                    }
                         rightleftRotate(n->parent->parent);
                        n->color =  Black;
                        n->right->color = Red;
                        n->left->color = Red;
                    return ;
                }
                if (n->parent->isRight == true)
                {
                        leftRoutate(n->parent->parent);
                                        std::cout << "here" << (this->root->left->right) << std::endl;

                        n->color = Red;
                        n->parent->color = Black;
                        if (n->parent->left != nullptr)
                            n->parent->left->color = Red;
                        return ;
                }
                leftRightRotate(n->parent->parent);
                
                n->color = Black;
                if (n->right !=nullptr)
                    n->right->color = Red;
                if (n->left != nullptr)
                    n-> left->color = Red;
                 
            }

            void correct(node<T> *n)
            {
                if (n == nullptr)
                    return ;
                if (n == this->root)
                {
                   if (n->color == Red)
                        n->color = Black;

                    return ;
                }
                            //  std::cout <<"dd"<< std::endl;


                if (n->parent->isRight == false)
                {
                        if (( n->parent->parent &&  n->parent->parent->right == nullptr) || (n->parent->parent && n->parent->parent->right->color == Black))
                        {
                            rotrate(n);
                                                        //  std::cout << n->parent->parent << std::endl;

                            return ;
                        }
                        // here red
                        if (n->parent->parent->right != nullptr)
                                n->parent->parent->right->color = Black;
                        n->parent->parent->color = Red;
                        n->parent->color = Black;
                    return ;
                }

                if (n->parent->parent->left ==  nullptr || n->parent->parent->right->color == Black)
                {
                    rotrate(n);
                    return ;

                }
                if (n->parent->parent->left != nullptr)
                        n->parent->parent->left->color = Black;
                n->parent->parent->color =Red;
                n->parent->color = Black;

                return ;
            }
            void check(node<T> *n)
            {
                  if ( n == this->root )
                  {
                      return ;
                  }
   
                
                if (n->color == Red && (n->parent->color == Red))
                {
                    if (n->parent->parent != nullptr)
                    {
                        correct(n);

                    }

                }
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
                                last = _node;
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
                            last = temp;

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
                            last = temp;

                        }
                        else {
                            _node->right = temp;
                        }
                        // temp->parent = _node->right;

                    }
                    
                    return _node;
        } 

            

    
};