#include <iostream>
#include "avl/avl.hpp"
using namespace std;
//
//
/* *********************** 🟢 Inorder Traversal 🟢 ********************** */
//
//


void AVLTree::printUtil(Node* root){
    if(!root)return;
    this->printUtil(root->left);
    cout<<root->data<<" "<<root->height<<"\n";
    this->printUtil(root->right);
}
void AVLTree::print(){
    this->printUtil(this->root);
}


//
//
/* *********************** 🔴 Inorder End 🔴 ********************** */
//
//


