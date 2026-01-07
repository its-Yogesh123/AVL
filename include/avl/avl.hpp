#pragma once
#include <iostream>

class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right;
};

class avl{
    int size;
    public:
    int size();
    void insert();
    void remove();
    void search();
    bool isEmpty();
};