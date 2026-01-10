#include <iostream>
#include "avl/avl.hpp"
using namespace std;


// 
// 
/* ************************ 🟢 General Functionality Start  🟢 ***************************** */
// 
// 


int AVLTree::size(){
    return this->size_;
};


bool AVLTree::isEmpty(){
    return this->root == NULL;
}

int AVLTree::tree_height(){
    if(!this->root)return 0;
    return this->root->height;
};

// 
// 
/* ************************ 🟢 Insert Functionality Start  🟢 ***************************** */
// 
// 


// insert helper function
Node* AVLTree::insertUtil(Node* root,int n){
    if(!root)return new Node(n);
    if(n < root->data)root->left=  this->insertUtil(root->left,n);
    else root->right = this->insertUtil(root->right,n);
    this->update_height(root);
    root = this->balance(root);
    this->update_height(root);
    return root;
}

// insert public API
void AVLTree::insert(int n){
    this->root = insertUtil(this->root,n);
    this->size_++;
};

//
//
/* ************************ 🔴 Insert Functionality END  🔴 ******************************* */
// 
// 

// 
// 
/* ************************ 🟢 Search Functionality Start  🟢 ***************************** */
// 
// 
// helper for search funtion
Node* AVLTree::searchUtil(Node* root,int n){
    if(!root)return root;
    else if(root->data == n)return root;
    else if(n < root->data)return this->searchUtil(root->left,n);
    else return this->searchUtil(root->right,n);
}

// ---- public search API method
bool AVLTree::search(int n){
    if(!this->root)return false;
    return this->searchUtil(this->root,n) != nullptr;
}


//
//
/* ************************ 🔴 Search Functionality END  🔴 ******************************* */
// 
// 




// 
// 
/* ************************ 🟢 Remove Functionality Start  🟢 ***************************** */
// 
// 
// using inorder predecessor for deleting an key

Node* AVLTree::getInorderPredecessor(Node* root,Node** replacement){
    if(!root->right){
        *replacement = root;
        return root->left;
    };
    root->right =this->getInorderPredecessor(root->right,replacement);
    this->update_height(root);
    root = this->balance(root);
    this->update_height(root);
    return root;
}

Node* AVLTree::removeUtil(Node* root,int n){
    if(!root)return nullptr;
    else if(root->data == n){
        if(!root->left && !root->right){
            return nullptr;
        }
        else if(!root->left){
            return root->right;
        }
        else if(!root->right){
            return root->left;
        }
        else{
            Node* replacement=nullptr;
            root->left = getInorderPredecessor(root->left,&replacement);
            replacement->left = root->left;
            replacement->right = root->right;
            root = replacement;
        }
    }
    else if(n < root->data)root->left = removeUtil(root->left,n);
    else root->right = this->removeUtil(root->right,n);
    this->update_height(root);
    root = this->balance(root);
    this->update_height(root);
    return root;
}

// ---- public search API method
void AVLTree::remove(int n){
    this->root =  this->removeUtil(this->root,n);
    this->size_--;
}


//
//
/* ************************ 🔴 Remove Functionality END  🔴 ******************************* */
// 
// 