
#pragma once
#include <iostream>
#include "pair.hpp"

namespace ft {
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
        typedef T& reference;
        typedef T* pointer;
        // node <T> _end;

        bool isRight ;

            node (T value)
            {
                // std::cout <<  "node created with  value" << value << std::endl;
                this->left = NULL;
                this->right = NULL;
                this->value = value;
                this->color = Red;
                this->parent = NULL;
                isRight = false;
            }

        node<T> *findNextNode(node<T> *n)
        {
            node<T> *tmp = n ;
            if (n->right)
            {
                tmp  =  n->right;
                while(tmp->left)
                {
                    tmp = tmp->left;
                }
                return tmp;

            }else {
                   if (tmp->parent !=NULL)
                   {    
                            return tmp->parent;
                   }
                   else 
                   {
                       return tmp;
                   }
            }
        }



        node<T> *findPrevious(node<T> *n)
        {
            node<T> *tmp = n ;
            if (n->left)
            {
                tmp  =  n->left;
                while(tmp->right)
                {
                    tmp = tmp->right;
                }
                return tmp;

            }else {
                // tmp = tmp;
                   if (tmp->parent !=NULL)
                   {    
                        if (tmp->isRight)
                            return tmp->parent;
                        
                        //  std::cout << "====>hello world1" << std::endl;
                        tmp = tmp->parent;
                        node<T >  *kepp = tmp;
                        while ( tmp && tmp->parent  && tmp->parent->isRight ==  false  )
                        {
                            kepp = tmp;
                            tmp = tmp->parent;
                        }
                        return tmp->parent;
                   }
                   else 
                   {
                       return tmp;
                   }
            }
        }
  
} ;
// :()
template<
    class T
