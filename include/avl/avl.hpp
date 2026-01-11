#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node();
    Node(int n);
    ~Node();
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
        Node* insertUtil(Node* ,int);
        Node* searchUtil(Node*, int);
        Node* removeUtil(Node*,int);
        Node* getInorderPredecessor(Node*,Node**);
        void printUtil(Node*);
        void inorderUtil(Node*,vector<int>&);
        void preorderUtil(Node*,vector<int>&);
        void postorderUtil(Node*,vector<int>&);
        void showTreeUtil(Node*);
    public:
        AVLTree();
        ~AVLTree();
        // --general methods
        int size();
        bool isEmpty();
        int tree_height();
        // -- standard functions
        void insert(int);
        void remove(int);
        bool search(int);
        // traversal
        vector<int> inorder();
        vector<int> preorder();
        vector<int> postorder();
        void showTree();

        // Utils for development and testing
        void print();
};