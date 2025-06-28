#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
int main(){
    node *head = nullptr,*newnode,*temp;
    int choice = 1;
    while(choice){
        newnode = new node;
        cout<<"Enter data:"<<endl;
        cin>>newnode->data;
        newnode->next=nullptr;
        if(head==nullptr){
            head = temp= newnode;
        }
        else{
            temp->next=newnode;
            temp = newnode;
        }
        cout<<"Do you want to continue(0 or 1)"<<endl;
        cin>>choice;
    }
    temp = head;
    while(temp != nullptr){
        cout<<temp->data;
        temp = temp->next;
    }
    return 0;
}