
#pragma once
#include <iostream>
#include "pair.hpp"


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

                std::cout << "this is what created " << this->root->value <<  std::endl;
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
                std::cout << "[" << n->value   << "]" << std::endl;
                _print(n->right);
            }
            void print()
            {
                std::cout << "print" << std::endl;
                _print(this->root);
            }

            size_t size()
            {
                if (this->root == nullptr)
                    return  0;
                return 1;
            }



            
                node<T> *_find(node<T> *n ,T val)
                {
                        if (n == nullptr)
                            return  n;
                        if (val < n->value)
                            _find(n->left, val);
                        else if (val > n->value)
                            _find(n->right, val);
                        else
                            return n;
                        return nullptr;
                }

                node<T> *find(T val)
                {
                    return _find(root, val);
                }

                bool exist(T val)
                {
                    return find(val) != nullptr;
                }
                


                bool isNullLeaf(node<T> *n)
                {
                    return n== nullptr;
                }

                void _delete(node<T> *n , T val)
                {
                        if (root == nullptr || isNullLeaf(n))
                            return ;
                        if (n->value == val)
                        {
                            if (isNullLeaf(n->right) || isNullLeaf(n->left)){
                                            deleteOneChild(n);
                            
                            }else {
                                node<T> *next = findSamllest(n->right);
                                n->value = next->value;
                                _delete(n->right , next->value);
                            }
                        }
                        if (n->value < val)
                            _delete(n->right, val);
                        else
                            _delete(n->left, val);
                }

                node<T> *findSamllest(node<T> *n)
                {
                    node<T> *temp = nullptr;

                    while (n != nullptr && !isNullLeaf(n))
                    {
                        temp = n;
                        n = n->left;
                    }
                    return temp != nullptr ? temp : n;
                }
                void deleteOneChild(node<T> *n)
                {
                    if (n == nullptr)
                    {
                        std::cout << "null node " << std::endl;
                        return ;
                    }
                    node<T> *toDelete = isNullLeaf(n->right) ? n->left : n->right;

                    replaceNode(n, toDelete);

                    if (toDelete->color == Black)
                    {
                        if (toDelete->color == Red)
                        {
                            toDelete->color = Black;
                        }
                        else {
                            deleteCase1(toDelete);
                        }
                    }
                }

                void deleteCase1(node<T> *n)
                {
                    if (n->parent == nullptr)
                    {
                        this->root = n;
                        return ;
                    }
                    deleteCase2(n);
                }
                void deleteCase2(node<T> *n)
                {
                    node<T> *siblingNode = findSiblingNode(n);
                    if (siblingNode->color == Red)
                    {
                        if (siblingNode->isRight == false)
                        {
                            rightRotate(siblingNode);
                        }else {
                            leftRotate(siblingNode);
                        }

                        if (siblingNode == root)
                        {
                            root = siblingNode;
                        }
                    }

                deleteCase3(n);
                }

                void deleteCase3(node<T> *n)
                {
                    node <T> *sibling = findSiblingNode(n);
                    if (n->parent->color == Black && sibling->color == Black && sibling->left->color == Black && sibling->right->color == Black)
                    {
                        sibling->color = Red;
                        deleteCase1(n->parent);
                    }else {
                        deleteCase4(n);
                    }

                }
                void deleteCase4(node<T> *n)
                {                  
                    node <T> *sibling = findSiblingNode(n);
                    if (n->parent->color == Red && sibling->color == Black && sibling->left->color == Black && sibling->right->color == Black)
                    {
                        sibling->color = Red;
                        n->color = Black;
                    }else {
                        deleteCase5(n);
                    }

                }
                void deleteCase5(node<T> *n)
                {
                    node <T> *sibling = findSiblingNode(n);

                    if (sibling->color == Black)
                    {
                        if (n->isRight == false && sibling->right->color== Black && sibling->left->color == Red)
                        {
                            rightRotate(sibling->left);
                        }else if (n->isRight && sibling->left->color == Black && sibling->right->color ==  Black){
                                leftRoutate(sibling->right);
                        }
                    }
                    deleteCase6(n);
                }
                void deleteCase6(node<T> *n)
                {
                    node <T> *sibling = findSiblingNode(n);
                    sibling->color = sibling->parent->color;
                    sibling->parent->color = Black;
                    if(n->isRight == false)
                    {
                        sibling->right->color = Black;
                        leftRoutate(sibling);
                    }else {
                        sibling->left->color = Black;
                        rightRotate(sibling);
                    }
                    if (sibling->parent == nullptr)
                    {
                        root = sibling;
                    }

                }

                // void delete_node(node<T> *n)
                // {
                //     node<T> *toDelete = 

                // }

    //                private void replaceNode(Node root, Node child, AtomicReference<Node> rootReference) {
    //     child.parent = root.parent;
    //     if(root.parent == null) {
    //         rootReference.set(child);
    //     }
    //     else {
    //         if(isLeftChild(root)) {
    //             root.parent.left = child;
    //         } else {
    //             root.parent.right = child;
    //         }
    //     }
    // }


            node<T>  *root;
            


        private :
                node<T> *last;
           

            void rightRotate(node<T> *n)
            {
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
                        temp->parent->left = temp;
                    }
                }
                temp->right = n;
                n->isRight = true;
                n->parent = temp;
            }


            void leftRoutate(node<T> *n)
            {                                
                if (n == nullptr)
                    return ;                    
                // std::cout << "=====left rotate"  <<  n->value << std::endl;
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
                std::cout <<"left right rotate" << std::endl;
                if (n == nullptr)
                    return ;
                leftRoutate(n->left);

                rightRotate(n);
            }
         void    rightleftRotate (node<T> *n)
            {
                std::cout << "right left rotate" << std::endl;
                if (n == nullptr)
                        return ;
                rightRotate(n->right);
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
                // std::cout << "weee" <<   n->parent->parent  << std::endl;
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
                if (n == nullptr)
                        return;
                  if ( n == this->root )
                  {
                      correct(n);
                      return ;
                  }
   
                
                if (n->color == Red && ( n->parent &&  n->parent->color == Red))
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
                    std::cout << value << std::endl;
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