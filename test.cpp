#include <iostream>
#include "./include/avl/avl.hpp"
using namespace std;


int main(){
    AVLTree obj;
    int a;
    int b;
    cout<<"1 value_to_insert\n";
    cout<<"2 value_to_delete\n";
    cout<<"3 value_to_search\n";
    cout<<"4 to print tree\n";
    cout<<"-1 for Exit\n";
    while(true){
        cin>>a>>b;
        if(a == 1){
            obj.insert(b);
        }
        else if(a == 2){
            obj.remove(b);
        }
        else if(a == 3){
            cout<<obj.search(b)<<endl;
        }
        else if(a == 4){
            cout<<"\n ----- Tree Begin ------\n";
            obj.print();
            cout<<"\n ----- Tree End ------"<<endl;
        }
        else if(a == 5){
            cout<<"\n ----- Inorder Begin ------\n";
            for(int i:obj.inorder())cout<<i<<" ";
            cout<<"\n ----- Inorder End ------"<<endl;
        }
        else break;
        cout<<"\n---------"<<endl;
    }
    return 0;
}
