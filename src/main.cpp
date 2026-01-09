#include <iostream>
#include "avl/avl.hpp"
using namespace std;

// 
// 
/* ************************ 🟢 Insert Functionality Start  🟢 ***************************** */
// 
// 


// insert helper function
Node* AVLTree::insertUtil(Node* root,int n){
    if(!root)return new Node(n);
    if(n < root->data)root->left=  AVLTree::insertUtil(root->left,n);
    else root->right = AVLTree::insertUtil(root->right,n);
    this->update_height(root);
    root = this->balance(root);
    this->update_height(root);
    return root;
}

// insert public API
void AVLTree::insert(int n){
    this->root = insertUtil(this->root,n);
};

//
//
/* ************************ 🔴 Insert Functionality END  🔴 ******************************* */
// 
// 

// ----------------------------- Search functionality ----------------------

// helper for search funtion
Node* AVLTree::searchUtil(Node* root,int n){
    if(!root)return root;
    else if(root->data == n)return root;
    else if(n < root->data)return AVLTree::searchUtil(root->left,n);
    else return AVLTree::searchUtil(root->right,n);
}

// ---- public search API method
bool AVLTree::search(Node* root,int n){
    if(!root)return false;
    return this->searchUtil(root,n) != nullptr;
}


/* ************************ Search Functionality END ******************************* */
// 
// 
// 
