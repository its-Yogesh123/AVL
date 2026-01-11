#include <iostream>
#include "avl/avl.hpp"
using namespace std;
//
//
/* *********************** 🟢 Inorder Traversal 🟢 ********************** */
//
//


void AVLTree::inorderUtil(Node* root,vector<int>& inorder){
    if(!root)return;
    this->inorderUtil(root->left,inorder);
    inorder.push_back(root->data);
    this->inorderUtil(root->right,inorder);
}
vector<int> AVLTree::inorder(){
    vector<int> data;
    this->inorderUtil(this->root,data);    // recursive get all inorder
    return data;
}




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
//
//
/* *********************** 🟢 Preorder Traversal 🟢 ********************** */
//
//


void AVLTree::preorderUtil(Node* root,vector<int>& preorder){
    if(!root)return;
    preorder.push_back(root->data);
    this->preorderUtil(root->left,preorder);
    this->preorderUtil(root->right,preorder);
}
vector<int> AVLTree::preorder(){
    vector<int> data;
    this->preorderUtil(this->root,data);    // recursive get all inorder
    return data;
}

//
//
/* *********************** 🔴 Inorder End 🔴 ********************** */
//
//
//
//
/* *********************** 🟢 Postorder Traversal 🟢 ********************** */
//
//


void AVLTree::postorderUtil(Node* root,vector<int>& postorder){
    if(!root)return;
    this->postorderUtil(root->left,postorder);
    this->postorderUtil(root->right,postorder);
    postorder.push_back(root->data);
}
vector<int> AVLTree::postorder(){
    vector<int> data;
    this->postorderUtil(this->root,data);    // recursive get all inorder
    return data;
}

//
//
/* *********************** 🔴 Postorder End 🔴 ********************** */
//
//


