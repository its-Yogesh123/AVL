#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right; 
    Node(int n=0){
        data = n;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};
int height(Node* root){
    return root?root->height:0;
}
void balance_height(Node* root){
    if(!root)return;
    root->height = (height(root->left),height(root->right))+1;
}
bool is_left(Node* root){
    if(!root)return false;
    return height(root->left) > height(root->right);
}

Node* left_rotate(Node* root){
    Node* r_right= root->right;
    if(!root || !r_right)return root;
    root->right = r_right->left;
    r_right->left = root;
    balance_height(r_right->left);
    balance_height(r_right);
    return r_right;
}
Node* right_rotate(Node* root){
    Node* r_left = root->left;
    if(!root || !r_left)return root;
    root->left = r_left->right;
    r_left->right = root;
    balance_height(root);
    balance_height(r_left);
    return r_left;
}
Node* balance(Node* root){
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

Node* insert(Node* root,int n){
    if(!root)return new Node(n);
    if(n < root->data)root->left=  insert(root->left,n);
    else root->right =insert(root->right,n);
    root = balance(root);
    balance_height(root);
    return root;
};
void print(Node* root){
    if(!root)return;
    print(root->left);
    cout<<root->data<<" "<<root->height<<"\n";
    print(root->right);
}
int main(){
    Node* root=NULL;
    root= insert(root,0);
    root= insert(root,1);
    root= insert(root,2);
    // for(int i=0;i<10;i++){
    //     root = insert(root,i);
    // }
    print(root);
    return 0;
}
