#include <iostream>
#include "./include/avl/avl.hpp"
using namespace std;


int main(){
    AVLTree obj;
    for(int i=0;i<10;i++)obj.insert(i);
    obj.print();
    cout<<endl;
    cout<<obj.size();

    // obj.remove(11);
    // obj.print();
    // cout<<endl;
    // cout<<obj.size();
    return 0;
}