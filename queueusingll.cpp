#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head = nullptr;
node* rear= nullptr;

void enqueue(int data){
    node* newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    if(head == nullptr && rear == nullptr){
        head = newnode;
        rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    node *temp = head;
    if(head == nullptr && rear == nullptr){
        cout<<"QUEUE IS EMPTY"<<endl;
    }
    else{
        cout<<"Popped element is:"<<temp->data<<endl;
        head = head->next;
        free(temp);
    }
}
void peek(){
    if(head == nullptr && rear == nullptr){
        cout<<"QUEUE IS EMPTY"<<endl;
    }
    else{
        cout<<"The front element of queue is:"<<head->data<<endl;
    }
}
void display(){
    node* temp = head;
    if(head == nullptr && rear == nullptr){
        cout<<"QUEUE IS EMPTY"<<endl;
    }
    else{
        while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;


    }
    
}
int main(){
    enqueue(5);
    enqueue(4);
    enqueue(-3);
    display();
    dequeue();
    display();
    peek();
    return 0;
}
