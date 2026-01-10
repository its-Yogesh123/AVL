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
    else if(n < root->data)return AVLTree::searchUtil(root->left,n);
    else return AVLTree::searchUtil(root->right,n);
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
    this->update_height(this->root);
    root = this->balance(this->root);
    this->update_height(this->root);
    return root;
}

Node* AVLTree::removeUtil(Node* root,int n){
   
    if(!this->root)return nullptr;
    else if(root->data == n){
        if(!this->root->left && !this->root->right){
            return nullptr;
        }
        else if(!this->root->left){
            return this->root->right;
        }
        else if(!this->root->right){
            return this->root->left;
        }
        else{
            Node** replacement;
            root->left = getInorderPredecessor(root->left,replacement);
            (*replacement)->left = root->left;
            (*replacement)->right = root->right;
            this->update_height(*replacement);
            *replacement = this->balance(*replacement);
            this->update_height(*replacement);
            return *replacement;
        }
    }
    else if(n < root->data)this->root->left = this->removeUtil(this->root->left,n);
    else {this->root->right = this->removeUtil(this->root->right,n);}
    this->update_height(this->root);
    root = this->balance(this->root);
    this->update_height(this->root);
    return root;
}

// ---- public search API method
void AVLTree::remove(int n){
    root =  this->removeUtil(this->root,n);
}


//
//
/* ************************ 🔴 Remove Functionality END  🔴 ******************************* */
// 
// 