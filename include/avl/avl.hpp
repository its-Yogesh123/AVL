#pragma once
#include <iostream>
#include <vector>

class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(){};
    Node(int n){};
    ~Node(){};
};

class AVLTree{
    private:
        int size_;
        Node* root;

        // methods
        int height(Node*);
        void update_height(Node*);
        bool is_left(Node*);
        Node* left_rotate(Node*);
        Node* right_rotate(Node*);
        Node* balance(Node*);
        Node* insertUtil(Node* ,int n);
        Node* searchUtil(Node*, int);
    public:
        AVLTree();
        ~AVLTree();
        // --general methods
        int size();
        bool isEmpty();
        int tree_height();
        // -- standard functions
        void insert(int n);
        void remove();
        bool search(Node*, int);
        // traversal
        vector<int> inorder();
        vector<int> preorder();
        vector<int> postorder();
        void showTree();
};