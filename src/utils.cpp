#include <iostream>
#include "avl/avl.hpp"
using namespace std;

/* ------------- Node -------------------------*/
Node::Node(){
    this->left=nullptr;
    this->right=nullptr;
    this->data =0;
    this->height =1;
}
Node::Node(int n){
    this->left=nullptr;
    this->right=nullptr;
    this->data =n;
    this->height =1;
}
Node::~Node(){}

/* ------------- AVLTree class -------------------------*/

AVLTree::AVLTree(){
    this->root =nullptr;
    this->size_=0;
}
AVLTree::~AVLTree(){}



/* ---------------------------  Functional utilities ------------------*/
int AVLTree::height(Node* root){
    return root?root->height:0;
}
void AVLTree::update_height(Node* root){
    if(!root)return;
    root->height = max(height(root->left),height(root->right))+1;
}
bool AVLTree::is_left(Node* root){
    if(!root)return false;
    return height(root->left) > height(root->right);
}

Node* AVLTree::left_rotate(Node* root){
    if(!root || !root->right)return root;
    Node* r_right= root->right;
    root->right = r_right->left;
    r_right->left = root;
    update_height(r_right->left);
    update_height(r_right);
    return r_right;
}
Node* AVLTree::right_rotate(Node* root){
    if(!root || !root->left)return root;
    Node* r_left = root->left;
    root->left = r_left->right;
    r_left->right = root;
    update_height(root);
    update_height(r_left);
    return r_left;
}
Node* AVLTree::balance(Node* root){
    int l_h = height(root->left);
    int r_h = height(root->right);
    if(abs(l_h - r_h) <=1)return root;
    if(l_h > r_h){
        if(is_left(root->left))root = right_rotate(root);
        else{
            root->left = left_rotate(root->left);
            root = right_rotate(root);
        }
    }
    else{
        if(!is_left(root->left))root =left_rotate(root);
        else{
            root->right = right_rotate(root->right);
            root =left_rotate(root);
        }
    }
    return root;
}