> class RBtree
{

        public :
                typedef T& reference;

            RBtree()
            {
                this->root = NULL;
                this->last = NULL;
            }

            void insert(T value)
            {
                // std::cout << value << std::endl;
                 insert2(this->root, value);

                // if (this->last != NULL)
                // {
                //     check(this->last);
                //     last = NULL;
                // }
            }


            int left = 0;
            int right =0;

            void _print(node<T> *n)
            {
                if (n == NULL)
                    return ;
                _print(n->left);
                 std::cout << "[" << n->value   << "]"  << (n->isRight == true ? " is right " : "is  left" )   << std::endl;
                _print(n->right);
            }
            void print()
            {
                left = 0;
                right = 0;
                std::cout << "print" << std::endl;
                _print(this->root);
             }

            size_t size()
            {
                if (this->root == NULL)
                    return  0;
                return 1;
            }



            
                node<T> *_find(node<T> *n ,T val)
                {
                        if (n == NULL)
                            return  n;
                        if (val < n->value)
                            _find(n->left, val);
                        else if (val > n->value)
                            _find(n->right, val);
                        else
                            return n;
                        return NULL;
                }

                node<T> *find(T val)
                {
                    return _find(root, val);
                }

                bool exist(T val)
                {
                    return find(val) != NULL;
                }
                


                bool isNullLeaf(node<T> *n)
                {
                    return n == NULL;
                }

                void _delete(node<T> *n , T val)
                {
                        if (root == NULL || isNullLeaf(n))
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
                    node<T> *temp = NULL;

                    while (n != NULL && !isNullLeaf(n))
                    {
                        temp = n;
                        n = n->left;
                    }
                    return temp != NULL ? temp : n;
                }

                
                node<T> *findBigger(node<T> *n)
                {
                    node<T> *temp = NULL;

                    while (n != NULL && !isNullLeaf(n))
                    {
                        temp = n;
                        n = n->right;
                    }
                    return temp != NULL ? temp : n;
                }
                void deleteOneChild(node<T> *n)
                {
                    if (n == NULL)
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
                    if (n->parent == NULL)
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
                    if (sibling->parent == NULL)
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
                if (n == NULL)
                        return ;

                node<T> *temp = n->left;

                n->left =  temp->right;

                if (n->left != NULL)
                {
                    n->left->isRight = false;
                    n->left->parent = n;
                } 
                if (n->parent == NULL)
                {
                    this->root = temp;
                    temp->parent = NULL;
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
                if (n == NULL)
                    return ;                    
                // std::cout << "=====left rotate"  <<  n->value << std::endl;
                node<T> *temp = n->right;
                if (temp == NULL)
                    return ;
                n->right = temp->left;

                if (n->right != NULL)
                {
                    n->right->parent = n;
                    n->right->isRight = true;
                }
                if (n->parent == NULL)
                {
                    this->root = temp;
                    temp->parent = NULL;
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
                if (n == NULL)
                    return ;
                leftRoutate(n->left);

                rightRotate(n);
            }
         void    rightleftRotate (node<T> *n)
            {
                if (n == NULL)
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
                        if (n->parent->right != NULL)
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
                        n->color = Red;
                        n->parent->color = Black;
                        if (n->parent->left != NULL)
                            n->parent->left->color = Red;
                        return ;
                }
                leftRightRotate(n->parent->parent);
                n->color = Black;
                n->right->color = Red;
                n-> left->color = Red;
            }

            void correct(node<T> *n)
            {
                if (n == NULL)
                    return ;
                if (n == this->root)
                {
                   if (n->color == Red)
                        n->color = Black;
                    return ;
                }
                if (n->parent->isRight == false)
                {
                        if (((   n->parent->parent->right == NULL) || ( ( n->parent->parent->right && n->parent->parent->right->color == Black))))
                        {
                            rotrate(n);
                            return ;
                        }
                        // here red
                        if (n->parent->parent->right != NULL)
                                n->parent->parent->right->color = Black;
                        n->parent->parent->color = Red;
                        n->parent->color = Black;
                    return ;
                }

                if (n->parent->parent->left ==  NULL || n->parent->parent->right->color == Black)
                {
                    rotrate(n);
                    return ;
                }
                if (n->parent->parent->left != NULL)
                        n->parent->parent->left->color = Black;
                n->parent->parent->color =Red;
                n->parent->color = Black;
                return ;
            }

            void check(node<T> *n)
            {
                if (n == NULL)
                        return;

                //   if ( n == this->root )
                //   {
                //      correct(n);
                //       return ;
                //   }
                if (n->color == Red && ( n->parent &&  n->parent->color == Red))
                {                      
                    if (n->parent->parent != NULL)
                    {

                        correct(n);
                    }
                }
                check(n->parent);
                
            }

            /*
                this function insert itratavly . i think it's fast then recusive one
            */
            node<T> *insert2(node<T> *tmp, T value)
            {
                node<T> *tmp1;

                tmp1 = tmp;
                if (root == NULL)
                {
                    this->root = new node<T>(value);
                    root->color = Black;
                    return this->root;
                }
                while (tmp1 != NULL)
                {
                    tmp = tmp1;
                    tmp1  = (value< tmp1->value) ? tmp1->left: tmp1->right;
                }
    
                if (value < tmp->value)
                {
                    // std::cout << "left" << std::endl;
                    tmp->left = new node<T>(value);
                    tmp->left->parent = tmp;
                    check(tmp->left);
                    return tmp->left;

                }else 
                {
                    tmp->right = new node<T>(value);
                    tmp->right->parent = tmp;
                    tmp->right->isRight = true;
                    check(tmp->right);
                    return tmp->right;
                }
            }



            node<T>  *_insert(node<T> *_node ,T value)
            {
                    if (_node == NULL)
                    {
                            _node = new node<T>(value);
                            if (this->root == NULL)
                            {
                                _node->color = Black;
                                this->root = _node;
                                last = _node;
                            }
                            return _node;
                    }
                    if (value < _node->value)
                    {
                        std::cout << "in left" << std::endl;
                        node<T> *temp  =   _insert(_node->left, value);
                        if (_node->left  == NULL)
                        {
                            _node->left = temp;
                            temp->parent = _node;
                            temp->isRight = false;
                            last = temp;
                        }
                        else {
                            // _node->left = temp;
                        }
                    }
                    else {
                        // std::cout << "in right" << std::endl;
                        node<T> *temp = _insert(_node->right, value);
                        if (_node->right == NULL)
                        {

                            temp->isRight = true;
                            _node->right = temp;
                            // std::cout <<  << temp->isRight << std::endl;
                            temp->parent = _node;
                            last = temp;
                        }
                        else {
                            // _node->right = temp;
                        }
                    }
                    return _node;
            } 

            

    
};

};